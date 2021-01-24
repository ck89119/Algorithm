#include <bits/stdc++.h>
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
const int N = 200 + 5;
const int M = 9999999;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int m, n;
vector<int> edge[N];
map<string, int> mapping;
int c[N];

int add_edge(int u, int v) {
  edge[u].push_back(v);
  return 0;
}

int dfs(int u) {
  for (int i = 0; i < edge[u].size(); ++i) {
    int v = edge[u][i];
    if (c[v] == -1) {
      c[v] = (c[u] ^ 1);
      if (dfs(v) == -1) return -1;
    } else {
      if (c[v] == c[u]) return -1;
    }
  }
  return 0;
}

int main() {
  #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  #endif
  
  int t;
  cin >> t;
  for (int ncase = 1; ncase <= t; ++ncase) {
    mapping.clear();
    for (int i = 0; i < N; ++i) edge[i].clear();

    string s1, s2;
    cin >> m;
    n = 0;
    for (int i = 0; i < m; ++i) {
      cin >> s1 >> s2;
      if (mapping.count(s1) == 0) mapping[s1] = n++;
      if (mapping.count(s2) == 0) mapping[s2] = n++;
      add_edge(mapping[s1], mapping[s2]);
      add_edge(mapping[s2], mapping[s1]); 
    }
    
    int flag = 1;
    CLR(c, -1);
    for (int i = 0; i < n; ++i) 
      if (c[i] == -1) {
        c[i] = 0;
        if (dfs(i) == -1) { flag = 0; break; }
      }

    cout << "Case #" << ncase << ": " << (flag ? "Yes" : "No") << endl;
  }
  return 0;
}
