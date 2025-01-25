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
const int N = 26 * 26;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  bool g[N][N];
  memset(g, 0, sizeof(g));

  string line;
  while (cin >> line) {
    string s0 = line.substr(0, 2);
    string s1 = line.substr(3, 2);
    int a = (s0[0] - 'a') * 26 + s0[1] - 'a';
    int b = (s1[0] - 'a') * 26 + s1[1] - 'a';
    g[a][b] = 1;
    g[b][a] = 1;
  }
  
  int l = ('t' - 'a') * 26;
  int r = ('t' - 'a' + 1) * 26;
  
  auto check = [&](int x) -> bool {
    return x >= l && x < r;
  };
  
  int ans = 0;
  for (int i = 0; i < N; ++i)
    for (int j = i + 1; j < N; ++j)
      for (int k = j + 1; k < N; ++k)
        if (check(i) || check(j) || check(k)) {
          ans += (g[i][j] && g[j][k] && g[k][i]);
        }
  dump(ans);   
  return 0;
}
