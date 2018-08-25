#include<bits/stdc++.h>
using namespace std;

// manual.begin
template<class T>
void test_stream(T &ss){
    cout << "ss.eof() = " <<  ss.eof() << endl;
    cout << "ss.fail() = " <<  ss.fail() << endl;
    cout << "ss.str() = " <<  ss.str() << endl;
}

signed main(){
    int a,b;
    cin>>a; // it will read first integer from stream and leave everything behind.
    /*
     * it is used to ingore till next endline char
     * http://www.cplusplus.com/reference/istream/istream/ignore/
     * https://stackoverflow.com/questions/25475384/when-and-why-do-i-need-to-use-cin-ignore-in-c
     * it will ignore either upto first \n or first 256 characters whichever happens first.
     * by default it is cin.ignore(size_t n = 1, char delim = EOF)
     * so we can notice that it will only remove one char.
     */
    cin.ignore(256,'\n');
    string s;
    stringstream ss;

    /* dont use cin.getline(chat *a, size_t s);
     * because we dont generally want to deal with char arrays.
     * use getline(ostream &cin, string s);
     * it reads till endline characeter. it removes it from stream but don't insert that into the string.
     * generally cin don't remove spaces and endline characters from streams.
     * these characters are left in stream for next read.
     * during next read cin will start ignoring useless characters(spaces + endlines) till it get useful character.
     * after reading few consuctive useful characters it will stop at useless characters(generally whitespace or endl)
     */

    /* getline reads until next endline character.
     * https://stackoverflow.com/a/47505853/6799074
     */
    while(getline(cin,s)){
        ss.str(s);
        ss >> a >> b;
        test_stream(ss);
        cout << " variable read : " << a << " " << b << endl;
        test_stream(ss);
        /* iostream::clear
         * if we dont use ss.clear then eof bit will reamain set and again reading will lead to fail bit set.
         * you can avoid this by providing input like:
         * 4
         * 3 5 
         * 4 6 
         * first line of input is for cin>>a;
         * notice the trailing white space it will not set eof flag
         * and next time you will reinitilize the stream with string
         * and then you can again read without need of ss.clear();
         */
        ss.clear();
    }
}
//manual.end

/* TAGS
 * cin
 * read streams
 * streams
 * getline
 */
