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
const int MAXN=99999;
const int MAXM=999999;
const int INF=(1<<30);
const double PI=acos(-1.0);
const double EPS=1e-11;

struct EdgeNode {
    int to;
    int w;
    int next;
}edges[MAXM];
int head[MAXN];
int dfn[MAXN];
int low[MAXN];
int idx, edgesSize, cnt;
stack<int> s;
int inStack[MAXN];
int belong[MAXN];
int m, n;

int init() {
    CLR(dfn, -1);
    CLR(low, -1);
    CLR(head, -1);
    idx = 0;
    edgesSize = 0;
    while (!s.empty()) s.pop();
    CLR(inStack, 0);
    cnt = 0;
    return 0;
}

int addEdge(int u, int v, int w, int &k) {
    edges[k].to = v;
    edges[k].w = w;
    edges[k].next = head[u];
    head[u] = k++;
    return 0;
}

int input() {
    int i;
    cin >> n >> m;
    for (i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v, 1, edgesSize);
    }
    return 0;
}

int tarjan(int v) {
    int i;
    dfn[v] = low[v] = idx++;
    s.push(v);
    inStack[v] = 1;
    for (i = head[v]; i != -1; i = edges[i].next) {
        int u = edges[i].to;
        if (dfn[u] == -1) {
            tarjan(u);
            low[v] = min(low[v], low[u]);
        } else if (inStack[u]) {
            low[v] = min(low[v], dfn[u]);
        }
    }

    if (dfn[v] == low[v]) {
        int u;
        cnt++;
        do {
            u = s.top(); s.pop();
            inStack[u] = 0;
            belong[u] = cnt;
        } while (u != v);
        //cout << v << endl;
    }
    return 0;
}

int solve() {
    int i;
    for (i = 1; i <= n; i++)
        if (dfn[i] == -1) tarjan(i);
    return 0;
}

int main() {
    init();
    input();
    solve();
    return 0;
}
