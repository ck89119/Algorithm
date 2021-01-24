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

int dir[4][2] = {0, -1, -1, 0, 0, 1, 1, 0};
int n,m;
int grid[505][505];
int n_com, n_dot;

int InBoard(int x, int y) {
    if (x > 0 && x <= n && y > 0 && y <= m) return 1;
    else return 0;
}

int dfs(int x, int y, int color) {
    int k;
    grid[x][y] = color;
    for (k = 0; k < 4; k++) {
        int tx, ty;
        tx = x+dir[k][0];
        ty = y+dir[k][1];
        if (InBoard(tx, ty) && grid[tx][ty] == 0)
            dfs(x+dir[k][0], y+dir[k][1], color);
    }
    return 0;
}

int print(int x, int y, int init) {
    int k;
    grid[x][y] = -1;
    for (k = 0; k < 4; k++) {
        int tx, ty;
        tx = x+dir[k][0];
        ty = y+dir[k][1];
        if (InBoard(tx, ty) && grid[tx][ty] != -1)
            print(x+dir[k][0], y+dir[k][1], 0);
    }
    if (!init){
        printf("D %d %d\n", x, y);
        printf("R %d %d\n", x, y);
    }

    return 0;
}

int main() {
    int i,j;
    scanf("%d%d", &n, &m);
    n_dot = n * m;
    for (i = 1; i <= n; i++) {
        char ch;
        getchar();
        for (j = 1; j <= m; j++) {
            scanf("%c", &ch);
            if (ch == '#') {grid[i][j] = -1; n_dot--;}
        }
    }

    n_com = 0;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            if (grid[i][j] == 0) {
                n_com++;
                dfs(i, j, n_com);
            }

    printf("%d\n", 3*n_dot-2*n_com);
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            if (grid[i][j] > 0) printf("B %d %d\n", i, j);

    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            if (grid[i][j] > 0) {
                print(i, j, 1);
            }
    return 0;
}
