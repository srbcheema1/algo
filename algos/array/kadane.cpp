#include<bits/stdc++.h>
using namespace std;

/*
 * good editorials :
 * https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
 */

// manual.begin
int kadane(vector<int> &arr){
    // for negative case
    int maxx = INT_MIN;
    for(int i=0;i<(int)arr.size();i++) maxx = max(maxx,arr[i]);
    if(maxx <=0) return maxx;

    int local_max=0,ans = 0;
    for(int i=0;i<(int)arr.size();i++){
        if(local_max + arr[i] <= 0) local_max = 0;
        else local_max += arr[i];
        ans = max(local_max,ans);
    }
    return ans;
}

signed main(){
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    cout << kadane(vec) << endl;
}
//manual.end

/* TAGS
 * largest continous array sum.
 * largest subarray sum
 */
