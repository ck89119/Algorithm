/*
ID: ck89119
PROG: charrec
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
#define CLR(a,x) memset(a,x,sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0x80
#define MP(A,B) make_pair(A,B)
#define PB(A) push_back(A)
#define PAU system("pause");
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(n) (n^(n-1))&n
#define fin freopen("charrec.in","r",stdin);
#define fout freopen("charrec.out","w",stdout);
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

char font[27][20][25];
char image[1205][25];
int n;
int dif[1205][27][25];
int cost[1205][3], ans[1205][3];
int f[1205], p[1205], ch[1205];

int input() {
    int i, j, k, l;
    freopen("font.in", "r", stdin);
    cin >> n;
    for (k = 0; k < 27; ++k)
        for (i = 0; i < 20; ++i) {
            scanf("%s", font[k][i]);
            //dump(font[k][i])
        }

    fin fout
    cin >> n;
    for (i = 0; i < n; ++i)
        scanf("%s", image[i]);

    CLR(dif, 0);
    for (i = 0; i < n; ++i)
        for (j = 0; j < 27; ++j)
            for (k = 0; k < 20; ++k)
                for (l = 0; l < 20; ++l)
                    dif[i][j][k] += (image[i][l] != font[j][k][l]);
    return 0;
}

int dp() {
    int i;
    CLR(f, 0x3f); CLR(ch, -1);
    f[0] = 0;
    for (i = 0; i <= n; ++i) {
        if (i - 19 >= 0) {
            if (f[i] > f[i-19] + cost[i-19][0]) {
                f[i] = f[i-19] + cost[i-19][0];
                p[i] = i - 19;
                ch[i] = ans[i-19][0];
            }
        }

        if (i - 20 >= 0) {
            if (f[i] > f[i-20] + cost[i-20][1]) {
                f[i] = f[i-20] + cost[i-20][1];
                p[i] = i - 20;
                ch[i] = ans[i-20][1];
            }
        }

        if (i - 21 >= 0) {
            if (f[i] > f[i-21] + cost[i-21][2]) {
                f[i] = f[i-21] + cost[i-21][2];
                p[i] = i - 21;
                ch[i] = ans[i-21][2];
            }
        }
    }

    return 0;
}

int solve() {
    int i, j, k;
    int t;

    CLR(cost, 0x3f);
    for (i = 0; i + 18 < n; ++i) {
        if (i + 18 < n) {
            for (j = 0; j < 27; ++j) {
                t = 0;
                for (k = 0; k < 19; ++k)
                    t += dif[i+k][j][k];
                if (t < cost[i][0]) {
                    cost[i][0] = t;
                    ans[i][0] = j;
                }
                for (k = 18; k >= 0; --k) {
                    t -= dif[i+k][j][k];
                    t += dif[i+k][j][k+1];
                    if (t < cost[i][0]) {
                        cost[i][0] = t;
                        ans[i][0] = j;
                    }
                }
            }
        }

        if (i + 19 < n) {
            for (j = 0; j < 27; ++j) {
                t = 0;
                for (k = 0; k < 20; ++k)
                    t += dif[i+k][j][k];
                if (t < cost[i][1]) {
                    cost[i][1] = t;
                    ans[i][1] = j;
                }
            }
        }

        if (i + 20 < n) {
            for (j = 0; j < 27; ++j) {
                t = 0;
                for (k = 0; k < 20; ++k)
                    t += dif[i+k][j][k];
                if (t < cost[i][2]) {
                    cost[i][2] = t;
                    ans[i][2] = j;
                }
                for (k = 19; k >= 0; --k) {
                    t -= dif[i+k][j][k];
                    t += dif[i+k+1][j][k];
                    if (t < cost[i][2]) {
                        cost[i][2] = t;
                        ans[i][2] = j;
                    }
                }
            }
        }
    }

    dp();
    return 0;
}

int output(int index) {
    if (index) output(p[index]);
    //dump(index)
    if (ch[index] == -1) return 0;
    if (ch[index]) printf("%c", 'a' + ch[index] - 1);
    else printf(" ");
    return 0;
}

int main() {
    input();
    solve();
    output(n);
    printf("\n");
    return 0;
}
