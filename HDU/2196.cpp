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
//struct Edge {
//    int to;
//    int w;
//    int next;
//};
//int head[];
const int MAXN=99999;
const int INF=(1<<30);
const double PI=acos(-1.0);
const double EPS=1e-11;

struct Edge {
    int to;
    int w;
    int sum;
    int next;
};
Edge edge[2*10005];
int head[10005];
int n;
int dp[10005];

int input() {
    int i, k;

    CL(head, -1); k = 0;
    for (i = 2; i <= n; i++) {
        int v, w;
        scanf("%d%d", &v, &w);
        edge[k].to = v;
        edge[k].w = w;
        edge[k].sum = 0;
        edge[k].next = head[i];
        head[i] = k;
        k++;

        edge[k].to = i;
        edge[k].w = w;
        edge[k].sum = 0;
        edge[k].next = head[v];
        head[v] = k;
        k++;
    }
    return 0;
}

int rec1(int k, int pre) {
    int i, maxH;
    if (dp[k] != -1) return dp[k];
    maxH = 0;
    for (i = head[k]; i != -1; i = edge[i].next) {
        int v = edge[i].to;
        if (v == pre) continue;
        maxH = max(maxH, rec1(v, k) + edge[i].w);
        edge[i].sum = dp[v] + edge[i].w;
    }
    //dump(k)dump(maxH)
    return dp[k] = maxH;
}

int rec2(int k, int pre) {
    int i;
    int maxH;

    maxH = 0;
    for (i = head[pre]; i != -1; i = edge[i].next) {
        int v = edge[i].to;
        if (v == k) continue;
        maxH = max(maxH, edge[i].sum);
    }
    for (i = head[k]; i != -1; i = edge[i].next) {
        int v = edge[i].to;
        if (v != pre) continue;
        edge[i].sum = maxH + edge[i].w;
        dp[k] = max(dp[k], edge[i].sum);
    }

    for (i = head[k]; i != -1; i = edge[i].next) {
        int v = edge[i].to;
        if (v == pre) continue;
        rec2(v, k);
    }

    return 0;
}

int solve() {
    int i;
    CL(dp, -1);
    rec1(1, -1);

    for (i = head[1]; i != -1; i = edge[i].next) {
        int v = edge[i].to;
        rec2(v, 1);
    }
    for (i = 1; i <= n; i++)
        printf("%d\n", dp[i]);
    return 0;
}

int main(){
    while (scanf("%d", &n) != EOF) {
        input();
        solve();
    }
    return 0;
}
