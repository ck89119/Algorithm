/*
ID: ck891191
PROG:
LANG: C++
*/
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
using namespace std;
#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl;
#define FR(i,a,b) for(int i=(a);i<(b);++i)//[a,b)
#define CL(a,x) memset(a,x,sizeof(a))
#define MP(A,B) make_pair(A,B)
#define two(X) (1<<(X))
#define towL(X) (((int64)(1))<<(x))
#define contain(S,X) ((S&two(X))>0)
#define containL(S,X) ((S&twoL(X))>0)
//freopen("","r",stdin);
//freopen("","w",stdout);
const long long MAXN=(1LL<<62);
const int INF=(1<<30);
const double PI=acos(-1.0);
const double EPS=1e-11;
const int MOD=1000000007;
long long c[1005][1005];
int n,m;
int list[1005];
long long twoPow[1005];
long long res;

int com(){
    int i,j;
    for (i=0;i<=n;i++) c[i][0]=1;
    for (i=1;i<=n;i++)
        for (j=1;j<=i;j++)
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%MOD;
    twoPow[0]=1;twoPow[1]=1;
    for (i=2;i<=n;i++) twoPow[i]=(twoPow[i-1]*2)%MOD;
    return 0;
}

int main(){
    int i,cnt;
    scanf("%d%d",&n,&m);
    com();
    for (i=0;i<m;i++)  scanf("%d",&list[i]);
    sort(list,list+m);
    res=1;cnt=0;
    for (i=0;i<m;i++){
        int l;
        //dump(i)dump(list[i])
        if (i==0) l=list[i]-1;
        else{
            l=list[i]-list[i-1]-1;
            res=(res*twoPow[l])%MOD;
        }
        //dump(l)dump(res)
        cnt+=l;
        res=(res*c[cnt][l])%MOD;
    }
    cnt+=n-list[m-1];
    res=(res*c[cnt][n-list[m-1]])%MOD;
    cout<<res<<endl;

    return 0;
}
