#include <bits/stdc++.h>
using namespace std;

#define dump(x) cout <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0xc0
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(x) x & (-x)
#define X first
#define Y second
typedef long long ll;
typedef pair<int, int> pii;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 300 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n, l, r;
ll f[N][N];

vector<int> parse(char str[]) {
  vector<int> ans;
  for (int i = 0; str[i]; ) {
    int t = 0;
    while (str[i] && str[i] == ' ') ++i;
    while (str[i] && str[i] != ' ') {
      t = t * 10 + str[i] - '0';
      ++i;
    }
    ans.push_back(t);
  }
  return ans;
}

int dp() {
  clr(f, 0);
  f[0][0] = 1;
  for (int i = 1; i < N; ++i)
    for (int j = i; j < N; ++j)
      for (int k = 1; k < N; ++k) {
        f[j][k] += f[j-i][k-1];
      }
  return 0; 
}


int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  dp();
  char str[100];
  while (gets(str)) {
    vector<int> args = parse(str);
    n = args[0];
    if (args.size() == 1) {
      l = 0;
      r = n;
    } else if (args.size() == 2) {
      l = 0;
      r = min(n, args[1]);
    } else {
      l = args[1];
      r = min(n, args[2]);
    }
    // dump(l); dump(r);
    ll ans = 0;
    for (int i = l; i <= r; ++i)
      ans += f[n][i];
    printf("%lld\n", ans);
  }
  return 0;
}
