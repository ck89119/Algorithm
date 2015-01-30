/*
ID: ck891191
PROG: ditch
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
const int MAXN = 200 + 5;
const int INF=(1<<30);
const double PI=acos(-1.0);
const double EPS=1e-11;
const int MAXM = 200 + 5;
struct Edge {
    int v, f, next;
}edge[MAXM];
int edge_size;
int head[MAXN];
int level[MAXN];
int m, n;

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
    int flag;
    queue<int> q;
    while (!q.empty()) q.pop();
    CL(level, 0);
    q.push(src);
    level[src] = 1;
    flag = 0;
    while (!q.empty()) {
        int t, k;
        t = q.front(); q.pop();
        if (t == sink) {
            flag =1 ;
            break;
        }
        for (k = head[t]; k != -1; k = edge[k].next) {
            int v = edge[k].v;
            if (!level[v] && edge[k].f){
                q.push(v);
                level[v] = level[t] + 1;
            }
        }
    }
    return flag;
}

int dfs(int now, int sink, int maxf) {
    int ans = 0;
    if (now == sink) return maxf;

    int k;
    for (k = head[now]; k != -1; k = edge[k].next) {
        int v = edge[k].v;
        if (level[v] == level[now] + 1 && edge[k].f){
            int f;
            f = dfs(v, sink, min(edge[k].f, maxf-ans));
            edge[k].f -= f;
            edge[k^1].f += f;
            ans += f;
            if (ans == maxf) return ans;
        }
    }
    return ans;
}

int Dinic(int src, int sink) {
    int max_flow = 0;
    while (bfs(src, sink)) max_flow += dfs(src, sink, INF);
    return max_flow;
}

int main() {
    int i;
    freopen("ditch.in","r",stdin);
    freopen("ditch.out","w",stdout);
    scanf("%d%d", &m, &n);
    CL(head, -1); edge_size = 0;
    for (i = 0; i < m; i ++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add_edge(a, b, c, 0);
    }
    printf("%d\n",Dinic(1, n));
    return 0;
}
