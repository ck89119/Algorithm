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
const int N = 360000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int p[10];

int get_sum(int n) {
  int sum = 0;
  while (n) {
    sum += p[n%10];
    n /= 10;
  }
  return sum;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  for (int i = 0; i < 10; ++i) p[i] = pow(i, 5);
  
  int ans = 0;
  for (int i = 10; i < N; ++i)
    if (get_sum(i) == i) ans += i;
  printf("%d\n", ans);

  return 0;
}
