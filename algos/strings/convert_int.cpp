#include<bits/stdc++.h>
using namespace std;

// manual.begin
signed main(){
    // int to string
    int i = 9; string s; stringstream ss;
    ss << i;
    ss >> s;
    cout << s << endl;

    // using to_string
    i = 10;
    s = to_string(i);
    cout << s << endl;

    // string to int
    s = "11";
    i = stoi(s);
    cout << i << endl;

    // string to int
    s = "12"; i = 13;
    stringstream sss(s);
    sss >> i;
    cout << i << endl;
}
//manual.end

/* TAGS
 * int_to_string
 * to_string
 * stringstream
 * stoi
 */
