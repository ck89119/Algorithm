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
const int N = 101;
const int M = 103;
// const int N = 11;
// const int M = 7;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  vector<vector<int>> count(N, vector<int>(M));
  int x, y, vx, vy; 
  while (scanf("p=%d,%d v=%d,%d\n", &x, &y, &vx, &vy) != EOF) {
    // dump(x), dump(y), dump(vx), dump(vy);
    x = ((x + vx * 100) % N + N) % N;
    y = ((y + vy * 100) % M + M) % M;
    count[x][y] += 1;
  }
  
  ll c1 = 0, c2 = 0, c3 = 0, c4 = 0;
  for (int i = 0; i < N / 2; ++i)
    for (int j = 0; j < M / 2; ++j)
      c1 += count[i][j];

  for (int i = 0; i < N / 2; ++i)
    for (int j = M / 2 + 1; j < M; ++j)
      c2 += count[i][j];
  
  for (int i = N / 2 + 1; i < N; ++i)
    for (int j = 0; j < M / 2; ++j)
      c3 += count[i][j];

  for (int i = N / 2 + 1; i < N; ++i)
    for (int j = M / 2 + 1; j < M; ++j)
      c4 += count[i][j];
  // dump(c1), dump(c2), dump(c3), dump(c4);
  printf("%lld\n", c1 * c2 * c3 * c4);
  return 0;
}
