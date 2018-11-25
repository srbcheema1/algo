#include<bits/stdc++.h>
using namespace std;

#define dout if(debug and (debug_test == 0 or _t == debug_test) ) cerr<<" "
#define endl "\n"
#define int long long
#define substring(i,j) substr(i,(j-i+1)) // both i,j are included

#ifdef ONLINE_JUDGE
#define DEBUG 0.0
#else
#define DEBUG 1
#endif
int debug = DEBUG;// it will take care of itself on online-judge
int debug_test = 0; // test_case to be debugged ... 0 means all ... -1 means none
int _t = 0;// test_case counter

#define all(container) container.begin(),container.end()
#define umap unordered_map
#define pqueue priority_queue // kept them macro coz we need to use <> also
typedef unsigned long long ulli;// rarely will be used
typedef pair<int,int> mp;
typedef vector<int> vi;
typedef vector<vector<int> > matrix; // matrix matt(n,vector<int>(m,0));

template<class T>int sz(T &x){return (int)x.size();}
template<class T>void show(T first){dout<<first<<"\n";}
template<class T>bool sort_fun(T a,T b){return a>b;} // for descending sort // templated
template<class T,class U>bool found(T t,U u){if(t.find(u)==t.end())return false;return true;}

// helping templates ignore them
template<class T,class... Args>void show(T first,Args... args){dout<<first;show(args...);}
template<class T>void _p(T x){int i=0;for(auto a: x){dout<<a<<",";if(i++ > 20)break;}}
template<class T,class U>ostream &operator<<(ostream &o,pair<T,U> &x){return o<<"("<<x.first<<","<<x.second<<")";}
template<class T>ostream &operator<<(ostream &os,vector<T> &x){dout<<"[";_p(x);dout<<"] ";return os;}
template<class T>ostream &operator<<(ostream &os,set<T> &x){dout<<"{";_p(x);dout<< "} ";return os;}

const int mod = 1e9+7, inf = LLONG_MAX, none = inf/2-9;
struct Desc{bool operator()(int a,int b){return a>b;}}desc; // for descending sort

// code begins here
struct Query {
    int l,r,i,ans;
    string x;
    Query(int _l,int _r, int _i, string _x) {
        l = _l; r = _r; i = _i; x = _x;
        ans = -1;
    }
    //bool operator<(const Query& o)const{return l < o.l;}// sort in ascending order
};

struct Node {
    Node* l;// for 0
    Node* r;// for 1
    Node* j;// for jump
    int height,lm;// lm = l_min
    set<int> lavail,ravail,avail;
    bool end;
    Node() {
        l = r = j = NULL;
        end = true;
        lm = mod;
    }
};

const int NN = 1e6+9;// 1e6+9
const int  N = 1e5+9;// 1e5+9
Node * arr[NN];
int len_str[N];
int segtree[4*N];
vector<string> str(N);

void build_tree(int l,int r,int i) {
    if(l==r) {
        segtree[i] = len_str[l];
        return;
    }
    int mid = (l+r)/2;
    build_tree(l,mid,2*i);
    build_tree(mid+1,r,2*i+1);
    segtree[i] = max(segtree[2*i],segtree[2*i+1]);
}

int query(int l,int r,int st,int ed,int i) {
    if(l==st and r==ed) return segtree[i];

    int mid = (st+ed)/2;
    if(r<=mid) return query(l,r,st,mid,2*i);
    if(l>mid) return query(l,r,mid+1,ed,2*i+1);

    return max(query(l,mid,st,mid,2*i),query(mid+1,r,mid+1,ed,2*i+1));
}

void build_trie(Node *root,string & str,int i,int len,int ind,int height) {
    root->height = height;
    if(i==len-1) {
        root->avail.insert(ind);
        return;
    }
    root->end = false;

    if(str[i+1]=='0') {
        if(root->l == NULL) root->l = new Node();
        root->lavail.insert(ind);
        build_trie(root->l,str,i+1,len,ind,height-1);
    } else {
        if(root->r == NULL) root->r = new Node();
        root->ravail.insert(ind);
        build_trie(root->r,str,i+1,len,ind,height-1);
    }
    root->avail.insert(ind);
}

int query_trie(Node * root,string x,int i,int lead,int l,int r) {// max of lead + i
    if(root->end) return *(root->avail.lower_bound(l));
    if(root->avail.size() == 1) return *(root->avail.begin());
    if(root->j) {
        int now_height = root->height;
        int next_height = root->j->height;
        int diff = now_height - next_height;
        if(lead) {
            if(diff >= lead) {
                diff -= lead;
                i += diff;
                lead = 0;
            } else lead -= diff;
        } else i+= diff;
        if(root->j != NULL) show(root->j->height);
        return query_trie(root->j,x,i,lead,l,r);
    }

    bool lgood = true,rgood = true;
    if(root->lavail.lower_bound(l) == root->lavail.upper_bound(r)) lgood = false;
    if(root->ravail.lower_bound(l) == root->ravail.upper_bound(r)) rgood = false;

    if(lead) {
        if(rgood) return query_trie(root->r,x,i,lead-1,l,r);
        else return query_trie(root->l,x,i,lead-1,l,r);
    }

    if(x[i] =='0') {
        if(rgood) return query_trie(root->r,x,i+1,0,l,r);
        else return query_trie(root->l,x,i+1,0,l,r);
    }
    else {
        if(lgood) return query_trie(root->l,x,i+1,0,l,r);
        else return query_trie(root->r,x,i+1,0,l,r);
    }
}// end query

void add_to_trie(string & str,int len,int ind) {
    Node* root = arr[len];
    build_trie(root,str,0,len,ind,len);
}

Node * contract(Node * root,bool jump = false) {
    if(root->end) return root;

    if(jump) { // came for jump
        if(root->l == NULL) return contract(root->r,true);
        if(root->r == NULL) return contract(root->l,true);
        if(root->r != NULL and root->l != NULL) return root;
    } else {
        if(root->l == NULL) {
            root->j = contract(root->r,true);
            return contract(root->j);
        }
        else if(root->r == NULL) {
            root->j = contract(root->l,true);
            return contract(root->j);
        }
        else {
            contract(root->l);
            contract(root->r);
        }
        return NULL;
    }// simple call
}

void solve(){
    for(int i=0;i<NN;i++) arr[i] = new Node();
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++) {
        string temp;
        cin>>temp;
        int len = sz(temp);
        str[i] =temp;
        len_str[i] = len;
    }
    for(int i=0;i<NN;i++) contract(arr[i]);
    build_tree(0,n,1);

    vector<Query> queries;
    for(int i=0;i<q;i++) {
        int l,r;
        string x;
        cin>>l>>r>>x;
        queries.push_back({l-1,r-1,i,x});
    }
    sort(all(queries),[](Query &a,Query &b) { return a.l > b.l; });// sort with descending l

    int li = n-1;// last index to be inserted in trie
    for(int i=0;i<q;i++) {
        int &l = queries[i].l;
        int &r = queries[i].r;
        string &x = queries[i].x;

        for(;li>=l;li--)
            add_to_trie(str[li],sz(str[li]),li);

        int lenx = sz(x);
        int avail_len = query(l,r,0,n,1);// not a big deal
        int ans = 0;

        if(avail_len>lenx) {
            int lead = avail_len - lenx;
            show("availlen and lead",avail_len,lead);
            ans = query_trie(arr[avail_len],x,0,lead-1,l,r);
        } else {
            bool got = false;
            for(int i=0;i<lenx;i++) {
                if(x[i] == '0') {
                    int j = lenx - i;
                    show(j,arr[j]->avail);
                    if(arr[j]->avail.lower_bound(l) != arr[j]->avail.upper_bound(r) ) {// make it good
                        ans = query_trie(arr[j],x,i+1,0,l,r);
                        got = true;
                        break;
                    }
                }
            }
            if(not got) {
                for(int i=lenx-1;i>=0;i--) {
                    int j = lenx - i;
                    if(arr[j]->avail.lower_bound(l) != arr[j]->avail.upper_bound(r) ) {// make it good
                        ans = query_trie(arr[j],x,i+1,0,l,r);
                        got = true;
                        break;
                    }
                }
            }
        }
        queries[i].ans = ans+1;
    }// all querries processed

    // output
    sort(all(queries),[](Query &a,Query &b) { return a.i < b.i; });// sort with ascending i
    for(auto a: queries) cout << a.ans << endl;
}

signed main() {
    #ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(0);cin.tie(0);
    #else
    //freopen("Input.txt","r",stdin);
    #endif
    std::cout << std::fixed; std::cout.precision(7);
    int test=1;
    //cin>>test;
    for(int t = 1; t <= test; t++)_t = t,solve();
}
