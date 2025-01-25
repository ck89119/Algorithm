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
const int N = 28123 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

vector<int> ab;
int is_ab(int n) {
  int sum = 1;
  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      sum += i;
      if (i * i < n) sum += n / i;
    } 
  }
  return sum > n;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  for (int i = 1; i < N; ++i)
    if (is_ab(i)) ab.push_back(i);
  
  bool f[N];
  clr(f, false);
  for (int i = 0; i < ab.size(); ++i)
    for (int j = i; j < ab.size(); ++j) {
      int s = ab[i] + ab[j];
      if (s < N) f[s] = true;
    }

  int sum = 0;
  for (int i = 1; i < N; ++i)
    if (!f[i]) sum += i;
  cout << sum << endl;
  return 0;
}
