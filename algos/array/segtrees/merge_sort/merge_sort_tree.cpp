#include<bits/stdc++.h>
using namespace std;

// manual.begin

// mst begins here
const int nn = 2e6;// size of vec being used
vector<int> tree[4*nn];
void build_tree(int l, int r,vector<int> &vec, int i=1){
    // call it as build(1,n,vec);
    // vec is 1 based
    if(l==r){
        tree[i].push_back(vec[l]);
        return;
    }
    int mid = (l+r)>>1;
    build_tree(l,mid,vec,2*i);
    build_tree(mid+1,r,vec,2*i+1);

    // merge into tree[i]
    merge(tree[2*i].begin(),tree[2*i].end(),tree[2*i+1].begin(),tree[2*i+1].end(),back_inserter(tree[i]));
}

int query(int s,int e, int l, int r, int k, int i=1){
    /*
     * call it as query(1,vec.size(),l,r,k);
     * returns element just smaller than k in given range
     * INT_MIN if all elements are larger than k
     */
    if(l==s and r==e){
        int pos = lower_bound(tree[i].begin(),tree[i].end(),k) - tree[i].begin();// pos of first elem not less than k
        if(pos == 0) return INT_MIN;// no elem less than k
        if(pos == (int)tree[i].size()) return *tree[i].rbegin();// all are smaller return last elem
        return tree[i][pos-1];
    }

    int mid = (s+e)/2;
    if(mid < l)return query(mid+1,e,l,r,k,2*i+1);
    if(mid >= r) return query(s,mid,l,r,k,2*i);
    return max(query(s,mid,l,mid,k,2*i),query(mid+1,e,mid+1,r,k,2*i+1));
}
// mst ends here


signed main(){
    int n,q;
    cin>>n>>q;
    vector<int> vec(n+1);
    for(int i=1;i<=n;i++){
        cin>>vec[i];
    }
    build_tree(1,n,vec);
    while(q--){
        int a,b,k; // range a to b number just lesss than k
        cin>>a>>b>>k;
        int ans =  query(1,n,a,b,k);
        if(ans == INT_MIN) cout << "all are big than " << k << endl;
        else cout << ans << endl;
    }
}
//manual.end

/* TAGS
 * number just less than k in given range
 * numbers smaller than k in given range
 * merge sort
 * merge_sort
 */
