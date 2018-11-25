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
const int range = 60009;// will calculate prime numbers till this
vector<int> big_div(range+9); // biggest divisor of i, for primes big_div[i] == i
vector<int> primes; // will contain all the prime numbers
vector<int> sieve() {
    for(int i=0;i<=range;i++) big_div[i] = i;
    for(int i=2;i<range;i++)
        if(big_div[i] == i)
            for(int j=2*i;j<range;j+=i)
                big_div[j]=i;
    for(int i=2;i<range;i++)
        if(big_div[i]==i)
            primes.push_back(i);
    show("prime numbers till",range,":",primes.size());//3432
    show("last prime is",*primes.rbegin());//31991
    return primes;
}

bool is_prime(int n){
    if(n==1)return false;
    if(n < range) return big_div[n] == n;
    for(int i=0;i<(int)primes.size() and primes[i]<=sqrt(n);i++)
        if(n%primes[i]==0)return false;
    for(int i = *primes.rbegin();i <= sqrt(n);i++)// still if number if bigger than largest prime
        if(n%i==0)return false;
    return true;
}

int sum = 0;
struct Num{
    int loc,val,nl; // node loc // -1 means single "totally single like me" xD
    bool prime;
    Num(int _v,int _l) {
        val = _v; loc = _l; prime = false;
        nl = -1;
        if(is_prime(val) or is_prime(sum-val)) prime = true;
    }
};

vector<Num> vec;
struct Node {
    vi sett;
    vi childs;
    int head,hv,baap,size;
    int index;// will be indexed only after all are made
    Node(vi _sett,int _head) {
        head = _head;
        int local_sum = 0;
        for(auto a: _sett) local_sum += vec[a].val;
        int other_sum = sum - local_sum;
        for(auto a: _sett)
            if(is_prime(other_sum + vec[a].val)) {
                head = a;
                break;
            }
        for(auto a: _sett) {
            if(head == a)continue;
            sett.push_back(a);
        }
        sett.push_back(head);
        hv = 0;
        for(auto a: sett) hv+= vec[a].val;
        baap = -1;
        size = sett.size();
    }
    Node(int a) {
        sett.push_back(a);
        head = a;
        hv = vec[a].val;
        baap = -1;
        size = 1;
    }
    void insert(int a) {
        head = a;
        hv+=vec[a].val;
        sett.push_back(a);
        baap = -1;
        size++;
    }
};

void refurbrish(vi & num,vector<Node> & nodes) {
    vi temp_num;
    for(int i=0;i<sz(num);i++)
        if(vec[num[i]].nl == -1)
            temp_num.push_back(num[i]);
    num.assign(all(temp_num));
    sort(all(num),[](int &a, int &b) { return vec[a].val < vec[b].val; });
    sort(all(nodes),[](Node &a, Node &b) { return a.hv < b.hv; });// smallest in the begining
}

void print_output(vector<Node> & nodes,int joiner) {
    for(auto node: nodes) {
        std::reverse(all(node.sett));
        if(node.baap!=-1)// there exists a baap
            cout << node.baap << " " << node.sett[0] << endl;
        else
            cout << joiner << " " << node.sett[0] << endl;
        for(int i=1;i<sz(node.sett);i++) {
            cout << node.sett[i-1] << " " << node.sett[i] << endl;
        }
    }

}

int n;
int solve(vi & num, vector<Node> & nodes) {
    nodes.clear();num.clear();
    int joiner = mod;

    for(int i=1;i<=n;i++) { // P
        if(vec[i].prime) {
            nodes.push_back({i});
            vec[i].nl = sz(nodes) - 1;
            show("is prime",i,vec[i].val);
        }
        else num.push_back(i);// only contain location of simple numbers
    }
    refurbrish(num,nodes);

    int node_start = 0;
    if(sz(num)) {
        joiner = *num.rbegin();
        num.pop_back();
    }

    for(int max_size =1;max_size<200;max_size++) {// tree creater
        for(int i=0;i<sz(num);i++) { // N P
            for(int j=node_start;j<sz(nodes);j++) {
                if((int)nodes[j].size > max_size or nodes[j].baap > -1) continue;
                Num temp(vec[num[i]].val + nodes[j].hv,-1);
                if(temp.prime) {
                    nodes[j].insert(num[i]);
                    vec[num[i]].nl = j;
                    break;
                }
            }
        }
        refurbrish(num,nodes);

        if(max_size < 20)
        for(int k=0;k<sz(num);k++) { // N P P
            for(int i=node_start;i<sz(nodes);i++) {
                if((int)nodes[i].size > max_size or nodes[i].baap > -1) continue;
                for(int j=i+1;j<sz(nodes);j++) {
                    if((int)nodes[j].size > max_size or nodes[j].baap > -1) continue;
                    Num temp(vec[num[k]].val + nodes[i].hv + nodes[j].hv,-1);
                    if(temp.prime) {
                        nodes.push_back({num[k]});
                        vec[num[k]].nl = sz(nodes) -1;
                        nodes[i].baap = num[k];
                        nodes[j].baap = num[k];
                        nodes.rbegin()->hv += nodes[i].hv;
                        nodes.rbegin()->hv += nodes[j].hv;
                        nodes.rbegin()->size += max(nodes[j].size,nodes[i].size);
                        break;
                    }
                }
                if(vec[num[k]].nl > -1) break;
            }
        } // got subtrees with non-prime as root and two prime subtrees as childs
        refurbrish(num,nodes);
        if(!sz(num)) break;
    }

    if(joiner == mod){// rare chance of it // have no joiner
        Node temp = *nodes.begin();
        nodes.begin()->baap = mod;
        joiner = temp.head;
        for(auto a: temp.sett) {
            if(a==joiner) continue;
            nodes.push_back({a});
            nodes.rbegin()->baap = joiner;// newly node has baap as joiner
        }
    }// rare chance of this to happen

    if(sz(num)) {// wont execute// rare chance of it
        for(auto a: num) {
            nodes.push_back({a});
            nodes.rbegin()->baap = joiner;
        }
    }

    for(int i=0;i<sz(nodes);i++) nodes[i].index = i;

    for(auto & a:nodes) {
        if(a.baap == mod) continue;
        if(a.baap == -1) a.baap = joiner;
    }

    return joiner;
}

void process() {
    sieve();
    cin>>n;
    vi arr(n+1);
    for(int i=1;i<=n;i++) {
        cin>>arr[i];
        sum+=arr[i];
    }
    vec.push_back({2,0});//use less
    for(int i=1;i<=n;i++) vec.push_back({arr[i],i});
    vector<Node> nodes;
    vi num;
    int joiner = solve(num,nodes);
    print_output(nodes,joiner);
}

signed main() {
    #ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(0);cin.tie(0);
    #else
    freopen("Input.txt","r",stdin);
    #endif
    process();
}
