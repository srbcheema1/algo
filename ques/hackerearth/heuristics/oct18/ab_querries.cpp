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
int temp = -1,last = -1,hell=-1;
struct Desc{bool operator()(int a,int b){return a>b;}}desc; // for descending sort

// code begins here

const int N = 1e5+9;
vector<int> mod_tree(4*N);
vector<int> sum_tree(4*N);
int arr[N];

void make_mod_tree(int l,int r, int i){
    if(l == r) {
        mod_tree[i] = l;
        return;
    }

    int mid = (l+r)/2;
    make_mod_tree(l,mid,2*i);
    make_mod_tree(mid+1,r,2*i+1);

    mod_tree[i] = (arr[mod_tree[2*i]] > arr[mod_tree[2*i+1]]) ? mod_tree[2*i] : mod_tree[2*i+1];
}
int mode_q(int l,int r,int st,int ed,int i) {
    if(l==st and r==ed) {
        return mod_tree[i];
    }

    int mid = (st+ed)/2;
    if(r<=mid) return mode_q(l,r,st,mid,2*i);
    if(l>mid) return mode_q(l,r,mid+1,ed,2*i+1);

    int left = mode_q(l,mid,st,mid,2*i);
    int right = mode_q(mid+1,r,mid+1,ed,2*i+1);
    return (arr[left] > arr[right]) ? left : right;
}
void mode_u(int st,int ed,int i,int w) {
    if(st==w and ed==w) {
        return;
    }

    int mid = (st+ed)/2;
    if(w<=mid) mode_u(st,mid,2*i,w);
    if(w>mid) mode_u(mid+1,ed,2*i+1,w);

    mod_tree[i] = (arr[mod_tree[2*i]] > arr[mod_tree[2*i+1]]) ? mod_tree[2*i] : mod_tree[2*i+1];
}




void make_sum_tree(int l,int r, int i){
    if(l == r) {
        sum_tree[i] = arr[l];
        return;
    }

    int mid = (l+r)/2;
    make_sum_tree(l,mid,2*i);
    make_sum_tree(mid+1,r,2*i+1);

    sum_tree[i] = sum_tree[2*i] + sum_tree[2*i+1];
}
int sum_q(int l,int r,int st,int ed,int i) {
    if(l==st and r==ed) {
        return sum_tree[i];
    }

    int mid = (st+ed)/2;
    if(r<=mid) return sum_q(l,r,st,mid,2*i);
    if(l>mid) return sum_q(l,r,mid+1,ed,2*i+1);

    int left = sum_q(l,mid,st,mid,2*i);
    int right = sum_q(mid+1,r,mid+1,ed,2*i+1);
    return left + right;
}
void sum_u(int st,int ed,int i,int w) {
    if(st==w and ed==w) {
        return;
    }

    int mid = (st+ed)/2;
    if(w<=mid) sum_u(st,mid,2*i,w);
    if(w>mid) sum_u(mid+1,ed,2*i+1,w);

    sum_tree[i] = sum_tree[2*i] + sum_tree[2*i+1];
}

int gcd(int a,int b) {
    if(b==1) return a;
    return gcd(b,a%b);
}

void solve(){
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) {
        cin>>arr[i];
    }
    make_mod_tree(1,n,1);
    make_sum_tree(1,n,1);

    int t,a,b;
    while(q--) {
        cin>>t>>a>>b;
        if(t==2) {
            arr[a] = b;
            mode_u(1,n,1,a);
            sum_u(1,n,1,a);
        } else {
            int mode = mode_q(a,b,1,n,1);
            int sum_lr = sum_q(a,b,1,n,1);
            if(a==1) sum_lr = sum_lr/2;
            else sum_lr = sum_q(1,a-1,1,n,1) + sum_lr/2;

            int low = a, high = b;
            int good = high,mid = 0;
            while(low < high) {
                mid = (low+high)/2;
                show(mid);
                int hell = sum_q(1,mid,1,n,1);
                show("binary",low,high,mid,hell,sum_lr);
                if(hell == sum_lr) {
                    good = mid; break;
                }
                if(hell > sum_lr) {
                    good = mid;
                    high = mid-1;
                }
                if(hell < sum_lr) {
                    low = mid+1;
                }
            }
            show(mode,good," sum_lr",sum_lr);
            int ans = mode*good / __gcd(mode,good);
            cout << ans << endl;
        }
    }
}

void preprocess(){

}

signed main(){
    #ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(0);cin.tie(0);
    #else
    //freopen("input.txt","r",stdin);
    #endif
    std::cout << std::fixed; std::cout.precision(7);
    preprocess();
    int test=1;
    cin>>test;
    for(int t = 1; t <= test; t++)_t = t,solve();
}
// a code by srbcheema1
