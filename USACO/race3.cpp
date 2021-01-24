/*
ID: ck89119
PROG: race3
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
#define CLR(a,x) memset(a,x,sizeof(a))
#define MP(A,B) make_pair(A,B)
#define PAU system("pause");
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(n) (n^(n-1))&n
#define fin freopen("in.txt","r",stdin);
#define fout freopen("out.txt","w",stdout);
//ifstream fin("");
//ofstream fout("");

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out (vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int MAXN=99999;
const int INF=(1<<30);
const double PI=acos(-1.0);
const double EPS=1e-11;

int n;
int mat[105][105];
int res1[105], res2[105];
int reach1[105], reach2[105];

int input() {
    int v;
    n = 0;
    CLR(mat, 0);
    while (scanf("%d", &v), v != -1) {
        while (v != -2) {
            mat[n][v] = 1;
            scanf("%d", &v);
        }
        n++;
    }
    n--;
    return 0;
}

int connected(int remove) {
    int i, j, k;
    int connect[105][105];
    for (i = 0; i <= n; i++)
        for (j = 0; j <= n; j++)
            connect[i][j] = mat[i][j];
    for (k = 0; k <= n; k++)
        for (i = 0; i <= n; i++)
            for (j = 0; j <= n; j++)
                if (i!=remove && j!=remove && k!=remove)
                    connect[i][j] = connect[i][j] || (connect[i][k]&&connect[k][j]);
    return connect[0][n];
}

int dfs(int cur, int reach[105], int connect[105][105]) {
    int i;
    reach[cur] = 1;
    for (i = 0; i <= n; i++)
        if (!reach[i] && connect[cur][i]) dfs(i, reach, connect);
    return 0;
}

int solve() {
    int i;
    res1[0] = 0;
    for (i = 1; i < n; i++)
        if (!connected(i)) res1[++res1[0]] = i;
    printf("%d", res1[0]);
    for (i = 1; i <= res1[0]; i++) printf(" %d", res1[i]);
    printf("\n");

    res2[0] = 0;
    for (i = 1; i <= res1[0]; i++) {
        int connect[105][105];
        CLR(reach1, 0); CLR(reach2, 0);
        dfs(res1[i], reach1, mat);
        int x, y;
        for (x = 0; x <= n; x++)
            for (y = 0; y <= n; y++) {
                connect[x][y] = mat[x][y];
                if (x == res1[i] || y == res1[i]) connect[x][y] = 0;
            }
        dfs(0, reach2, connect);
        for (x = 0; x <= n; x++)
            if (reach1[x] && reach2[x]) break;
        if (x > n) res2[++res2[0]] = res1[i];
    }
    printf("%d", res2[0]);
    for (i = 1; i <= res2[0]; i++)
        printf(" %d", res2[i]);
    printf("\n");
    return 0;
}

int main() {
    freopen("race3.in", "r", stdin);
    freopen("race3.out", "w", stdout);
    input();
    solve();
    return 0;
}
