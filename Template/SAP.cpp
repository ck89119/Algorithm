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
const int MAXN=99999;
const int MAXM=9999999;
const int INF=(1<<30);
const double PI=acos(-1.0);
const double EPS=1e-11;

struct Edge {
    int v, f, next;
}edge[MAXM];
int edge_size;
int head[MAXN];
int h[MAXN], hnum[MAXN];
int n, np, nc, m;
int s, t;

int addEdge(int u, int v, int c) {
    edge[edge_size].v = v;
    edge[edge_size].f = c;
    edge[edge_size].next = head[u];
    head[u] = edge_size++;
    return 0;
}

int travel() {
    int i, j;
    for (i = 0; i <= n+1; i++) {
        cout << "i = " << i << ": ";
        for (j = head[i]; j != -1; j = edge[j].next) {
            cout << edge[j].v << ' ';
        }
        cout << endl;
    }
    return 0;
}

int dfs(int u, int flow) {
    //dump(u)
    int delta, left = flow, minh = n+1;
    int i;
    if (u == t) return flow;

    for (i = head[u]; i != -1; i = edge[i].next) {
        int v = edge[i].v;
        int f = edge[i].f;
        if (f) {
            if (h[v] == h[u]-1) {
                //dump(v)
                delta = dfs(v, min(left, f));
                edge[i].f -= delta;
                edge[i^1].f += delta;
                left -= delta;
                if (left == 0 || h[s] == n+2) return flow - left;
            }
            minh = min(minh, h[v]);
        }
    }
    //dump(minh)
    if (left == flow) {
        hnum[h[u]]--; //dump(h[u])dump(hnum[h[u]])
        if (!hnum[h[u]]) h[s] = n+2;
        h[u] = minh + 1;
        hnum[h[u]]++;
    }
    //out(h, n+2);
    //PAU
    return flow - left;
}

int sap(int src, int sink) {
    int maxFlow = 0;
    s = src; t = sink;
    CLR(h, 0);
    CLR(hnum, 0);
    hnum[0] = n+2;
    while (h[s] < n+2) maxFlow += dfs(s, INF);
    return maxFlow;
}

int trans(char s[50], int &a, int &b, int &c) {
    int i = 1;
    a = b = c = 0;
    while (s[i] != ',') {
        a = a*10 + s[i] - '0';
        i ++;
    }
    i ++;
    while (s[i] != ')') {
        b = b*10 + s[i] - '0';
        i ++;
    }
    i ++;
    while (s[i] != '\0') {
        c = c*10 + s[i] - '0';
        i ++;
    }
    return 0;
}

int trans1(char s[50], int &a, int &b) {
    int i = 1;
    a = b = 0;
    while (s[i] != ')') {
        a = a * 10 + s[i] - '0';
        i ++;
    }
    i ++;
    while (s[i] != '\0') {
        b = b * 10 + s[i] - '0';
        i ++;
    }
    return 0;
}

int main() {
    while (scanf("%d%d%d%d", &n, &np, &nc, &m) != EOF) {
        char str[50];
        int i, a, b, c;
        edge_size = 0;
        CLR(head, -1);
        for (i = 0; i < m; i ++) {
            scanf("%s", str);
            trans(str, a, b, c);
            addEdge(a, b, c);
            addEdge(b, a, 0);
        }
        for (i = 0; i < np; i++) {
            scanf("%s", str);
            trans1(str, a, b);
            addEdge(n, a, b);
            addEdge(a, n, 0);
        }
        for (i = 0; i < nc; i++) {
            scanf("%s", str);
            trans1(str, a, b);
            addEdge(a, n+1, b);
            addEdge(n+1, a, 0);
        }
        //travel();
        printf("%d\n",sap(n, n+1));

    }
    return 0;
}
