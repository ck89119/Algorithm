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

vector<int> digits;
int f[10][13][3][2];

int dfs(int cur, int r, int pre_digit, int limit) {
  if (cur < 0) return r == 0 && pre_digit == 2;
  if (f[cur][r][pre_digit][limit] != -1) return f[cur][r][pre_digit][limit];

  int ans = 0;
  int end = limit ? digits[cur] : 9;
  for (int i = 0; i <= end; ++i) {
    int p = 0;
    if (pre_digit == 2) {
      p = 2;
    } else if (i == 1) {
      p = 1;
    } else if (i == 3 && pre_digit == 1) {
      p = 2;
    }
    ans += dfs(cur - 1, (r * 10 + i) % 13, p, limit && i == end);
  }
  return f[cur][r][pre_digit][limit] = ans;
}


int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  int n;
  while (scanf("%d", &n) != EOF) {
    digits.clear();
    while (n) {
      digits.push_back(n % 10);
      n /= 10;
    }

    memset(f, -1, sizeof(f));
    printf("%d\n", dfs(digits.size() - 1, 0, 0, 1));
  }
  return 0;
}
