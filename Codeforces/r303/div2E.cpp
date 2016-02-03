#include <bits/stdc++.h>
using namespace std;

#define dump(x) cout <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
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
const int N = 3 * 100000 + 5;
const int M = 9999999;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n, m, st;
vector<PII> edge[N];
int ans[N];
int weight[N];
LL dis[N];

int add_edge(int u, int v, int id) {
  edge[u].push_back(make_pair(v, id));
  return 0;
}

int dijkstra(int st) {
  CLR(dis, 0x3f);

  priority_queue<pair<LL, int> > q;
  dis[st] = 0;
  q.push(make_pair(0, st));
  
  while (!q.empty()) {
    LL d = -q.top().first;
    int u = q.top().second;
    //dump(d); dump(u);
    q.pop();
    
    for (int i = 0; i < edge[u].size(); ++i) {
      int v = edge[u][i].first;
      int id = edge[u][i].second;
      int w = weight[id];
      if (dis[v] > d + w) {
        dis[v] = d + w;
        ans[v] = id;
        q.push(make_pair(-dis[v], v));
      } else if (dis[v] == d + w) {
        ans[v] = id;
      }
    }
  }
  return 0;
}


int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    add_edge(u, v, i);
    add_edge(v, u, i);
    weight[i] = w;
  }
  scanf("%d", &st);
  dijkstra(st);
  LL sum = 0;
  for (int i = 1; i <= n; ++i)
    if (i != st) sum += weight[ans[i]];
  printf("%I64d\n", sum);
  for (int i = 1; i <= n; ++i)
    if (i != st) printf("%d ", ans[i]);
  printf("\n");
  return 0;
}
