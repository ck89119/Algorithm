/*
ID: ck891191
PROG: cowcycle
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
int f, r, f1, r1, f2, r2;
int ans1[15], ans2[15], res1[15], res2[15];
double radio[55];
double EX, DX, resDX;

int input() {
    freopen("cowcycle.in","r",stdin);
    freopen("cowcycle.out","w",stdout);
    scanf("%d%d%d%d%d%d", &f, &r, &f1, &f2, &r1, &r2);
    return 0;
}

int dfs2(int k, int minr) {
    if (k == r) {
        if (3*ans1[0]*ans2[0] > ans1[f-1]*ans2[r-1]) return 0;
        int i, j;
        EX = 0.0; DX = 0.0;

        int t = 0;
        for (i = 0; i < f; i ++)
            for (j = 0; j < r; j ++)
                radio[t++] = (double)ans1[i]/ans2[j];
        sort(radio, radio+t);
        for (i = 0; i < t-1; i ++) {
            double tmp = radio[i+1] - radio[i];
            EX += tmp;
            DX += tmp * tmp;
        }
        EX /= (t - 1);
        DX = DX / (t - 1) - EX * EX;

        if (DX < resDX) {
            resDX = DX;
            for (i = 0; i < f; i ++) res1[i] = ans1[i];
            for (i = 0; i < r; i ++) res2[i] = ans2[i];
        }
        return 0;
    }
    if (minr > r2) return 0;

    //dfs2(k, minr+1);
    int i;
    for (i = minr; i <= r2; i ++) {
        ans2[k] = i;
        dfs2(k+1, i+1);
    }
    return 0;
}

int dfs1(int k, int minf) {
    if (k == f) {
        //for (int i = 0; i < f; i ++) printf("%d ",ans1[i]);printf("\n");
        dfs2(0, r1);
        return 0;
    }
    if (minf > f2) return 0;

    //dfs1(k, minf+1);
    int i;
    for (i = minf; i <= f2; i ++) {
        ans1[k] = i;
        dfs1(k+1, i+1);
    }
    return 0;
}

int solve() {
    int i;
    resDX = 999999999999.0;
    dfs1(0, f1);
    //dump("#########")
    for (i = 0; i < f-1; i ++) printf("%d ", res1[i]);
    printf("%d\n", res1[f-1]);
    for (i = 0; i < r-1; i ++) printf("%d ", res2[i]);
    printf("%d\n", res2[r-1]);
    return 0;
}

int main() {
    input();
    solve();
    return 0;
}
