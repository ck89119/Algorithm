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

int main() {
    int m, n;
    int i;
    scanf("%d%d", &n, &m);
    if (n == m) {
        printf("%d\n", 2*n-1);
        for (i = 1; i <= n-1; i++) {
            printf("%d %d\n", i, i);
            printf("%d %d\n", i, i+1);
        }
        printf("%d %d\n", n, n);
    }
    else {
        printf("%d\n", n+m-1);
        if (n < m) {
            for (i = 1; i <= n; i++) {
                printf("%d %d\n", i, i);
                printf("%d %d\n", i, i+1);
            }
            for (i = n+2; i <= m; i++)
                printf("%d %d\n", n, i);
        }
        else {
            for (i = 1; i <= m; i++) {
                printf("%d %d\n", i, i);
                printf("%d %d\n", i+1, i);
            }
            for (i = m+2; i <= n; i++)
                printf("%d %d\n", i, m);
        }

    }
    return 0;
}
