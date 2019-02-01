// actually ques of persistant seg tree, done using merge_sort
// gives tle
// spoj mkthnum

#include<bits/stdc++.h>
using namespace std;

int arr[100009];
vector<int> * vec[200009];

vector<int> * merge_sort(vector<int> &a,vector<int> &b){
    vector<int> *t = new vector<int>();
    int as,bs,i=0,j=0;
    as = a.size();
    bs = b.size();
    while(i<as && j<bs){
        if(a[i]<=b[j]){
            t->push_back(a[i]);
            i++;
        }
        else{
            t->push_back(b[j]);
            j++;
        }
    }
    while(i<as){
        t->push_back(a[i]);
        i++;
    }
    while(j<bs){
        t->push_back(b[j]);
        j++;
    }
    return t;
}

void make_tree(int l,int r,int i=1){
    int mid = (l+r)/2;
    if(l==r){
        vec[i] = new vector<int>();
        vec[i]->push_back(arr[l]);
        return ;
    }

    make_tree(l,mid,2*i);
    make_tree(mid+1,r,2*i+1);

    vec[i] = merge_sort(*vec[2*i],*vec[2*i+1]);
}

vector<int> * query(int low,int up,int l,int r,int i=1){
    int mid = (l+r)/2;
    vector<int> *a,*b;
    if(low==l && up==r){
        return vec[i];
    }
    if(up<=mid)
        return query(low,up,l,mid,2*i);
    else if(low>mid)
        return query(low,up,mid+1,r,2*i+1);
    else{
        a = query(low,mid,l,mid,2*i);
        b = query(mid+1,up,mid+1,r,2*i+1);

        return merge_sort(*a,*b);
    }

}

int main(){
    int n,q;
    int l,r,p;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    make_tree(1,n);
    while(q--){
        cin>>l>>r>>p;
        cout<<(*query(l,r,1,n))[p-1]<<endl;
    }
}
