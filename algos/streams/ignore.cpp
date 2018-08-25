#include<bits/stdc++.h>
using namespace std;

// manual.begin

signed main(){
    /*
     * more about cin.ignore visit : https://stackoverflow.com/a/47505853/6799074
     * input is of next two lines
     * Stack Overflow<Enter>
     * Where developers learn.<Enter>
     * for more about cin.ignore visit http://www.cplusplus.com/reference/istream/istream/ignore/
     */
    string name, address;
    cin>>name;
    cin.ignore();
    //cin.ignore(256,'\n');
    getline(cin,address);
    cout << address << endl;
    assert(address == " Overflow"); // breaks if using cin.ignore() or cin.ignore(256,'\n')
    assert(address == "Overflow"); // breaks if using cin.ignore(256,'\n') OR not using any
    assert(address == "Where developers learn."); // breaks if using cin.ignore() or not using any
}
//manual.end

/* TAGS
 *
 */
