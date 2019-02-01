//http://codeforces.com/problemset/problem/835/C
//wrong ans
//but there is some concept of 2d seg tree
#include<bits/stdc++.h>

using namespace std;

int isstar[102][102];
int arr[11][102][102];
int seg[11][404][404];

void make_tree(int n,int l,int r,int d,int u,int i=1,int j=1){
    int midx = (l+r)/2,midy = (u+d)/2;
    if(l==r){
        if(d==u){
            seg[n][i][j]=arr[n][l][u];
            return;
        }
        make_tree(n,l,r,d,midy,i,2*j);
        make_tree(n,l,r,midy+1,u,i,2*j+1);

        seg[n][i][j] = seg[n][i][2*j] + seg[n][i][2*j+1];
        return;
    }
    
    make_tree(n,l,midx,d,u,2*i,j);
    make_tree(n,midx+1,r,d,u,2*i+1,j);
    
    for(int k=2;k<=4*u-1;k++)
        seg[n][i][k]=seg[n][2*i][k] + seg[n][2*i+1][k];
    

    seg[n][i][j] = seg[n][2*i][j] + seg[n][2*i+1][j];
    return;
}

int db=0;
int query(int n,int x1,int x2,int y1,int y2,int l,int r,int d,int u,int i=1,int j=1){
    int x=(l+r)/2,y=(u+d)/2;
//    cout<<x1<<" "<<x2<<" "<<y1<<" "<<y2<<" ; "<<l<<" "<<r<<" "<<d<<" "<<u<<" "<<i<<" "<<j<<endl;

    //ans in node itself
    if(x1==l && x2==r && y1==d && y2==u){
//        cout<<"here"<<i<<" "<<j<<seg[n][i][j]<<endl;
        return seg[n][i][j];
    }

    //expand in two side child... either y or x is satisfied
    if(y1==d && y2==u){
        if(x2<=x) return query(n,x1,x2,y1,y2,l,x,d,u,2*i,j);
        if(x1>x) return query(n,x1,x2,y1,y2,x+1,r,d,u,2*i+1,j);
        return query(n,x1,x,y1,y2,l,x,d,u,2*i,j)+query(n,x+1,x2,y1,y2,x+1,r,d,u,2*i+1,j);
    }
    if(x1==l && x2==r){
        if(y2<=y) return query(n,x1,x2,y1,y2,l,r,d,y,i,2*j);//x1,x2,y1,y2,
        if(y1>y) return query(n,x1,x2,y1,y2,l,r,y+1,u,i,2*j+1);
        return query(n,x1,x2,y1,y,l,r,d,y,i,2*j)+query(n,x1,x2,y+1,y2,l,r,y+1,u,i,2*j+1);
    }

    //ans in single diag child node
    if(x2<=x && y2<=y){//quad l-d
        return query(n,x1,x2,y1,y2,l,x,d,y,2*i,2*j);
    }
    else if(x1>x && y2<=y){//quad r-d
        return query(n,x1,x2,y1,y2,x+1,r,d,y,2*i+1,2*j);
    }
    else if(x2<=x && y1>y){//quad l-u
        return query(n,x1,x2,y1,y2,l,x,y+1,u,2*i,2*j+1);
    }
    else if(x1>x && y1>y){//quad r-u
        return query(n,x1,x2,y1,y2,x+1,r,y+1,u,2*i+1,2*j+1);
    }
    
    //ans in 2 diag child nodes
    else if(x2<=x){
        return query(n,x1,x2,y1,y,l,x,d,y,2*i,2*j)+query(n,x1,x2,y+1,y2,l,x,y+1,u,2*i,2*j+1);
    }
    else if(x1>x){
        return query(n,x1,x2,y1,y,x+1,r,d,y,2*i+1,2*j)+query(n,x1,x2,y+1,y2,x+1,r,y+1,u,2*i+1,2*j+1);
    }
    else if(y2<=y){
        return query(n,x1,x,y1,y2,l,x,d,y,2*i,2*y) + query(n,x+1,x2,y1,y2,x+1,r,d,y,2*i+1,2*j);
    }
    else if(y1>y){
        return query(n,x1,x,y1,y2,l,x,y+1,u,2*i,2*j+1) + query(n,x+1,x2,y1,y2,x+1,r,y+1,u,2*i+1,2*j+1);
    }


    //ans in 4 diag child nodes
    return query(n,x1,x,y1,y,l,x,d,y,2*i,2*j)+  query(n,x1,x,y+1,y2,l,x,y+1,u,2*i,2*j+1)+
     query(n,x+1,x2,y1,y,x+1,r,d,y,2*i+1,2*j)+  query(n,x+1,x2,y+1,y2,x+1,r,y+1,u,2*i+1,2*j+1);
}


int main(){
    int n,q,c;
    int x,y,s;
    int x1,x2,y1,y2,t=0;
    int maxx=3,maxy=3;
    cin>>n>>q>>c;
    while(n--){
        cin>>x>>y>>s;
        arr[0][x][y]=s;
        isstar[x][y]=1;
        if(x>maxx) maxx=x;
        if(y>maxy) maxy=y;
    }
    maxx++,maxy++;    
    maxx=100;maxy=100;
    make_tree(0,1,maxx,1,maxy);
    for(int k=1;k<=c;k++){
        for(int i=1;i<=maxx;i++)
            for(int j=1;j<=maxy;j++)
                if(isstar[i][j]==1){
                    if(arr[k-1][i][j]<c){
                        arr[k][i][j]=arr[k-1][i][j]+1;
                    }
                    else arr[k][i][j]=0;
                }
        make_tree(k,1,maxx,1,maxy);
    }
    while(q--){
        cin>>t>>x1>>y1>>x2>>y2;
//        if(x1>maxx) x1=maxx;
//        if(x2>maxx) x2=maxx;
//        if(y1>maxy) y1=maxy;
//        if(y2>maxy) y2=maxy;
        t = t%(c+1);
        cout<<query(t,x1,x2,y1,y2,1,maxx,1,maxy)<<endl;
    }
}
