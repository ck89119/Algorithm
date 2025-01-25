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

// struct EdgeNode {
//     int to;
//     int w;
//     int next;
// } edges[N];
// int head[N];
// int dfn[N];
// int low[N];
// int idx, edgesSize, cnt;
// stack<int> s;
// int in_stack[N];
// int group_number[N];
// int m, n;

// int init() {
//     memset(dfn, -1, sizeof(dfn));
//     memset(low, -1, sizeof(low));
//     memset(head, -1, sizeof(head));
//     idx = 0;
//     edgesSize = 0;
//     while (!s.empty()) s.pop();
//     memset(in_stack, 0, sizeof(in_stack));
//     cnt = 0;
//     return 0;
// }

// int addEdge(int u, int v, int w, int &k) {
//     edges[k].to = v;
//     edges[k].w = w;
//     edges[k].next = head[u];
//     head[u] = k++;
//     return 0;
// }

// int input() {
//     int i;
//     cin >> n >> m;
//     for (i = 0; i < m; i++) {
//         int u, v;
//         cin >> u >> v;
//         addEdge(u, v, 1, edgesSize);
//     }
//     return 0;
// }

// int tarjan(int v) {
//     int i;
//     dfn[v] = low[v] = idx++;
//     s.push(v);
//     in_stack[v] = 1;
//     for (i = head[v]; i != -1; i = edges[i].next) {
//         int u = edges[i].to;
//         if (dfn[u] == -1) {
//             tarjan(u);
//             low[v] = min(low[v], low[u]);
//         } else if (in_stack[u]) {
//             low[v] = min(low[v], dfn[u]);
//         }
//     }

//     if (dfn[v] == low[v]) {
//         int u;
//         cnt++;
//         do {
//             u = s.top(); s.pop();
//             in_stack[u] = 0;
//             group_number[u] = cnt;
//         } while (u != v);
//         //cout << v << endl;
//     }
//     return 0;
// }

// int solve() {
//     for (int i = 1; i <= n; i++)
//         if (dfn[i] == -1) tarjan(i);
//     return 0;
// }

// int main() {
//     init();
//     input();
//     solve();
//     return 0;
// }

struct SccTarjan {
    vector<vector<int>> g;
    int n;
    vector<int> dfn, low, belongs, new_size;
    stack<int> s;
    vector<bool> in_stack;
    int idx, cnt;

    SccTarjan(vector<vector<int>> &_g) : g(move(_g)) {
        n = g.size();
        dfn = vector<int>(n, -1);
        low = vector<int>(n, -1);
        belongs = vector<int>(n);
        in_stack = vector<bool>(n);
        idx = 0;
        cnt = 0;
    }

    void dfs(int v) {
        dfn[v] = low[v] = idx++;
        s.push(v);
        in_stack[v] = true; for (auto u: g[v]) {
            if (dfn[u] == -1) {
                dfs(u);
                low[v] = min(low[v], low[u]);
            } else if (in_stack[u]) {
                low[v] = min(low[v], dfn[u]);
            }
        }
    
        if (dfn[v] == low[v]) {
            int size = 0;
            while (true) {
                int u = s.top(); s.pop();
                in_stack[u] = false;
                belongs[u] = cnt;
                ++size;

                if (u == v) break;
            }

            new_size.push_back(size);
            cnt += 1;
        }
    }

    void process() {
        for (int i = 0; i < n; ++i)
            if (dfn[i] == -1) dfs(i);
    }

    vector<unordered_set<int>> gen_new_graph() {
        vector<unordered_set<int>> new_g(cnt);
        for (int i = 0; i < n; ++i) {
            int u = belongs[i];
            for (auto j: g[i]) {
                int v = belongs[j];
                if (u == v) continue;

                new_g[u].emplace(v);
            } 
        }
        return new_g;
    }
};

int main() {
  vector<vector<int>> g(4);
  g[0] = {1};
  g[1] = {2};
  g[2] = {0};
  g[3] = {0};

  SccTarjan scc(g); 
  scc.process();

  auto &belongs = scc.belongs;
  cout << "belongs: " << endl;
  for (auto x: belongs) cout << x << " "; cout << endl;

  auto &new_size = scc.new_size;
  cout << "new_size: " << endl;
  for (auto x: new_size) cout << x << " "; cout << endl;

  auto &&new_g = scc.gen_new_graph();
  cout << "new_g: " << endl;
  for (int i = 0; i < new_g.size(); ++i) {
    cout << i << ": ";
    for (auto x: new_g[i]) cout << x << " "; cout << endl;
  }

  return 0;
}

