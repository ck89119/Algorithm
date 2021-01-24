#include <bits/stdc++.h>
using namespace std;

#define dump(x) cout <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0xc0
typedef long long ll;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 2000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n, m, cost[26];
// int add[N], del[N];
string s;
int f[N][N];

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  cin >> n >> m >> s;
  for (int i = 0; i < n; ++i) {
    char ch;
    int a, d;
    cin >> ch >> a >> d;
    cost[ch-'a'] = min(a, d);
    // add[ch-'a'] = a;
    // del[ch-'a'] = d;
  }

  memset(f, 0, sizeof(f));
  for (int i = 0; i < m; ++i)
    for (int j = i + 1; j < m; ++j)
      f[i][j] = INF;
  for (int l = 2; l <= m; ++l)
    for (int i = 0; i + l <= m; ++i) {
      int j = i + l - 1;
      if (s[i] == s[j]) f[i][j] = f[i+1][j-1];
      else f[i][j] = min(f[i][j-1] + cost[s[j]-'a'], f[i+1][j] + cost[s[i]-'a']);
      // dump(i), dump(j), dump(f[i][j]);
    }
  printf("%d\n", f[0][m-1]);
  return 0;
}