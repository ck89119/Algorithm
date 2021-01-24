/*
ID: ck89119
PROG: starry
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
#define fin freopen("starry.in","r",stdin);
#define fout freopen("starry.out","w",stdout);
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


int check1(int w, int h, int a[105][105], int b[105][105]) {
    int i, j;
    int flag1, flag2; flag1 = flag2 = 1;
    for (i = 0; i < h && flag1; i++)
        for (j = 0; j < w && flag1; j++)
            if (a[i][j] != b[i][j]) flag1 = 0;
    if (flag1) return flag1;

    for (i = 0; i < h && flag2; i++)
        for (j = 0; j < w && flag2; j++)
            if (a[i][j] != b[i][w-1-j]) flag2 = 0;
    return flag2;
}

int check2(int w, int h, int a[105][105], int b[105][105]) {
    int i, j;
    int flag1, flag2; flag1 = flag2 = 1;
    for (i = 0; i < h && flag1; i++)
        for (j = 0; j < w && flag1; j++)
            if (a[i][j] != b[j][h-1-i]) flag1 = 0;
    if (flag1) return flag1;

    for (i = 0; i < h && flag2; i++)
        for (j = 0; j < w && flag2; j++)
            if (a[i][j] != b[j][i]) flag2 = 0;
    return flag2;
}

int check3(int w, int h, int a[105][105], int b[105][105]) {
    int i, j;
    int flag1, flag2; flag1 = flag2 = 1;
    for (i = 0; i < h && flag1; i++)
        for (j = 0; j < w && flag1; j++)
            if (a[i][j] != b[h-1-i][w-1-j]) flag1 = 0;
    if (flag1) return flag1;

    for (i = 0; i < h && flag2; i++)
        for (j = 0; j < w && flag2; j++)
            if (a[i][j] != b[h-1-i][j]) flag2 = 0;
    return flag2;
}

int check4(int w, int h, int a[105][105], int b[105][105]) {
    int i, j;
    int flag1, flag2; flag1 = flag2 = 1;
    for (i = 0; i < h && flag1; i++)
        for (j = 0; j < w && flag1; j++)
            if (a[i][j] != b[w-1-j][i]) flag1 = 0;
    if (flag1) return flag1;

    for (i = 0; i < h && flag2; i++)
        for (j = 0; j < w && flag2; j++)
            if (a[i][j] != b[w-1-j][h-1-i]) flag2 = 0;
    return flag2;
}

struct Pat {
    int w, h;
    int pat[105][105];
    bool operator == (Pat &p) {
        int ans = 0;
        if ((p.w == w && p.h == h) ||(p.w == h && p.h == w)) {
            if (p.w == w && p.h == h) {
                ans = check1(w, h, pat, p.pat) || check3(w, h, pat, p.pat);
                if (ans) return ans;
            }
            if (p.w == h && p.h == w) {
                ans = (check2(w, h, pat, p.pat) || check4(w, h, pat, p.pat));
                if (ans) return ans;
            }
        }
        return ans;
    }
};
vector<Pat> pattern;
int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int w, h;
char grid[105][105];

int inGrid(int y, int x) {
    if (x >= 0 && x < w && y >= 0 && y < h) return 1;
    else return 0;
}

int dfs(int y, int x, int &minx, int &maxx, int &miny, int &maxy) {
    int k;
    grid[y][x] = '2';
    minx = min(minx, x); maxx = max(maxx, x);
    miny = min(miny, y); maxy = max(maxy, y);
    for (k = 0; k < 8; k++) {
        int tx = x + dx[k];
        int ty = y + dy[k];
        if (inGrid(ty, tx) && grid[ty][tx] == '1')
            dfs(ty, tx, minx, maxx, miny, maxy);
    }
    return 0;
}

int solve() {
    int i, j, k, x, y;
    int minx, maxx, miny, maxy;
    Pat tmp;
    for (i = 0; i < h; i++)
        for (j = 0; j < w; j++)
            if (grid[i][j] == '1') {
                minx = miny = INF;
                maxx = maxy = -1;
                dfs(i, j, minx, maxx, miny, maxy);
                tmp.w = maxx - minx + 1;
                tmp.h = maxy - miny + 1;
                for (y = miny; y <= maxy; y++)
                    for (x = minx; x <= maxx; x++)
                        tmp.pat[y-miny][x-minx] = (grid[y][x] == '2');

                for (k = 0; k < pattern.size(); k++)
                    if (pattern[k] == tmp) break;

                if (k == pattern.size()) pattern.PB(tmp);
                for (y = miny; y <= maxy; y++)
                    for (x = minx; x <= maxx; x++)
                        if (grid[y][x] == '2') grid[y][x] = 'a' + k;
            }
    return 0;
}

int out() {
    int i, j;
    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++)
            cout << grid[i][j];
        cout << endl;
    }
    return 0;
}

int input() {
    int i, j;
    cin >> w >> h;
    for (i = 0 ; i < h; i++) {
        getchar();
        for (j = 0; j < w; j++)
            cin >> grid[i][j];
    }
    return 0;
}

int main() {
    fin fout
    input();
    solve();
    out();
    return 0;
}
