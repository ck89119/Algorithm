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

int a[1000+5];
int n;
int z_n,neo_n;

int main() {
    int i,k;
    scanf("%d",&n);
    z_n=neo_n=0;
    for (i=0;i<n;i++) {
        scanf("%d", &a[i]);
        if (a[i]==0) z_n++;
        if (a[i]<0) neo_n++;
    }
    i=0;
    while (a[i]>=0) i++; k=i;
    printf("%d %d\n",1,a[k]);

    if (n-z_n-neo_n>0){
        printf("%d",n-z_n-neo_n);
        for (i=0;i<n;i++)
            if (a[i]>0) printf(" %d",a[i]);
        printf("\n");

        printf("%d",z_n+neo_n-1);
        for (i=0;i<z_n;i++) printf(" %d",0);
        for (i=0;i<n;i++)
            if (a[i]<0&&i!=k) printf(" %d",a[i]);
        printf("\n");
    }
    else {
        int s=0;
        printf("%d",2);
        for (i=0;i<n&&s<2;i++)
            if (a[i]<0&&i!=k) {
                printf(" %d",a[i]);
                a[i]=-a[i];
                s++;
            }
        printf("\n");

        printf("%d",n-3);
        for (i=0;i<z_n;i++) printf(" %d",0);
        for (i=0;i<n;i++)
            if (a[i]<0&&i!=k) printf(" %d",a[i]);
        printf("\n");
    }

    return 0;
}
