/*
ID: ck89119
PROG: schlnet
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
#define fin freopen("schlnet.in","r",stdin);
#define fout freopen("schlnet.out","w",stdout);
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

struct EdgeNode {
    int to;
    int w;
    int next;
};
EdgeNode edge[10005];
int head[105], edge_size;
int n;
int dfn[105], lowlink[105], ind;
int inStack[105];
stack<int> s;
int scc[105], scc_size, indeg[105], outdeg[105];

int add_edge(int u, int v) {
    edge[edge_size].to = v;
    edge[edge_size].w = 1;
    edge[edge_size].next = head[u];
    head[u] = edge_size++;
    return 0;
}

int input() {
    int i;
    cin >> n;
    edge_size = 0; CLR(head, -1);
    for (i = 1; i <= n; ++i) {
        int k;
        while (cin >> k, k) {
            add_edge(i, k);
        }
    }
    return 0;
}

int tarjan(int v) {
    dfn[v] = lowlink[v] = ++ind;
    s.push(v); inStack[v] = 1;
    int i;
    for (i = head[v]; i != -1; i = edge[i].next) {
        int u = edge[i].to;
        if (!dfn[u]) {
            tarjan(u);
            lowlink[v] = min(lowlink[v], lowlink[u]);
        }
        else if (inStack[u]) {
                 lowlink[v] = min(lowlink[v], dfn[u]);
             }
    }

    if (dfn[v] == lowlink[v]) {
        scc[v] = ++scc_size;
        int u;
        do {
            u = s.top(); s.pop();
            inStack[u] = 0;
            scc[u] = scc_size;
        } while (u != v);
    }
    return 0;
}

int solve() {
    int i;
    CLR(dfn, 0); CLR(lowlink, 0); ind = 0;
    CLR(inStack, 0); while (!s.empty()) s.pop();
    CLR(scc, 0); scc_size = 0;
    for (i = 1; i <= n; ++i)
        if (!dfn[i]) tarjan(i);

    CLR(indeg, 0); CLR(outdeg, 0);
    for (i = 1; i <= n; ++i) {
        int j;
        for (j = head[i]; j != -1; j = edge[j].next) {
            int u = edge[j].to;
            if (scc[i] != scc[u]) {
                outdeg[scc[i]]++;
                indeg[scc[u]]++;
            }
        }
    }

    int ans_a = 0;
    for (i = 1; i <= scc_size; ++i)
        if (indeg[i] == 0) ++ans_a;
    //dump(scc_size)
    cout << ans_a << endl;

    int ans_b = 0;
    int res1, res2;
    res1 = ans_a; res2 = 0;
    for (i = 1; i <= scc_size; ++i)
        if (outdeg[i] == 0) ++res2;
    if (scc_size == 1) ans_b = 0;
    else ans_b = max(res1, res2);
    cout << ans_b << endl;
    return 0;
}

int main() {
    fin fout
    input();
    solve();
    return 0;
}
