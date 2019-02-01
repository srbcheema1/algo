#include<bits/stdc++.h>
#define ui long long int

using namespace std;

ui arry[100000];
struct Node{
    ui R,L,S,B;
}seg[200000];

ui maxx(ui a,ui b,ui c,ui d,ui e){
    ui ab = max(a,b);
    ui cd = max(c,d);
    ui abcd = max(ab,cd);
    ui abcde = max (abcd,e);
    return abcde;
}

void make_tree(int low,int up,int loc){
    int mid=(up+low)/2;
    if(up==low){
        seg[loc].S=seg[loc].R=seg[loc].L=seg[loc].B=arry[up];
        return;
    }
    make_tree(low,mid,2*loc);
    make_tree(mid+1,up,2*loc+1);
    int r=2*loc+1;
    int l=2*loc;
    seg[loc].S = seg[l].S + seg[r].S;
    seg[loc].L = max(seg[l].S + seg[r].L , seg[l].L);
    seg[loc].R = max(seg[l].R + seg[r].S , seg[r].R);
    seg[loc].B = maxx(seg[r].B , seg[l].B , seg[loc].L , seg[loc].R , seg[l].R + seg[r].L);
}

Node query(int l,int r,int low,int up,int loc){
    int mid=(low+up)/2;
    if(l==low && r==up){
       return seg[loc];
    }
    else if(r<=mid){
        return query(l,r,low,mid,2*loc);
    }
    else if(l>mid){
        return query(l,r,mid+1,up,2*loc+1);
    }
    else{
        Node ll = query(l,mid,low,mid,2*loc);
        Node rr = query(mid+1,r,mid+1,up,2*loc+1);

        Node temp;
        temp.S = ll.S + rr.S;
        temp.L = max(ll.S + rr.L , ll.L);
        temp.R = max(ll.R + rr.S , rr.R);
        temp.B = maxx(rr.B , ll.B , temp.L , temp.R , ll.R + rr.L);
        return temp;
    }
}

int main(){
    int n,m,l,r;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>arry[i];
    make_tree(1,n,1);
    cin>>m;
    while(m--){
        cin>>l>>r;
        cout<<query(l,r,1,n,1).B<<endl;
    }
    return 0;
}

//https://www.spoj.com/problems/GSS1/
