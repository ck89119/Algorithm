/*
ID: ck89119
PROG: twofive
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
#define PB(A) push_back(A)
#define PAU system("pause");
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(n) (n^(n-1))&n
#define fin freopen("twofive.in","r",stdin);
#define fout freopen("twofive.out","w",stdout);
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
char str[30];
int f[6][6][6][6][6];
int used[26];
int mx[6], my[6], ii[6];

int count(int a, int b, int c, int d, int e, int ch) {
    int &now = f[a][b][c][d][e];
    if (now) return now;
    if (used[ch]) return (now = count(a, b, c, d, e, ch+1));

    if (a < 5 && mx[0] < ch && my[a] < ch) now += count(a+1, b, c, d, e, ch+1);
    if (b < a && mx[1] < ch && my[b] < ch) now += count(a, b+1, c, d, e, ch+1);
    if (c < b && mx[2] < ch && my[c] < ch) now += count(a, b, c+1, d, e, ch+1);
    if (d < c && mx[3] < ch && my[d] < ch) now += count(a, b, c, d+1, e, ch+1);
    if (e < d && mx[4] < ch && my[e] < ch) now += count(a, b, c, d, e+1, ch+1);

    return now;
}

int solve_N() {
    int i, j;
    CLR(mx, -1); CLR(my, -1); CLR(used, 0);

    for (i = 0; i < 25; ++i) {
        ii[i/5]++;
        for (j = 0; j < 25; ++j)
            if (!used[j] && mx[i/5] < j && my[i%5] < j) {
                int sum;
                mx[i/5] = my[i%5] = j;
                CLR(f, 0);
                f[5][5][5][5][5] = 1;
                used[j] = 1;
                sum = count(ii[0], ii[1], ii[2], ii[3], ii[4], 0);
                if (n <= sum) {
                    break;
                }
                else n -= sum;
                used[j] = 0;
            }
        str[i] = 'A' + j;
        used[j] = 1;
    }
    cout << str << endl;
    return 0;
}

int solve_W() {
    int i, j;
    int ans = 0;
    CLR(mx, 0); CLR(my, 0); CLR(used, 0);
    for (i = 0; i < 25; ++i) {
        ii[i/5]++;
        for (j = 0; j < str[i]-'A'; ++j)
            if (!used[j] && mx[i/5] < j && my[i%5] < j) {
                mx[i/5] = my[i%5] = j;
                CLR(f, 0);
                f[5][5][5][5][5] = 1;
                used[j] = 1;
                ans += count(ii[0], ii[1], ii[2], ii[3], ii[4], 0);
                used[j] = 0;
            }
        used[j] = 1;
        mx[i/5] = my[i%5] = j;
    }
    cout << ans+1 << endl;
    return 0;
}

int main() {
    ios :: sync_with_stdio(false);
	cout << fixed << setprecision(16);

    fin fout
    char op;
    cin >> op;
    if (op == 'N') {
        cin >> n;
        solve_N();
    }
    else {
        cin >> str;
        solve_W();
    }
    return 0;
}





//char op, str[30];
//int n;
//int grid[10][10], ans[10][10], target[10][10];
//int get_ans;
//int dx[4] = {0, 1, 0, -1};
//int dy[4] = {1, 0, -1, 0};
//int vis[30];
//int cnt;
//
//int check() {
//    int i, j;
//    for (i = 1; i <= 5; ++i)
//        for (j = 1; j <= 5; ++j)
//            if (grid[i][j] != target[i][j]) return 0;
//    return 1;
//}
//
//int dfs(int x, int y, int type) {
//    if (get_ans) return 0;
//    if (x == 5 && y == 5) {
//        cnt++;
//        if (type == 1 && cnt == n) {
//            memcpy(ans, grid, sizeof(grid));
//            get_ans = 1;
//        }
//        if (type == 2 && check()) {
//            get_ans = 1;
//        }
//        return 0;
//    }
//
//    int i;
//    int mini = -1;
//    if (x > 1) mini = max(mini, grid[x-1][y]);
//    if (y > 1) mini = max(mini, grid[x][y-1]);
//    int maxi = 25 - (6-x)*(6-y) + 1;
//    for (i = mini+1; i <= maxi; ++i)
//        if (!vis[i]) {
//            grid[x][y] = i;
//            vis[i] = 1;
//            dfs(x+y/5, y%5+1, type);
//            grid[x][y] = 0;
//            vis[i] = 0;
//        }
//    return 0;
//}
//
//int output1() {
//    int i, j;
//    for (i = 1; i <= 5; ++i)
//        for (j = 1; j <= 5; ++j)
//            printf("%c", 'A'+ans[i][j]-1);
//    printf("\n");
//    return 0;
//}
//
//int solve1() {
//    CLR(grid, 0);
//    CLR(vis, 0);
//    grid[1][1] = 1; vis[1] = 1;
//    grid[5][5] = 25; vis[25] = 1;
//    cnt = 0; get_ans = 0;
//    dfs(1, 2, 1);
//    output1();
//    return 0;
//}
//
//int output2() {
//    printf("%d\n", cnt);
//    return 0;
//}
//
//int solve2() {
//    int i;
//    for (i = 0; i < 25; ++i)
//        target[i/5+1][i%5+1] = str[i] - 'A' + 1;
//    CLR(grid, 0);
//    CLR(vis, 0);
//    grid[1][1] = 1; vis[1] = 1;
//    grid[5][5] = 25; vis[25] = 1;
//    cnt = 0; get_ans = 0;
//    dfs(1, 2, 2);
//    output2();
//    return 0;
//}
//
//int main() {
//    fin fout
//    scanf("%c", &op);
//    if (op == 'N') {
//        scanf("%d", &n);
//        solve1();
//    }
//    else {
//        scanf("%s", str);
//        solve2();
//    }
//    return 0;
//}
