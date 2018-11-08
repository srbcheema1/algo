#include<bits/stdc++.h>

#define derr(debug_input) cerr<<"\tLINE "<<__LINE__<<": "<<#debug_input<<" -> "<<debug_input<<"\n"
#define endl "\n"
// correect for small cases
// wrong for large

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> mp;
typedef vector<vector<int>> matrix;

template<class T>
bool scomp(const T &a,const T &b){
    return a<b;
}

bool sort_fun(const mp &a,const mp &b){
    return abs(a.first) > abs(b.first);
}
const ll mod=1e9+7;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define dout if(t == dt) cout << ""
int dt = -2; // debug test case

int calc(vector<int> &c0, vector<int> &c1,int p, string &str, int t){
    int comp = 0;
    for(int i=0;i<p;i++){
        if(str[i] == '1'){
            comp += c0[i];
            dout << "1 there " << c0[i] << endl;
        } else {
            comp += c1[i];
            dout << "0 there " << c1[i] << endl;
        }
    }
    return comp;
}

string get_str(int k,int p){
    string str="";
    while(k){
        if(k&1)str = "1" + str;
        else str = "0"+str;
        k >>=1;
    }

    while((int)str.length()<p){
        str = '0' + str;
    }
    return str;
}

string merge_str(string &a, string &b, int t){
    string ret = b;
    for(int i=0;i<(int)b.length();i++){
        if(a[i]=='1')
            ret[i] = b[i]=='1'?'0':'1';
    }
    dout << a << " ^ " << b << " = " << ret << endl;
    return ret;
}

void run_for_test(int t=-1){
    int n,m,p;
    cin>>n>>m>>p;
    dout << n << " " << m << " " << p << endl;
    map<string,int> vec;
    set<string> unavail;
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        dout << str << endl;
        vec[str]++;
    }
    for(int i=0;i<m;i++){
        string str;
        cin>>str;
        dout << str << endl;
        unavail.insert(str);
    }

    vector<int> one(p);
    vector<int> c0(p);
    vector<int> c1(p);
    for(auto a: vec){
        string s = a.first;
        int count = a.second;
        for(int i=0;i<p;i++){
            char c = s[i];
            if(c=='1'){
                one[i]+=count;
                c1[i]+=count;
            } else {
                one[i]-=count;
                c0[i]+=count;
            }
        }
    }
    string ans(p,' ');
    vector<mp> arr;
    for(int i=0;i<p;i++){
        arr.push_back(mp(one[i],i));
    }
    sort(arr.begin(),arr.end(),sort_fun);
    for(int i=0;i<p;i++){
        if(arr[i].first < 0){
            ans[arr[i].second] = '0';
        } else {
            ans[arr[i].second] = '1';
        }
    }

    dout << " best ans should be : " << ans << endl;
    // best ans is made

    string best_ans = ans;
    map<string,int> good;
    for(int k=0;k<pow(2,min(p,14));k++) {
        string mark = get_str(k,p);
        ans = merge_str(mark,best_ans,t);
        if(unavail.find(ans) == unavail.end()) {
            good[ans] = calc(c0,c1,p,ans,t);
        }
    }

    int minn = INT_MAX;
    for(auto a: good){
        if(minn > a.second){
            ans = a.first;
        }
        minn = min(minn,a.second);
    }

    //cout << ans << endl;
    cout << minn << endl;
}


int main(){
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int _t=1;
    cin>>_t;
    int T=_t;
    //derr("hello world "<<_t);
    while(_t--){
        cout<<"Case #"<<T-_t<<": ";
        run_for_test(T-_t);
    }
    return 0;
}
