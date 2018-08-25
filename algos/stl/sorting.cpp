#include<bits/stdc++.h>
using namespace std;

// manual.begin
struct Desc{ bool operator() (int a, int b) { return a > b; } }desc; // for descending sort

struct Std{
    int roll; string name;
    Std(int roll, string name) : roll(roll) , name(name) {}
    bool operator<(Std other){return roll > other.roll;}// for descending // may change sign accordingly
    friend istream& operator>>(istream& inn,Std& me){inn>>me.roll>>me.name;return inn;}
    friend ostream& operator<<(ostream& out,Std& me){out<<"roll "<<me.roll;return out;}
};

signed main(){
    vector<int> vec({1,5,4});
    sort(vec.begin(),vec.end());
    for(auto a: vec)
        cout << a << " ";
    cout << endl;

    sort(vec.begin(),vec.end(),desc);
    for(auto a: vec)
        cout << a << " ";
    cout << endl;

    vector<Std> std({{35,"srb"},{2,"sahoo"},{11,"vishi"},{6,"nimi"}});
    sort(std.begin(),std.end());
    for(auto a: std)
        cout << a << endl;
}
// manual.end

/* TAGS
 *
 */
