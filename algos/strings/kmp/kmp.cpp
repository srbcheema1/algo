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
    int j = 0;
    for(int i=1;i<(int)p.size();i++) {
        while(j>0 and p[i] != p[j]) j = lps[j-1];
        if(j==0 and p[i] != p[j]) lps[i] = j++; // j is 1 and lps[i] is 0
        else lps[i] = ++j;
    }

    // compute matches
    set<int> matches;
    j = 0;
    for (int i=0;i<(int)s.size();i++) {
        while (j>0 and s[i] != p[j]) j = lps[j-1];
        if (j!=(int)p.size() and s[i] == p[j]) j++;
        if (j==(int)p.size()-1) matches.insert(i-j+1);
    }
    return matches;
}

/*
 * lps contains:-
 * it is length of longest proper suffix which is also prefix
 * suppose S = kababcabcabd
 * suppose P = abcabd
 * the 2nd b in P will point to 'c' saying that once try out comparision of ith val with c.
 * i mean we have to compare with vec[pointer_in_p - 1].
 * it provides next best location to compare with
 */
vector<int> make_lps(string s) {
    vector<int> lps(s.size(),0);
    int j = 0;
    for(int i=1;i<(int)s.size();i++) {
        while(j>0 and s[i] != s[j]) j = lps[j-1];
        if(j==0 and s[i] != s[j]) lps[i] = j++; // j is 1 and lps[i] is 0
        else lps[i] = ++j;
    }
    return lps;
}

vector<int> kmp(string s,string p,vector<int> lps) {
    vector<int> matches;
    int j = 0;
    p+="#";// any character that wont come in string
    lps.push_back(*lps.rbegin());// lps of last element
    for (int i=0;i<(int)s.size();i++) {
        while (j>0 and s[i] != p[j]) j = lps[j-1];
        if (j!=(int)p.size() and s[i] == p[j]) j++;
        if (j==(int)p.size()-1) matches.push_back(i-j+1);
    }
    return matches;
}

signed main() {
    int t=1;
    cin>>t;
    while(t--) {
        string s,p;
        cin>>s>>p;
        auto lps = make_lps(p);
        auto ans = kmp(s,p,lps);
        if(ans.size()) {
            cout << ans.size() << endl;
            for(int i=0;i<(int)ans.size();i++) {
                cout << ans[i] +1 << " ";
            }
            cout << endl;
        } else {
            cout << "Not Found" << endl;
        }
    }
}
//manual.end

/* TAGS
 * kmp
 * https://www.spoj.com/problems/NAJPF/
 */
