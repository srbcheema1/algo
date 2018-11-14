#include<bits/stdc++.h>
using namespace std;

template<class T>int sz(T &x){return (int)x.size();}
const int mod = 1e9+9;

// code begins here
struct Node {
    Node* l;// for 0
    Node* r;// for 1
    int contain,lm;// lm = l_min
    bool end;
    Node() {
        l = r = NULL;
        end = true;
        lm = mod;
        contain = 0;
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

int query(int l,int r,int st,int ed,int i) {// get max height in range
    if(l==st and r==ed) return segtree[i];

    int mid = (st+ed)/2;
    if(r<=mid) return query(l,r,st,mid,2*i);
    if(l>mid) return query(l,r,mid+1,ed,2*i+1);

    return max(query(l,mid,st,mid,2*i),query(mid+1,r,mid+1,ed,2*i+1));
}

void build_trie(Node *root,string & str,int i,int len,int ind) {
    root->lm = min(ind,root->lm);
    root->contain++;
    if(i==len-1)return;
    root->end = false;

    if(str[i+1]=='0') {
        if(root->l == NULL) root->l = new Node();
        build_trie(root->l,str,i+1,len,ind);
    } else {
        if(root->r == NULL) root->r = new Node();
        build_trie(root->r,str,i+1,len,ind);
    }
}

int query_trie(Node * root,string x,int i,int lead,int l,int r) {// max of lead + i
    // here i means which elem will take decision of next turn
    if(root->end) return root->lm;
    if(root->contain == 1) return root->lm;

    bool lgood = true,rgood = true;
    if(!root->r) rgood = false;
    else if(root->r->lm > r) rgood = false;

    if(!root->l) lgood = false;
    else if(root->l->lm > r) lgood = false;

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
    build_trie(root,str,0,len,ind);
}

struct Query {
    int l,r,i,ans;
    string x;
    Query(int _l,int _r, int _i, string _x) {
        l = _l; r = _r; i = _i; x = _x;
        ans = mod;
    }
};

void solve(){
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++) {
        string temp;
        cin>>temp;
        int len = sz(temp);
        str[i] =temp;
        len_str[i] = len;
    }
    build_tree(0,n,1);

    vector<Query> queries;
    for(int i=0;i<q;i++) {
        int l,r;
        string x;
        cin>>l>>r>>x;
        queries.push_back({l-1,r-1,i,x});
    }
    sort(queries.begin(),queries.end(),[](Query &a,Query &b) { return a.l > b.l; });// sort with descending l

    int li = n-1;// last index to be inserted in trie
    for(int i=0;i<q;i++) {
        int &l = queries[i].l;
        int &r = queries[i].r;
        int &ans = queries[i].ans;
        string &x = queries[i].x;

        for(;li>=l;li--) add_to_trie(str[li],sz(str[li]),li);// build_trie

        int avail_len = query(l,r,0,n,1);// not a big deal
        if(avail_len>sz(x)) {
            int lead = avail_len - sz(x);
            ans = query_trie(arr[avail_len],x,0,lead-1,l,r) + 1;
            continue;
        }
        for(int i=0;i<sz(x);i++) if(x[i] == '0') {
            int j = sz(x) - i;
            if(arr[j]->lm <= r) {
                ans = query_trie(arr[j],x,i+1,0,l,r)+1;
                break;
            }
        }
        if(ans != mod) continue;
        for(int i=sz(x)-1;i>=0;i--) {
            int j = sz(x) - i;
            if(arr[j]->lm <= r) {
                ans = query_trie(arr[j],x,i+1,0,l,r) + 1;
                break;
            }
        }
    }// all querries processed

    sort(queries.begin(),queries.end(),[](Query &a,Query &b) { return a.i < b.i; });// sort with ascending i
    for(auto a: queries) cout << a.ans << endl;
}

int main() {
    int test=1;
    for(int i=0;i<NN;i++) arr[i] = new Node();
    while(test--)solve();
}

//https://www.codechef.com/NOV18B/problems/BINSTR
