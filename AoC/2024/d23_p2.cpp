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
const int N = 676;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

bool g[N][N];
vector<int> best_nodes;

string no2str(int no) {
  string s = "  ";
  s[0] = no / 26 + 'a';
  s[1] = no % 26 + 'a';
  return s;
};

int dfs(int cur, vector<int> &nodes) {
  if (cur == 0) {
    if (nodes.size() > best_nodes.size()) {
      best_nodes = nodes;
      for (int i = nodes.size() - 1; i >= 0; --i) {
        cout << no2str(nodes[i]) << ",";
      }
      cout << endl; 
    }
    return 0;
  } 
  
  if (cur + 1 + nodes.size() < best_nodes.size()) return 0;  
  
  int flag = true;
  for (auto x: nodes) {
    if (!g[cur][x]) {
      flag = false;
      break;
    }
  }
  if (flag) {
    nodes.emplace_back(cur);
    dfs(cur - 1, nodes);
    nodes.pop_back();
  }
  dfs(cur - 1, nodes);
  return 0;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  memset(g, false, sizeof(g));

  string line;
  while (cin >> line) {
    string s0 = line.substr(0, 2);
    string s1 = line.substr(3, 2);
    int a = (s0[0] - 'a') * 26 + s0[1] - 'a';
    int b = (s1[0] - 'a') * 26 + s1[1] - 'a';
    g[a][b] = g[b][a] = true;
  }

  vector<int> nodes;
  dfs(N-1, nodes);
  return 0;
}


// #include <bits/stdc++.h>
// using namespace std;

// #define dump(x) cout <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
// #define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0xc0
// #define mp(a, b) make_pair(a, b)
// #define pb(a) push_back(a)
// #define lowbit(x) x & (-x)
// typedef long long ll;
// typedef unsigned long long ull;
// typedef pair<int, int> pii;

// template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
// template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
// const int N = 26 * 26;
// const int INF = 0x3f3f3f3f;
// const int MOD = 1000000007;

// struct bitmap {
//   ull d[11];

//   bitmap() {
//     memset(d, 0, sizeof(d));
//   }

//   bitmap(bitmap &a) {
//     for (int i = 0; i < 11; ++i)
//       d[i] = a.d[i];
//   }

//   void add(int n) {
//     int i = n / 64;
//     int j = n % 64;
//     d[i] |= (1ull << j);
//   }

//   bool contains(int n) {
//     int i = n / 64;
//     int j = n % 64;
//     return d[i] >> j & 1;
//   }

//   bool contains(bitmap &b) {
//     for (int i = 0; i < 11; ++i)
//       if ((d[i] & b.d[i]) != b.d[i]) {
//         return false;
//       }
//     return true;
//   }

//   int count() {
//     int c = 0;
//     for (int i = 0; i < 11; ++i)
//       c += __builtin_popcountll(d[i]);
//     return c;
//   }

//   bitmap operator&(const bitmap &b) const {
//     bitmap ans;
//     for (int i = 0; i < 11; ++i) {
//       ans.d[i] = d[i] & b.d[i];
//     }
//     return ans;
//   }

//   bool operator==(const bitmap &b) const {
//     for (int i = 0; i < 11; ++i)
//       if (d[i] != b.d[i]) return false;
//     return true;
//   }

//   string print() {
//     auto no2str = [](int no) -> string {
//       string s = "  ";
//       s[0] = no / 26 + 'a';
//       s[1] = no % 26 + 'a';
//       return s;
//     };

//     string ans = "";
//     for (int i = 0; i < 64 * 11; ++i)
//       if (contains(i)) {
//         ans += no2str(i) + ",";
//       }
//     return ans;
//   }
// };

// int main() {
// #ifndef ONLINE_JUDGE
//   freopen("in.txt", "r", stdin);
//   // freopen("out.txt", "w", stdout);
// #endif
//   bitmap g[N];
//   string line;
//   while (cin >> line) {
//     string s0 = line.substr(0, 2);
//     string s1 = line.substr(3, 2);
//     int a = (s0[0] - 'a') * 26 + s0[1] - 'a';
//     int b = (s1[0] - 'a') * 26 + s1[1] - 'a';
//     g[a].add(b);
//     g[b].add(a);
//   }

//   queue<bitmap> q;
//   for (int i = 0; i < N; ++i) {
//     bitmap b;
//     b.add(i);
//     q.emplace(b);
//   }

//   string ans;
//   int max_l = 0;
//   while (!q.empty()) {
//     auto &b = q.front(); q.pop();
//     int c = b.count();

//     dump(c);
//     if (c > max_l) {
//       max_l = b.count();
//       ans = b.print();
//     }

//     for (int i = 0; i < N; ++i) {
//       if (b.contains(i)) continue;

//       if (g[i].contains(b)) {
//         // dump(g[i].print());
//         // dump(b.print());
//         bitmap n(b);
//         n.add(i);
//         q.emplace(n);
//       }
//     }
//   }
//   dump(ans);
//   return 0;
// }
