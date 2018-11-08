#include<bits/stdc++.h>

#define derr(debug_input) cerr<<"\tLINE "<<__LINE__<<": "<<#debug_input<<" -> "<<debug_input<<"\n"
#define endl "\n"

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> mp;
typedef vector<vector<int>> matrix;

template<class T>
bool scomp(const T &a,const T &b){
    return a<b;
}

const ll mod=1e9+7;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

void run_for_test(){
    int n;
    cin>>n;
    n = n*3;
    vector<int> bahoo(n);
    vector<int> balla(n);
    for(int i=0;i<n;i++)
        cin>>bahoo[i];
    for(int i=0;i<n;i++)
        cin>>balla[i];

    sort(bahoo.begin(),bahoo.end());
    vector<int> good;
    for(int i=3;i<n;i++)
        good.push_back(bahoo[i]);

    int c_box = 0;
    for(int i=0;i<3;i++)
        c_box += good[i];
    map<vector<int>,int > bahoo_set;
    do {
        int a_box = 0;
        int b_box = 0;
        for(int i=0;i<3;i++)
            a_box += good[i];
        for(int i=3;i<6;i++)
            b_box += good[i];
        vector<int> hell({a_box,b_box,c_box});
        sort(hell.begin(),hell.end());

        bahoo_set[hell]++;
    } while(std::next_permutation(good.begin(), good.end()));

    map<vector<int>,int > balla_set;
    do {
        int a_box = 0;
        int b_box = 0;
        int c_box = 0;
        for(int i=0;i<3;i++)
            a_box += balla[i];
        for(int i=3;i<6;i++)
            b_box += balla[i];
        for(int i=6;i<9;i++)
            b_box += balla[i];
        vector<int> hell({a_box,b_box,c_box});
        sort(hell.begin(),hell.end());

        balla_set[hell]++;
    } while(std::next_permutation(balla.begin(), balla.end()));

    int bahoo_pts = 0, balla_pts = 0;
    for(auto a: bahoo_set){
        for(auto b: balla_set){
            do{
                if(
                    (b.first[2] < a.first[2] and b.first[1] < a.first[1]) or
                    (b.first[2] < a.first[2] and b.first[0] < a.first[0]) or
                    (b.first[1] < a.first[1] and b.first[0] < a.first[0]) or
                  0 )
                    bahoo_pts += a.second * b.second;
                else
                    balla_pts += a.second + b.second;
            } while(std::next_permutation(b.first.begin(), b.first.end()));
        }
    }
    cout << setprecision(6) << (bahoo_pts*1.0 /(balla_pts + bahoo_pts)) << endl;
}



int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int _t=1;
    cin>>_t;
    int T=_t;
    //derr("hello world "<<_t);
    while(_t--){
        cout<<"Case #"<<T-_t<<": ";
        run_for_test();
    }
    return 0;
}
