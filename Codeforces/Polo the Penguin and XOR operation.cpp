/*
ID: ck891191
PROG:
LANG: C++
*/
#include <vector>
#include <list>
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
using namespace std;
#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl;
#define FR(i,a,b) for(int i=(a);i<(b);++i)//[a,b)
#define CL(a,x) memset(a,x,sizeof(a))
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
int twoPow[21];
int n;
int perm[1000005];

int solve(){
    int i,ii;
    for (i=0;i<=20;i++) twoPow[i]=(1<<i);
    i=n;
    while (i>0){
        int k;
        for (ii=0;ii<=20;ii++)
            if (i<twoPow[ii]) break;
        k=twoPow[ii-1];
        for (ii=k;ii<=i;ii++){
            perm[ii]=2*k-1-ii;
            perm[2*k-1-ii]=ii;
        }
        i=2*k-2-i;
    }
    if (i==0) perm[0]=0;
    return 0;
}

int main(){
    long long res;
    scanf("%d",&n);
    res=n;
    res*=(n+1);
    printf("%I64d\n",res);
    solve();
    for (int i=0;i<=n;i++) printf("%d ",perm[i]);
    printf("\n");
    return 0;
}
