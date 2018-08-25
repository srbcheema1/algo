#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    string t;
    cin>>n>>k>>t;

    int l=0,r=t.size()-1;
    while(l<r){
        if(t[l]==t[r] && t[l]==t[0]) l++, r--;
        else break;
    }

    if(l==0)
        for(int i=0;i<k;i++)
            cout<<t;
    else{
        for(int i=0;i<k;i++)
            for(int j=0;j<(int)t.size()-l;j++)
                cout<<t[j];
        for(int i=t.size()-l;i<(int)t.size();i++)
                cout<<t[i];
    }
}
