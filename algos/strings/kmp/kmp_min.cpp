#include<bits/stdc++.h>
#define dout if(debug and (debug_test == 0 or _t == debug_test) ) cout<<" "
#define endl "\n"
using namespace std;

#ifdef ONLINE_JUDGE
#define DEBUG 0.0
#else
#define DEBUG 1
#endif
int debug = DEBUG;// it will take care of itself on online-judge
int debug_test = 0; // test_case to be debugged ... 0 means all ... -1 means none
int _t = 0;

#define umap unordered_map
#define pqueue priority_queue
typedef unsigned long long int ulli;
typedef unsigned int ui;
typedef pair<int,int> mp;
typedef vector<vector<int> > matrix; // matrix matt(n,vector<int>(m,0));

const int mod = 1e9+7;

template<class T>int sz(T &x){return (int)x.size();}
template<class T>void show(T first){dout<<first<<"\n";}
template<class T,class... Args>void show(T first,Args... args){dout<<first;show(args...);}
template<class T,class U>ostream &operator<<(ostream &os,pair<T,U> &x){return os<<x.first<<","<<x.second;}
template<class T>void print(T first,T last){for(auto it = first;it != last;it++)dout<<*it;dout<<endl;}
template<class T>void print(T container){print(container.begin(),container.end());}; // print(vec);
template<class T>bool sort_fun(T a,T b){return a>b;} // for descending sort // templated
struct Desc{bool operator()(int a,int b){return a>b;}}desc; // for descending sort
// manual.begin

set<int> kmp(string s,string p) {
    // compute lps
    p+="#";// any character that wont come in string
    vector<int> lps(p.size(),0);
    for(int i=1,j=0;i<(int)p.size();i++) {
        while(j>0 and p[i] != p[j]) j = lps[j-1];
        if(j==0 and p[i] != p[j]) lps[i] = j++; // j is 1 and lps[i] is 0
        else lps[i] = ++j;
    }

    // compute matches
    set<int> matches;
    for (int i=0,j=0;i<(int)s.size();i++) {
        while (j>0 and s[i] != p[j]) j = lps[j-1];
        if (j!=(int)p.size() and s[i] == p[j]) j++;
        if (j==(int)p.size()-1) matches.insert(i-j+1);
    }
    return matches;
}


signed main(){
    string s,p;
    auto ans = kmp(s,p);
    if(ans.size()) cout << "match found" << endl;
    else cout << "no match found" << endl;

}
//manual.end

/* TAGS
 * kmp
 */
