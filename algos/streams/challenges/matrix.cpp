#include<bits/stdc++.h>
using namespace std;

// manual.begin
signed main(){
    int a, way = 3, maxx = INT_MIN, minn = INT_MAX;
    char ch;
    if(way == 1)
    while(cin>>a) {
        maxx = INT_MIN;
        do {
            maxx = max(a,maxx);
            ch = cin.peek();
            while(ch == ' ' || ch == '\t') cin.get(),ch = cin.peek();
            if(ch=='\n') break;
        } while(cin>>a);
        minn = min(minn,maxx);
    }
    if(way == 2)
    while(cin>>a) {
        maxx = INT_MIN;
        do {
            maxx = max(a,maxx);
            while(cin.get(ch))
                if(!(ch==' ' || ch=='\t')) break;
            if(ch=='\n') break;
            cin.unget();
        } while(cin>>a);
        minn = min(minn,maxx);
    }
    if(way == 3)
    while(cin){ // will take one extra turn.
        maxx = INT_MIN;
        while(cin >> a) {
            maxx = max(a,maxx);
            while(cin.get(ch))
                if(!(ch==' ' || ch=='\t')) break;
            if(ch=='\n') break;
            cin.unget();
        }
        if (maxx != INT_MIN) minn = min(minn,maxx); // condition for extra turn
    }
    cout << minn << endl;
}
//manual.end

/* TAGS
 * reading files till eof
 * unget
 * peek
 * get
 * EOF
 */
