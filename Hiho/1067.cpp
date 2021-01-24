#include <bits/stdc++.h>
using namespace std;

#define dump(x) cout <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0xc0
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define lowbit(x) x & (-x)
typedef long long ll;
typedef pair<int, int> pii;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 100000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

//struct Edge {
//  int v, w;
//  Edge(int _v, int _w): v(_v), w(_w) {}
//};
int n, m;
map<string, int> mapping;
map<int, string> remapping;
vector<int> edges[N];
vector<pii> queries[N], ans;
int vis[N];
int anc[N];

struct UnionFindSet {
  int f[N];
  
  UnionFindSet() {
    for (int i = 0; i < N; ++i) f[i] = i;
  }
  
  int find(int x) {
    return f[x] == x ? x : f[x] = find(f[x]); 
  }
  
  int unite(int x, int y) {
    f[find(x)] = f[find(y)];
    return 0;
  }
} s;

int get_idx(const string &s) {
  if (mapping.find(s) == mapping.end()) {
    int cnt = mapping.size();
    mapping[s] = cnt;
    remapping[cnt] = s;
    return cnt;
  }
  return mapping[s];
}

int add_edge(int u, int v) {
  edges[u].push_back(v);
  return 0;
}

int add_query(int u, int v) {
  queries[u].emplace_back(v, -1);
  queries[v].emplace_back(u, -1);
  return 0;
}

int lca(int u) {
//  cout << "####  " << u << "   ####" << endl; 
  vis[u] = 1;
  for (auto v: edges[u]) 
    if (!vis[v]) {
      lca(v); 
      s.unite(u, v); 
      anc[s.find(v)] = u;
    }
  
  for (auto &p: queries[u]) {
    int v = p.first;
    int &q = p.second;
    if (q == -1 && vis[v]) {
      q = anc[s.find(v)];
    }
  }
  return 0;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  string sa, sb;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    cin >> sa >> sb;
    int u = get_idx(sa);
    int v = get_idx(sb);
    add_edge(u, v);
  }
  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    cin >> sa >> sb;
    int u = get_idx(sa);
    int v = get_idx(sb);
    add_query(u, v);
    ans.emplace_back(u, v);
  }
//  for (auto &p: mapping) cout << "<" << p.first << ", " << p.second << ">, "; cout << endl;

  for (int i = 0; i < mapping.size(); ++i) anc[i] = i;
  memset(vis, 0, sizeof(vis));
  lca(0);
//  dump(ans.size());
  for (auto &p: ans) {
    int u = p.first;
    int v = p.second;
    int flag = 0;
    for (auto q: queries[u])
      if (q.first == v && q.second != -1) {
        cout << remapping[q.second] << endl;
        flag = 1;
        break;
      }
    if (flag) continue;
    for (auto q: queries[v])
      if (q.first == u && q.second != -1) {
        cout << remapping[q.second] << endl;
        flag = 1;
        break;
      }
  }
  return 0;
}
