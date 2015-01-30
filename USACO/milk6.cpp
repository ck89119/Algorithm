/*
ID: ck89119
PROG: milk6
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
#define fin freopen("in.txt","r",stdin);
#define fout freopen("out.txt","w",stdout);
//ifstream fin("");
//ofstream fout("");
#define LL long long

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out (vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int MAXN=35;
const int MAXM=1005;
const LL INF=0x7f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;

struct Edge {
    int u, v;
    LL f;
    //int next;
}edge[MAXM*2+5];
LL cap[MAXN][MAXN], flow[MAXN][MAXN], flowb[MAXN][MAXN];
//int head[MAXN];
//int edgeSize;
int level[MAXN];
int src, sink;
LL maxFlow;
int n, m;

int addEdge(int i,int u, int v, LL f) {
    edge[i].u = u;
    edge[i].v = v;
    edge[i].f = f * 1001 + 1;
    cap[u][v] += edge[i].f;
    //edge[edgeSize].next = head[u];
    //head[u] = edgeSize++;
    return 0;
}

int makeLevel() {
    queue<int> q;
    int i;
    CLR(level, -1);
    level[src] = 0; q.push(src);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u ==  sink) return 1;
        for (i = 1; i <= n; i++) {
            int v = i;
            if (level[v] == -1 && cap[u][v] > flow[u][v]) {
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
    }
    return 0;
}

LL dfs(int u, LL delta) {
    LL res = 0;
    int i;
    if (u == sink) return delta;

    for (i = 1; delta && i <= n; i++) {
        int v = i;
        if (delta && level[v] == level[u] + 1) {
            LL f = dfs(v, min(delta, cap[u][v]-flow[u][v]));
            flow[u][v] += f;
            flow[v][u] -= f;
            delta -= f;
            res += f;
        }
    }
    return res;
}

int fBak() {
    int i, j;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            flowb[i][j] = flow[i][j];
    return 0;
}

int fRec() {
    int i, j;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            flow[i][j] = flowb[i][j];
    return 0;
}

LL Dinic() {
    CLR(flow, 0); src = 1; sink = n;
    LL f = 0;
    while (makeLevel()) f += dfs(src, INF);
    return f;
}

int input() {
    int i;
    scanf("%d%d", &n, &m);
    CLR(cap, 0);
    for (i = 0; i < m; i++) {
        int u, v;
        LL f;
        scanf("%d%d%lld", &u, &v, &f);
        addEdge(i, u, v, f);
    }
    return 0;
}

int outEdge() {
    int i;
    LL k = 0;
    for (i = 0; i < m; i++) {
        int u, v;
        LL f, mf;
        u = edge[i].u;
        v = edge[i].v;
        f = edge[i].f;
        if (flow[u][v] == cap[u][v]) {
            //dump(i)
            fBak();
            cap[u][v] -= f;
            mf = Dinic();
            if (mf + f == maxFlow) {
                printf("%d\n", i+1);
                k++;
                if (k == maxFlow%1001) return 0;
            }

            fRec();
            cap[u][v] += f;
        }

    }
    return 0;
}

int main() {
    freopen("milk6.in","r",stdin);
    freopen("milk6.out","w",stdout);
    input();
    maxFlow = Dinic();
    printf("%lld %lld\n", maxFlow/1001, maxFlow%1001);
    outEdge();
    return 0;
}
