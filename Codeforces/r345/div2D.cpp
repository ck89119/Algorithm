#include <bits/stdc++.h>
using namespace std;

#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0x80
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
const int N = 1000000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n, a, b, t;
int sum_b[N];
char s[N];

int check(int m) {
  //dump(m);
  for (int i = n - m + 1; i <= n; ++i) {
    int sum = m;
    sum += (m - 1) * a;
    //for (int j = 0; j < m; ++j)
      //if (s[i+j] == 'w') sum += b;
    sum += sum_b[i+m-1] - sum_b[i-1];
    sum += min(n - i, i + m - 1 - n) * a;
    //dump(i); dump(sum); 
    if (sum <= t) return 1;
  }
  return 0;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif
  scanf("%d%d%d%d%s", &n, &a, &b, &t, s);
  for (int i = 0; i < n; ++i) s[n+i] = s[i];
  s[2*n] = '\0';

  sum_b[0] = (s[0] == 'w' ? 1 : 0);
  for (int i = 1; i < 2 * n; ++i)
    sum_b[i] = sum_b[i-1] + (s[i] == 'w' ? b : 0);
  //out(sum_b, n + n);
  int l, r, m;
  l = 0;
  r = n + 1;
  while (l + 1 < r) {
    m = (l + r) / 2;
    if (check(m)) l = m;
    else r = m;
    //printf("%d %d\n", l, r);
  }
  printf("%d\n", l);
  return 0;
}
