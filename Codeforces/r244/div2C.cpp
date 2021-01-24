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
const int MAXN=100000+5;
const int MAXM=300000+5;
const int INF=0x3f3f3f3f;
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
int ind, edgesSize, cnt;
stack<int> s;
int inStack[MAXN];
int belong[MAXN];
int m, n;
int w[MAXN], min_w[MAXN], num[MAXN];

int init() {
    CLR(dfn, -1);
    CLR(low, -1);
    CLR(head, -1);
    ind = 0;
    edgesSize = 0;
    while (!s.empty()) s.pop();
    CLR(inStack, 0);
    cnt = 0;
    CLR(min_w, INF);
    CLR(num, 0);
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
    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%d", &w[i]);
    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        addEdge(u, v, 1, edgesSize);
    }
    return 0;
}

int tarjan(int v) {
    int i;
    dfn[v] = low[v] = ind++;
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
    int i, j;
    for (i = 1; i <= n; i++)
        if (dfn[i] == -1) tarjan(i);
    for (i = 1; i <= n; ++i) {
      int x = belong[i];
      //dump(i); dump(x); dump(w[i]);
      if (min_w[x] > w[i]) {
        min_w[x] = w[i];
        num[x] = 1;
      } else if (min_w[x] == w[i]) {
        num[x]++;
      }
    }
    
    long long ans = 1;
    long long sum = 0;
    long long MOD = 1000000007; 
    //dump(cnt);
    for (i = 1; i <= cnt; ++i) {
      //dump(min_w[i]);
      sum += min_w[i];
    }
    for (i = 1; i <= cnt; ++i)
      ans = ans * num[i] % MOD; 
    printf("%I64d %I64d\n", sum, ans);
    return 0;
}

int main() {
  init();
  input();
  solve();
  return 0;
}
