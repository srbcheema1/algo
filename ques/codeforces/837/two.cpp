#include<bits/stdc++.h>
#define dout if(debug) cout<<" "

using namespace std;

int debug = 0;

const int mod = 1e9+7;
char arr[111][111];
char t_arr[111][111];

class Span{
    public:
    int sx,sy;
    int ex,ey;
    Span(){
        sx = -1; sy = -1; ex = -1; ey = -1;
    }
    void print(){
        dout << sx << " " << sy << endl <<  " " << ex << " " << ey << endl << endl;
    }
};


Span get_val_hor(char a, int n, int m){
    bool found = false;
    Span aa ;
    for(int i=0;i<n;i++){
        if(!found and arr[i][0] == a){
            found = true; aa.sx = i; aa.sy = 0;
        }
        if(found and arr[i][0]!= a){
            aa.ex=i-1;  aa.ey = m-1;
            break;
        }
    }
    if(not found){
        return Span();
    }

    if(found and aa.ex == -1  and arr[n-1][0]==a) {
        dout << "got end" << endl;
        aa.ex = n-1; aa.ey = m-1;
    }

    // verify it is fully filled
    aa.print();
    for (int i=aa.sx;i<=aa.ex;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]!=a){
                dout << i << " " << j << " broke" << endl;
                return Span();
            }
        }
    }

    return aa;
}


void solve(){
    int n,m;
    cin>>n>>m;

    string str;
    for(int i=0;i<n;i++){
        cin>>str;
        for (int j=0;j<m;j++)
            arr[i][j] = str[j];
    }

    bool horizontal = true, vertical = true;
    for(int i=0;i<n;i++)
        if(arr[i][0] != arr[0][0])
            vertical = false;
    for(int i=0;i<m;i++)
        if(arr[0][i] != arr[0][0])
            horizontal = false;

    if(horizontal and vertical) {
        dout << "both hor and ver" << endl;
        cout << "NO" << endl; return;
    }
    if(!horizontal and !vertical){
        dout << "not both hor and ver" << endl;
        cout << "NO" << endl; return;
    }

    if(vertical){
        dout << "vertical" << endl;
        for(int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                t_arr[j][i]=arr[i][j];

        int temp;
        temp = m;
        m = n;
        n = temp;

        for(int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                arr[i][j]=t_arr[i][j];

        horizontal = true;
    }

    if(horizontal) {
        Span rr = get_val_hor('R',n,m);
        Span bb = get_val_hor('B',n,m);
        Span gg = get_val_hor('G',n,m);

        rr.print(); bb.print(); gg.print();

        if(rr.sx == -1 || bb.sx == -1 || gg.sx == -1){
            dout << " sx is -1" << endl;
            cout << "NO" << endl;
            return;
        }

        int lr = rr.ex - rr.sx + 1;
        int lb = bb.ex - bb.sx + 1;
        int lg = gg.ex - gg.sx + 1;

        if(lr == lb  and lr == lg){
            if(lr + lb + lg == n)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
            return;
        } else{
            cout << "NO" << endl;
            return;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t=1;
    //cin>>t;
    while(t--)solve();
}
