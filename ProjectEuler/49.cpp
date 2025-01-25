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
const int N = 10000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int prime[N];

int get_prime() {
  for (int i = 0; i < N; ++i) prime[i] = 1;
  prime[0] = prime[1] = 0;

  for (int i = 2; i < N; ++i) 
    if (prime[i]) {
      int j = i + i;
      while (j < N) {
        prime[j] = 0;
        j += i;
      }
    }
  return 0;
}

int same_digit(int x, int y) {
  vector<int> dx, dy;
  while (x) {
    dx.push_back(x % 10);
    x /= 10;
  }
  while (y) {
    dy.push_back(y % 10);
    y /= 10;
  }
  sort(dx.begin(), dx.end());
  sort(dy.begin(), dy.end());
  for (int i = 0; i < 4; ++i)
    if (dx[i] != dy[i]) return 0;
  return 1;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  get_prime();
  for (int i = 1000; i < N; ++i) {
    if (!prime[i]) continue;
    for (int j = i+1; j < N; ++j) {
      if (!prime[j]) continue;
      if (!same_digit(i, j)) continue;
      // dump(i), dump(j);
      int k = 2 * j - i;
      if (k < N && prime[k] && same_digit(i, k)) {
        printf("%d %d %d\n", i, j, k); 
      }     
    }
  }
  return 0;
}
