#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<utility>
#include<functional>
#include<iomanip>
#include<sstream>
#include<ctime>
#include<cassert>
using namespace std;
#define y0 y0z
#define y1 y1z
#define yn ynz
#define j0 j0z
#define j1 j1z
#define jn jnz
#define tm tmz
#define buli(x) (__builtin_popcountll(x))
#define bur0(x) (__builtin_ctzll(x))
#define bul2(x) (63-__builtin_clzll(x))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define fil(a,b) memset((a),(b),sizeof(a))
#define cl(a) fil(a,0)
#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)
#define pw(x) ((ll(1))<<(x))
#define upmo(a,b) (((a)=((a)+(b))%mo)<0?(a)+=mo:(a))
#define mmo(a,b) (((a)=1ll*(a)*(b)%mo)<0?(a)+=mo:(a))
void getre(){int x=0;printf("%d\n",1/x);}
void gettle(){int res=1;while(1)res<<=1;printf("%d\n",res);}
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
template<typename T,typename S>inline bool upmin(T&a,const S&b){return a>b?a=b,1:0;}
template<typename T,typename S>inline bool upmax(T&a,const S&b){return a<b?a=b,1:0;}
template<typename N,typename PN>inline N flo(N a,PN b){return a>=0?a/b:-((-a-1)/b)-1;}
template<typename N,typename PN>inline N cei(N a,PN b){return a>0?(a-1)/b+1:-(-a/b);}
template<typename N>N gcd(N a,N b){return b?gcd(b,a%b):a;}
template<typename N>inline int sgn(N a){return a>0?1:(a<0?-1:0);}
#if ( ( _WIN32 || __WIN32__ ) && __cplusplus < 201103L)
    #define lld "%I64d"
#else
    #define lld "%lld"
#endif
inline void gn(long long&x){
	int sg=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');c=='-'?(sg=-1,x=0):(x=c-'0');
	while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';x*=sg;
}
inline void gn(int&x){long long t;gn(t);x=t;}
inline void gn(unsigned long long&x){long long t;gn(t);x=t;}
inline void gn(double&x){double t;scanf("%lf",&t);x=t;}
inline void gn(long double&x){double t;scanf("%lf",&t);x=t;}
inline void gs(char *s){scanf("%s",s);}
inline void gc(char &c){while((c=getchar())>126 || c<33);}
inline void pc(char c){putchar(c);}
#ifdef JCVB
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...) 
#endif
typedef long long ll;
typedef long double db;
inline ll sqr(ll a){return a*a;}
inline db sqrf(db a){return a*a;}
const int inf=0x3f3f3f3f;
const db pi=3.14159265358979323846264338327950288L;
const db eps=1e-6;
//const int mo=0;
//int qp(int a,ll b){int n=1;do{if(b&1)n=1ll*n*a%mo;a=1ll*a*a%mo;}while(b>>=1);return n;}


int totcoin,n;
ll ma;

int ki[20],li[20];
int A[22][22];
int co[22][22];


int lis[20];

ll cnt[10],powe[10][20],hua[10][20];

struct node{
	ll co,powe;
}lef[111111],rig[111111];
int cmp(const node&a,const node&b){
	if(a.co==b.co)return a.powe>b.powe;
	return a.co<b.co;
}
int ltot,rtot;
void gao(){
	rep(j,1,8+1){
		int i=lis[j];
		cnt[j]=ki[i]-li[i]+1;

		powe[j][1]=A[i][li[i]];
		hua[j][1]=0;
		for (int t=li[i]+1;t<=ki[i];t++){
			powe[j][t-li[i]+1]=A[i][t];
			hua[j][t-li[i]+1]=hua[j][t-li[i]]+co[i][t];
		}
	}
	ltot=rtot=0;
	rep(i,1,cnt[1]+1)
		rep(j,1,cnt[2]+1)
			rep(k,1,cnt[3]+1)
				rep(l,1,cnt[4]+1)
					lef[++ltot]=(node){hua[1][i]+hua[2][j]+hua[3][k]+hua[4][l],powe[1][i]+powe[2][j]+powe[3][k]+powe[4][l]};
	rep(i,1,cnt[5]+1)
		rep(j,1,cnt[6]+1)
			rep(k,1,cnt[7]+1)
				rep(l,1,cnt[8]+1)
					rig[++rtot]=(node){hua[5][i]+hua[6][j]+hua[7][k]+hua[8][l],powe[5][i]+powe[6][j]+powe[7][k]+powe[8][l]};

	int top;
	
	top=1;
	sort(lef+1,lef+1+ltot,cmp);
	for (int i=2;i<=ltot;i++)
		if(lef[i].powe>lef[top].powe)lef[++top]=lef[i];
	ltot=top;


	top=1;
	sort(rig+1,rig+1+rtot,cmp);
	for (int i=2;i<=rtot;i++)
		if(rig[i].powe>rig[top].powe)rig[++top]=rig[i];
	rtot=top;

	int cur=1;

	for (int i=ltot;i>=1;i--){
		while(cur<rtot && rig[cur+1].co+lef[i].co<=totcoin)cur++;
		if(rig[cur].co+lef[i].co<=totcoin)upmax(ma,rig[cur].powe+lef[i].powe);
	}
}
void dfs(int i,int sel){
	if(sel==8){
		gao();
	}else{
		if(i>n)return;
		lis[sel+1]=i;
		dfs(i+1,sel+1);
		dfs(i+1,sel);
	}
}
int main()
{
  freopen("D-large-practice.in", "r", stdin);
	freopen("std.out","w",stdout);
	int _time_jc=clock();
	int tes;
	gn(tes);
	rep(_,1,tes+1){
		printf("Case #%d: ",_);
		gn(totcoin);gn(n);
		ma=0;

		rep(i,1,n+1){
			gn(ki[i]);gn(li[i]);
			rep(j,1,ki[i]+1)gn(A[i][j]);
			rep(j,2,ki[i]+1)gn(co[i][j]);
		}

		dfs(1,0);
		cout<<ma<<endl;
		cerr<<_<<endl;
	}
#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}


