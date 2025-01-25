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

int status;

int have_same_digit(int n) {
  int ans = 0;
  while (n) {
    int d = n % 10;
    n /= 10;
    if (ans >> d & 1) return -1;
    ans |= (1 << d);
  }
  return ans;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int ans = 0;
  status = 0;
  for (int i = 1000; i < 10000; ++i) {
    int have_ans = 0;
    int ti = have_same_digit(i);
    if (ti == -1 || ti & status) continue;
    status ^= ti;
    for (int j = 2; j < 100; ++j) {
      int tj = have_same_digit(j);
      if (tj == -1 || tj & status) continue;
      status ^= tj;
    
      int k = i / j;
      if (i == j * k) {
        int tk = have_same_digit(k);
        if (have_ans == 0 && tk != -1 && (tk & status) == 0 && (tk | status) == (1 << 10) - 2) {
          have_ans = 1;
          ans += i;
        }
      }
      status ^= tj;
    }
    status ^= ti;
  }
  printf("%d\n", ans);
  return 0;
}
