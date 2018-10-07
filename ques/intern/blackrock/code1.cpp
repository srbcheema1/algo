#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int get_pp(const string & line){
    size_t loc = line.find(';');
    return int(stod(line.substr(0,loc)) * 100);
}

double get_ch(const string & line){
    size_t loc = line.find(';');
    return int(stod(line.substr(loc+1)) * 100);
}

int main() {
    string line;
    double pp, ch;
    std::map<int,string> cash = {
        {1,"PENNY"},
        {5,"NICKEL"},
        {10,"DIME"},
        {25,"QUATER"},
        {50,"HALF DOLLAR"},
        {100,"ONE"},
        {200,"TWO"},
        {500,"FIVE"},
        {1000,"TEN"},
        {2000,"TWENTY"},
        {5000,"FIFTY"},
        {10000,"ONE HUNDRED"}
    };

    while (getline(cin, line)) {
        pp = get_pp(line);
        ch = get_ch(line);

        if (ch < pp) {
            cout << "ERROR" << endl;
        } else if (ch == pp) {
            cout << "ZERO" << endl;
        } else {
            vector<string> output;
            std::map<int,string>::iterator it;
            while (ch > pp) {
                it = cash.upper_bound(ch-pp);
                it--; // just smaller value
                ch -= it->first;
                output.push_back(it->second);
            }
            sort(output.begin(),output.end());
            string result;
            for (auto val: output) {
                result+=val;
                result+=",";
            }
            result.pop_back();
            cout << result << endl;
        }
    }

    return 0;
}
