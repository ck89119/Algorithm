/*
ID: ck891191
PROG: stall4
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

const int INF=(1<<30);
const double PI=acos(-1.0);
const double EPS=1e-11;
const int MAXM = 2 * (40000 + 400) + 5;
const int MAXN = 400 + 5;

struct Edge {
    int v, f, next;
}edge[MAXM];
int edge_size;
int head[MAXN];
int level[MAXN];
int n,m;

int add_edge(int a, int b, int c, int c_inv) {
    int i = edge_size;
    edge[i].v = b;
    edge[i].f = c;
    edge[i].next = head[a];
    head[a] = i;

    edge[i^1].v = a;
    edge[i^1].f = c_inv;
    edge[i^1].next = head[b];
    head[b] = (i ^ 1);

    edge_size += 2;
    return 0;
}

int bfs(int src, int sink) {
    queue<int> q;
    while (!q.empty()) q.pop();
    CL(level, 0);
    q.push(src);
    level[src] = 1;
    while (!q.empty()) {
        int t;
        t = q.front(); q.pop();
        if (t ==  sink) return 1;
        for (int k = head[t]; k != -1; k =edge[k].next) {
            int v = edge[k].v;
            if (!level[v] && edge[k].f) {
                q.push(v);
                level[v] = level[t] + 1;
            }
        }
    }
    return 0;
}

int dfs(int now, int sink, int maxf) {
    int ans = 0;
    if (now == sink) return maxf;
    for (int k = head[now]; k != -1; k = edge[k].next) {
        int v = edge[k].v;
        if (level[v] == level[now] + 1 && edge[k].f){
            int f;
            f = dfs(v, sink, min(maxf-ans, edge[k].f));
            edge[k].f -= f;
            edge[k^1].f += f;
            ans += f;
            if (ans == maxf) return ans;
        }
    }
    return ans;
}

int dinic(int src, int sink) {
    int max_flow = 0;
    while (bfs(src, sink)) max_flow += dfs(src, sink, INF);
    return max_flow;
}

int main() {
    int i, j;
    freopen("stall4.in","r",stdin);
    freopen("stall4.out","w",stdout);
    scanf("%d%d", &n, &m);
    CL(head, -1); edge_size = 0;
    for (i = 1; i <= n; i ++) add_edge(0, i, 1, 0);
    for (i = n+1; i <= n+m; i ++) add_edge(i, n+m+1, 1, 0);
    for (i = 1; i <= n; i ++) {
        int s, t;
        scanf("%d", &s);
        for (j = 0; j < s; j ++)  {
            scanf("%d", &t);
            add_edge(i, n+t, 1, 0);
        }
    }
    printf("%d\n", dinic(0, n+m+1));
    return 0;
}
