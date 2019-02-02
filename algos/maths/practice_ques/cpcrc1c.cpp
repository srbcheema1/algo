//http://www.spoj.com/problems/CPCRC1C/
#include<bits/stdc++.h>
#define int long long

using namespace std;

int arr[10]={0,1,3,6,10,15,21,28,36,45};
int sum[11];

int sum_of_digits(string str){
    int ans =0;
    for(int i=0;i<(int)str.length();i++) ans+=str[i]-'0';
    return (int)ans;
}

int digit_sum(string str){
    int ans;
    int len = str.length();
    if(len==1){
        return arr[str[0]-'0'];
    }
    string left = str.substr(0,len-1);
    if(str[len-1]=='9'){
        int n = stoi(str);
        ans = ((n+1)/10)*45 + digit_sum(left)*10;
        return ans;
    }
    else{
        int d = (str[len-1]-'0');
        ans = (d+1)*sum_of_digits(left)+digit_sum(str.substr(len-1,1));
        ans += digit_sum(to_string(stoi(str)-d-1));
        return ans;
    }
}

signed main(){
    int a,b;
    string aa,bb;
    int ans_a,ans_b;
    cin>>a>>b;
    while(a>=0){
        if(a==0)a++;
        aa=to_string(a-1);
        bb=to_string(b);
        ans_a=digit_sum(aa);
        ans_b=digit_sum(bb);
        cout<<ans_b-ans_a<<endl;
        cin>>a>>b;
    }
}
