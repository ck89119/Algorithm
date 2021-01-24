/*
ID: ck89119
PROG: snail
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
#define dump(x) cout <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl;
#define FR(i,a,b) for(int i=(a);i<(b);++i)//[a,b)
#define CLR(a,x) memset(a,x,sizeof(a))
#define MP(A,B) make_pair(A,B)
#define PB(A) push_back(A)
#define PAU system("pause");
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(n) (n^(n-1))&n
#define fin freopen("snail.in","r",stdin);
#define fout freopen("snail.out","w",stdout);
//ifstream fin("");
//ofstream fout("");
#define LL long long

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out (vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int MAXN=99999;
const int MAXM=9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int n, m;
int grid[125][125], grid_tmp[125][125];
int res;

int dfs(int y, int x, int dir, int cnt) {
    //dump(y)dump(x)dump(dir)
    grid[y][x] = 2; //dump(y) dump(x)
    cnt++;

    while (grid[y+dy[dir]][x+dx[dir]] == 0) {
        y = y+dy[dir];
        x = x+dx[dir];
        grid[y][x] = 2; //dump(y) dump(x)
        cnt++;
    }

    if (grid[y+dy[dir]][x+dx[dir]] == 1) {
        int i;
        for (i = 1; i <= 3; ++i) {
            int d = (dir + i) % 4;
            if (grid[y+dy[d]][x+dx[d]] == 0) {
                int tmp[125][125];
                memcpy(tmp, grid, sizeof(grid));
//                for (int k = 0; k <= n+1; k++)
//                    out(grid[k], n+2);
//                dump(cnt)
                dfs(y+dy[d], x+dx[d], d, cnt);
                memcpy(grid, tmp, sizeof(tmp));
            }
        }
    }

    if (grid[y+dy[dir]][x+dx[dir]] == 2) {
        //dump(cnt)
        res = max(res, cnt);
    }

    res =  max(res, cnt);
    return 0;
}

int solve() {
    res = 0;
    memcpy(grid_tmp, grid, sizeof(grid));
    dfs(1, 1, 0, 0);
    memcpy(grid, grid_tmp, sizeof(grid_tmp));
    dfs(1, 1, 3, 0);
    cout << res << endl;
}


int input() {
    int i, j;
    string s;
    cin >> n >> m;
    CLR(grid, 0);
    for (i = 0; i < m; i++) {
        int x, y;
        cin >> s;
        x = s[0] - 'A' + 1;
        j = 1; y = 0;
        while (j < s.size())
            y = y * 10 + s[j++] - '0';
        //dump(x)
        //dump(y)
        grid[y][x] = 1;
    }
    for (i = 0; i <= n+1; i++) {grid[i][0] = 1; grid[i][n+1] = 1;}
    for (j = 0; j <= n+1; j++) {grid[0][j] = 1; grid[n+1][j] = 1;}
//    for (i = 0; i <= n+1; i++)
//        out(grid[i], n+2);
    return 0;
}

int main() {
    fin fout
    input();
    solve();
    return 0;
}
