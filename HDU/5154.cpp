#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
//#include <bits/stdc++.h>
using namespace std;

#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define CLR(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0x80
#define MP(A, B) make_pair(A, B)
#define PB(A) push_back(A)
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(x) x & (-x)
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 100 + 4;
const int M = 9999999;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n, m;
vector<int> edge[N];
int indegree[N];

int topsort() {
  int cnt = 0;
  while (true) {
    int k = -1;
    for (int i = 1; i <= n; ++i)
      if (indegree[i] == 0) {
        k = i;
        break;
      }
    if (k == -1) break;
    indegree[k] = -1;
    ++cnt;
    for (int i = 0; i < edge[k].size(); ++i) {
      int v = edge[k][i];
      --indegree[v];
    }
  }
  return cnt == n;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif
  while (scanf("%d%d", &n, &m) != EOF) {
    for (int i = 0; i <= n; ++i)
      edge[i].clear();
    CLR(indegree, 0);
    for (int i = 0; i < m; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      edge[v].push_back(u);
      ++indegree[u];
    }
    printf("%s\n", topsort() ? "YES" : "NO");
  }
  return 0;
}
