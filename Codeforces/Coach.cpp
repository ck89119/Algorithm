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
#include <cstring>
#include <cstdlib>
using namespace std;
#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl;
#define FR(i,a,b) for(int i=(a);i<(b);++i)//[a,b)
#define CL(a,x) memset(a,x,sizeof(a))
#define MP(A,B) make_pair(A,B)
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
//freopen("","r",stdin);
//freopen("","w",stdout);
//ifstream fin("");
//ofstream fout("");
const int MAXN = 9999;
const int INF=(1<<30);
const double PI=acos(-1.0);
const double EPS=1e-11;

int n,m;
int dep[50][50];
int n1,n2;
int belong[50];
int b_num[50],b_size;


int dfs(int k,int c) {
    int i;
    for (i=1; i<=n; i++)
        if (!belong[i]&&dep[k][i]){
            belong[i]=c;
            dfs(i,c);
        }
    return 0;
}

int main() {
    int i,j,k,a,b;
    scanf("%d%d", &n,&m);
    CL(dep, 0);
    for (i=0;i<m;i++) {
        scanf("%d%d", &a,&b);
        dep[a][b]=1;
        dep[b][a]=1;
    }
    CL(belong, 0); b_size=0;
    for (i=1;i<=n;i++)
        if (!belong[i]) {
            belong[i]=++b_size;
            dfs(i,b_size);
        }
   // for (i=1;i<=n;i++) cout<<belong[i]<<' ';cout<<endl;
    CL(b_num, 0);
    for (i=1;i<=n;i++)
        b_num[belong[i]]++;
   // for (i=1;i<=n;i++) cout<<b_num[i]<<' ';cout<<endl;
    n1=n2=0;
    int flag=1;
    for (i=1;i<=b_size&&flag;i++)
        if (b_num[i]==1) n1++;
        else if (b_num[i]==2) n2++;
        else if (b_num[i]>3) flag=0;
    if (!flag||n1<n2) {
        printf("-1\n");
        return 0;
    }

    for (i=1;i<=b_size;i++)
        if (b_num[i]==3) {
            for (j=1;j<=n;j++)
                if (belong[j]==i) printf("%d ",j);
            printf("\n");
            b_num[i]=-1;
        }
        else if (b_num[i]==2) {
            for (j=1;j<=n;j++)
                if (belong[j]==i) printf("%d ",j);
            b_num[i]=-1;
            //dump(i)
            for (j=1;j<=b_size;j++)
                if (b_num[j]==1) break;
            b_num[j]=-1;
            //dump(j)
            for (k=1;k<=n;k++)
                if (belong[k]==j){
                    printf("%d \n",k);
                    break;
                }
        }

    k=0;
    for (i=1; i<=b_size; i++)
        if (b_num[i]!=-1) {
            for (j=1;j<=n;j++)
                if (belong[j]==i) {
                    printf("%d ",j);
                    k++;
                    if (k==3) {
                        k=0;
                        printf("\n");
                    }
                    break;
                }
            b_num[i]=-1;
        }

    return 0;
}
