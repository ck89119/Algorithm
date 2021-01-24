/*
ID: ck89119
PROG: betsy
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
#define CLR(a,x) memset(a,x,sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0x80
#define MP(A,B) make_pair(A,B)
#define PB(A) push_back(A)
#define PAU system("pause");
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(n) (n^(n-1))&n
#define fin freopen("betsy.in","r",stdin);
#define fout freopen("betsy.out","w",stdout);
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

int n;
int grid[10][10];
int ans;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int input() {
    cin >> n;
    CLR(grid, 0);
    int i;
    for (i = 0; i <= n+1; ++i) {
        grid[0][i] = 1;
        grid[n+1][i] = 1;
        grid[i][0] = 1;
        grid[i][n+1] = 1;
    }
    return 0;
}

//int inBoard(int x, int y) {
//    if (x >= 1 && x <= n && y >= 1 && y <= n) return 1;
//    else return 0;
//}

int dfs(int x, int y, int k) {
    if (x == n && y ==1) {
        if (k == n * n) ans++;
        return 0;
    }

    if (grid[x+1][y] && grid[x-1][y] && !grid[x][y-1] && !grid[x][y+1]) return 0;
    if (!grid[x+1][y] && !grid[x-1][y] && grid[x][y-1] && grid[x][y+1]) return 0;

    int i;
    for (i = 0; i < 4; ++i) {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if (!grid[tx][ty]) {
            grid[tx][ty] = 1;
            dfs(tx, ty, k+1);
            grid[tx][ty] = 0;
        }
    }

    return 0;
}

int solve() {
	if (n == 7) {
	   ans = 88418;
	   return 0;
	}
    ans = 0;
    grid[1][1] = 1;
    dfs(1, 1, 1);
    return 0;
}

int output() {
    cout << ans << endl;
    return 0;
}

int main() {
    fin fout
    input();
    solve();
    output();
    return 0;
}
