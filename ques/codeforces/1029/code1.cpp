#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;

int main(){
    int n,x;
    cin>>n>>x;
    string t,s;
    cin>>t;
    int good = 0;
    int maxx = 0;
    for(int i=0;i<n;i++){
        maxx = i;
        for(int j=0;j<n;j++){
            int k = n-i+j;
            if(k>=n)break;
            if(t[j] != t[k]){
                maxx = 0;
                break;
            }
        }
        good = max(good,maxx);
    }
    if(good == 0){
        for(int i=0;i<x;i++)
            cout<<t;
    }
    else{
        string tt = "";
        for(int i=good;i<n;i++)
            tt += t[i];
        cout << t;
        for(int i=0;i<x-1;i++){
            cout << tt;
        }
        cout << endl;
    }

}
