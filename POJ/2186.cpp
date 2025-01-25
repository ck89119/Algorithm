/*
ID: ck89119
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
#define CLR(a,x) memset(a,x,sizeof(a))
#define MP(A,B) make_pair(A,B)
#define PAU system("pause");
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(n) (n^(n-1))&n
#define fin freopen("in.txt","r",stdin);
#define fout freopen("out.txt","w",stdout);
//ifstream fin("");
//ofstream fout("");

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out (vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int MAXN=10000+5;
const int MAXM=50000+5;
const int INF=(1<<30);
const double PI=acos(-1.0);
const double EPS=1e-11;

struct EdgeNode {
    int to;
    int next;
}edges[MAXM];
int head[MAXN];
int low[MAXN], dfn[MAXN], index, cnt, edgeSize, inStack[MAXN];
int belong[MAXN], size[MAXN];
stack<int> s;
int n, m;

int init() {
    CLR(head, -1);
    index = cnt = edgeSize = 0;
    CLR(low, -1);
    CLR(dfn, -1);
    CLR(inStack, 0);
    while (!s.empty()) s.pop();
    CLR(belong, -1);
    CLR(size, 0);
    return 0;
}

int addEdge(int u, int v) {
    edges[edgeSize].to = v;
    edges[edgeSize].next = head[u];
    head[u] = edgeSize++;
    return 0;
}

int input() {
    int i;
    cin >> n >> m;
    for (i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
    }
    return 0;
}

int tarjan(int u) {
    int i, v;
    low[u] = dfn[u] = index++;
    s.push(u); inStack[u] = 1;

    for (i = head[u]; i != -1; i = edges[i].next) {
        v = edges[i].to;
        if (dfn[v] == -1) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (inStack[v])
            low[u] = min(low[u], dfn[v]);
    }

    if (dfn[u] == low[u]) {
        cnt++;
        do {
            v = s.top(); s.pop();
            inStack[v] = 0;
            belong[v] = cnt;
            size[cnt]++;
        } while (u != v);
    }
    return 0;
}

//int dfs(int u) {
//    inStack[u] = 1;
//
//    set<int>::iterator i;
//    for (i = head2[u].begin(); i != head2[u].end(); i++) {
//        int v = *i;
//        if (!inStack[v]) dfs(v);
//    }
//    return 0;
//}

int solve() {
    int i, j;
    int outDeg[MAXN];
    int res;
    for (i = 1; i <= n; i++)
        if (dfn[i] == -1) tarjan(i);
    //dump("####")
    CLR(outDeg, 0);
    for (i = 1; i <= n; i++)
        for (j = head[i]; j != -1; j = edges[j].next) {
            int u = belong[i];
            int v = belong[edges[j].to];
            if (u != v) outDeg[u]++;
        }
    int total, k;
    total = 0; k = -1;
    for (i = 1; i <= cnt; i++)
        if (outDeg[i] == 0) {
            total++;
            k = i;
        }
    //dump(total) dump(k)
    res = (total>1)?0:size[k];
    cout << res << endl;
    return 0;
}

int main() {
    init();
    input();
    solve();
    return 0;
}
