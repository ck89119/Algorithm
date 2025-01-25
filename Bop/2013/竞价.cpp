/*
ID: ck891191
PROG:
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
using namespace std;
#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl;
#define FR(i,a,b) for(int i=(a);i<(b);++i)//[a,b)
#define CL(a,x) memset(a,x,sizeof(a))
#define MP(A,B) make_pair(A,B)
#define two(X) (1<<(X))
#define towL(X) (((int64)(1))<<(x))
#define contain(S,X) ((S&two(X))>0)
#define containL(S,X) ((S&twoL(X))>0)
#define lowbit(x) ((x)&(-(x)))
//freopen("","r",stdin);
//freopen("","w",stdout);
const long long MAXN=(1LL<<62);
const int INF=(1<<30);
const double PI=acos(-1.0);
const double EPS=1e-11;
int t;
int n,ca,cb;
int f[10+5][10+5][10+5];

int search(int kk, int a, int b){
    int i,ans;
    //dump(kk)dump(a)dump(b)
    cout<<kk<<' '<<a<<' '<<b<<endl;
    if (f[kk][a][b]!=-1) return f[kk][a][b];
    ans=0;
    for (i=a-1;i>=max(a-b,0);i--)
        ans=max(ans,search(kk-1,i,b)+1);
    for (i=b-2;i>=max(b-a-1,0);i--)
        ans=max(ans,search(kk-1,a,i));
    f[kk][a][b]=ans;
    //
    return f[kk][a][b];
}

int main(){
    int i,j,k,kk;
    scanf("%d",&t);
    for (k=1;k<=t;k++){
        scanf("%d%d%d",&n,&ca,&cb);
        CL(f,-1);
        for(i=1;i<=ca;i++)
            for (j=1;j<=cb;j++)
                if (i>=j) f[1][i][j]=1;
                else f[1][i][j]=0;
        for (i=0;i<=n;i++) f[i][0][0]=0;
        for (kk=2;kk<=n;kk++)
            for(i=1;i<=ca;i++)
                for (j=1;j<=cb;j++) search(kk,i,j);
        if (f[n][ca][cb]*2>n) printf("Case #%d: %d\n",k,1);
        else if (f[n][ca][cb]*2==n) printf("Case #%d: %d\n",k,0);
        else printf("Case #%d: %d\n",k,-1);
    }
    return 0;
}
