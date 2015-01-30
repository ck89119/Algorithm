/*
ID: ck89119
PROG: telecow
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
#define fin freopen("telecow.in","r",stdin);
#define fout freopen("telecow.out","w",stdout);
//ifstream fin("");
//ofstream fout("");
#define LL long long

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out (vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int MAXN=100;
const int MAXM=600;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;

struct Edge {
    int u, v;
    int f;
    int next;
};
Edge edge[MAXM*4+5];
int edge_size;
int head[MAXN*2+5];
int level[MAXN*2+5];
int n, m, c1, c2;
int from[MAXM+5], to[MAXM+5];
int ans;
int down[MAXN+5];

int add_edge(int u, int v, int f) {
    edge[edge_size].u = u;
    edge[edge_size].v = v;
    edge[edge_size].f = f;
    edge[edge_size].next = head[u];
    head[u] = edge_size++;
    return 0;
}

int input() {
    cin >> n >> m >> c1 >> c2;
    int i;
    for (i = 0; i < m; ++i)
        cin >> from[i] >> to[i];
    return 0;
}

int build() {
    int i;
    CLR(head, -1);
    edge_size = 0;
    for (i = 0; i < m; ++i) {
        add_edge(from[i]+n, to[i], INF);
        add_edge(to[i], from[i]+n, 0);
        add_edge(to[i]+n, from[i], INF);
        add_edge(from[i], to[i]+n, 0);
    }

    for (i = 1; i <= n; ++i)
        if (!down[i]) {
            if (i == c1 || i == c2) {
                add_edge(i, n+i, INF);
                add_edge(n+i, i, 0);
            }
            else {
                add_edge(i, n+i, 1);
                add_edge(n+i, i, 0);
            }
        }
    return 0;
}

int bfs(int src, int sink) {
    queue<int> q;
    int flag;
    while (!q.empty()) q.pop();
    CLR(level, 0);
    q.push(src);
    level[src] = 1;
    flag = 0;
    while (!q.empty()) {
        int t, k;
        t = q.front(); q.pop();
        if (t == sink) {
            flag = 1;
            break;
        }
        for (k = head[t]; k != -1; k = edge[k].next)
            if (!level[edge[k].v] && edge[k].f) {
                q.push(edge[k].v);
                level[edge[k].v] = level[t] + 1;
            }
    }
    return flag;
}

int dfs(int now, int sink, int maxf) {
    if (now == sink) return maxf;
    int ans = 0;
    int k;
    for (k = head[now]; k != -1; k = edge[k].next)
        if (edge[k].f && level[edge[k].v] == level[now] + 1) {
            int flow;
            flow = dfs(edge[k].v, sink, min(edge[k].f, maxf - ans));
            edge[k].f -= flow;
            edge[k^1].f += flow;
            ans += flow;
            if (ans == maxf) return ans;
        }
    return ans;
}

int Dinic(int src, int sink) {
    int max_flow;
    max_flow = 0;
    while (bfs(src, sink)) max_flow += dfs(src, sink, INF);
    return max_flow;
}

int solve() {
    build();
    ans = Dinic(c1, c2);
    cout << ans << endl;
    CLR(down, 0);
    int i, cnt = 0;
    for (i = 1; i <= n; ++i) {
        if (i == c1 || i == c2) continue;
        down[i] = 1;
        build();
        if (Dinic(c1, c2) + 1 == ans - cnt) {
            cnt++;
            if (cnt == ans) {cout << i << endl; break;}
            else cout << i << ' ';
        }
        else down[i] = 0;
    }
    return 0;
}

int main() {
    fin fout
    input();
    solve();
    return 0;
}
