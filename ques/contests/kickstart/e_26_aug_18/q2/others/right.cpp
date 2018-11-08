#include<bits/stdc++.h>
#define LL long long
#define ull unsigned long long
#define ULL ull
#define mp make_pair
#define pii pair<int,int>
#define piii pair<int, pii >
#define pll pair <ll,ll>
#define pb push_back
#define big 20160116
#define INF 2147483647
#define pq priority_queue
#define rank rk124232
#define y1 y20160116
#define y0 y20160110
#define _ 0
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
namespace Mymath{
	LL qp(LL x,LL p,LL mod){
		LL ans=1;
		while (p){
			if (p&1) ans=ans*x%mod;
			x=x*x%mod;
			p>>=1;
		}
		return ans;
	}
	LL inv(LL x,LL mod){
		return qp(x,mod-2,mod);
	}
	LL C(LL N,LL K,LL fact[],LL mod){
		return fact[N]*inv(fact[K],mod)%mod*inv(fact[N-K],mod)%mod;
	}
	template <typename Tp> Tp gcd(Tp A,Tp B){
		if (B==0) return A;
		return gcd(B,A%B);
	}
	template <typename Tp> Tp lcm(Tp A,Tp B){
		return A*B/gcd(A,B);
	}
};
const int Maxn=105;
bitset<Maxn> ban[Maxn];
int c0[Maxn],c1[Maxn];
bool bc[Maxn];
char tmp[Maxn];
int ff[Maxn];
int n,m,p;
struct st{
	int v;
	bitset<Maxn> s;
	bool operator <(const st& S)const{
		return v>S.v;
	}
	st(){}
	st(int _v,bitset<Maxn> _s){
		v=_v,s=_s;
	}
};

void mian(int tc){
	memset(c0,0,sizeof(c0));
	memset(c1,0,sizeof(c1));
	n=read();m=read();p=read();
	for (int i=0;i<Maxn;i++) ban[i]=0;
	for (int i=0;i<n;i++){
		scanf("%s",tmp);
		for (int j=0;j<p;j++){
			if (tmp[j]=='0') c0[j]++;
			else c1[j]++;
		}
	}
	bitset<Maxn> beg;
	int begcost=0;
	for (int i=0;i<p;i++){
		if (c0[i]<c1[i]){
			beg[i]=1;
			begcost+=c0[i];
			bc[i]=1;
		}
		else{
			begcost+=c1[i];
			bc[i]=0;
			beg[i]=0;
		}
		ff[i]=abs(c0[i]-c1[i]);
	}
	for (int i=0;i<m;i++){
		scanf("%s",tmp);
		for (int j=0;j<p;j++){
			if (tmp[j]=='0') ban[i][j]=0;
			else ban[i][j]=1;
		}
	}
	priority_queue<st> Q;
	Q.push(st(begcost,beg));
	while (!Q.empty()){
		st X=Q.top();Q.pop();
		bool flag=true;
		for (int i=0;i<m;i++){
			if (X.s==ban[i]){
				flag=false;
				break;
			}
		}
		if (flag){
			printf("Case #%d: %d\n",tc,X.v);
			return;
		}
		for (int i=0;i<p;i++){
			if (X.s[i]==bc[i]){
				X.s[i]=1-X.s[i];
				X.v+=ff[i];
				Q.push(X);
				X.s[i]=1-X.s[i];
				X.v-=ff[i];
			}
		}
	}
}
int main(){
	int T=read();
	int t=0;
	while (T--){
		t++;
		mian(t);
	}
	return 0;
}
