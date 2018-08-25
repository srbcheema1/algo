#include<bits/stdc++.h>
using namespace std;

// manual.begin

/* You will be given t input lines each input line will contain an integer
 * you will have to tell the maximum of all those numbers.
 * Special thing is that you are not told the number of input lines in it.
 */
signed main(){
    int a, ans = INT_MIN, way = 2;
    /* fail flag is set if we try to read after eof flag is set.
     * these flags can be using cin.eof() and cin.fail();
     * for case if fail flag is set then the return type of "cin>>a" is converted into null pointer
     * which is convertible to false
     * https://en.cppreference.com/w/cpp/io/basic_ios/operator_bool
     */
    if(way == 1){
        while(cin >> a)
            ans = max(ans,a);
    }
    if (way == 2){
        while(true){
            if(cin.eof()) break;
            cin>>a;
            ans = max(ans,a);
        }
    }
    cout << ans << endl;
}
//manual.end

/* TAGS
 * EOF.
 */
