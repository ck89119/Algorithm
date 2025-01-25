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
int n,m;
int grass[100+5][100+5];

int check(int x,int y){
    int flag;
    int i,j;
    flag=1;
    for (i=0;i<n;i++)
        if (grass[i][y]>grass[x][y]){
            flag=0;
            break;
        }
    if (flag) return 1;
    flag=1;
    for (j=0;j<m;j++)
        if (grass[x][j]>grass[x][y]){
            flag=0;
            break;
        }
    if (flag) return 1;
    else return 0;
}

int main(){
    int i,j,k;
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    scanf("%d",&t);
    for (k=1;k<=t;k++){
        int flag;
        scanf("%d%d",&n,&m);
        for (i=0;i<n;i++)
            for (j=0;j<m;j++) scanf("%d",&grass[i][j]);
        flag=1;
        for (i=0;i<n&&flag;i++)
            for (j=0;j<m&&flag;j++)
                if (!check(i,j)){
                    flag=0;
                }
        if (flag) printf("Case #%d: YES\n",k);
        else printf("Case #%d: NO\n",k);
    }
    return 0;
}
