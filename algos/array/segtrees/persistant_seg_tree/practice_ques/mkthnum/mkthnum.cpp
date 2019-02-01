#include<bits/stdc++.h>
#define mp pair<int,int>
using namespace std;

vector< pair<int,int> > arr;// before sort
vector< pair<int,int> > vec;// after sort
struct node{
    node *left,*right;
    int val;

    node(int v=0){val=v;left=NULL;right=NULL;}

    node(node *l,node *r,int v){left=l;right=r;val=v;}
};

node version[100003];

void make_tree(node &curr,int l,int r){
    if(l==r){
        curr.val=0;
        return;
    }
    int mid=(l+r)/2;
    curr.left = new node(0);
    curr.right = new node(0);

    make_tree(*(curr.left),l,mid);
    make_tree(*(curr.right),mid+1,r);
}

void make_version(node &past,node &curr,int l,int r,int pos){
    if(l==r){
        curr.val=1;
        return ;
    }

    int mid=(l+r)/2;
    if(pos<=mid){
        curr.left = new node(0);
        curr.right = past.right;
        make_version(*(past.left),*(curr.left),l,mid,pos);
    }
    else{
        curr.right = new node(0);
        curr.left = past.left;
        make_version(*(past.right),*(curr.right),mid+1,r,pos);
    }
    curr.val = curr.right->val + curr.left->val;
}

int query(node &past,node &curr,int l,int r,int pos){
    int left,right,mid;
    mid=(l+r)/2;
    if(l==r)
        return l;
    left = curr.left->val - past.left->val;
    right = curr.right->val - past.right->val;

    if(pos<=left){
        return query(*(past.left),*(curr.left),l,mid,pos);
    }
    else{
        return query(*(past.right),*(curr.right),mid+1,r,pos-left);
    }
}


int main(){
    int n,q,v;
    cin>>n>>q;
    int l,r,p,pos;

    arr.push_back(mp(0,0));
    vec.push_back(mp(0,0));
    for(int i=1;i<=n;i++){
        cin>>v;
        arr.push_back(mp(v,i));
        vec.push_back(mp(v,i));
    }
    sort(vec.begin()+1,vec.end());
    for(int i =1;i<=n;i++){
        arr[vec[i].second].second=i;
    }

    make_tree(version[0],1,n);
    for(int i=1;i<=n;i++){
        make_version(version[i-1],version[i],1,n,arr[i].second);
    }
    while(q--){
        cin>>l>>r>>p;
        pos=query(version[l-1],version[r],1,n,p);
        cout<<vec[pos].first<<endl;
    }
}
