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

int f[205];
int t[105],w[105];
int n;

int main(){
    int i,j,sum_w,sum_t;
    scanf("%d",&n);
    sum_w=sum_t=0;
    for (i=0;i<n;i++){
        scanf("%d%d",&t[i],&w[i]);
        sum_t+=t[i];
        sum_w+=w[i];
    }
    //dump(sum_w)
    for (j=sum_t;j>=0;j--) f[j]=INF;
    f[0]=sum_w;
    for (i=0;i<n;i++)
        for (j=sum_t;j>=t[i];j--)
            f[j]=min(f[j],f[j-t[i]]-w[i]);
    for (i=0;i<=sum_t;i++)
        if (i>=f[i]) break;
    printf("%d\n",i);

    return 0;
}
