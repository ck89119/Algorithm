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

int cnt[N][26];

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  int t;
  scanf("%d", &t);
  for (int ncase = 1; ncase <= t; ++ncase) {
    memset(cnt, 0, sizeof(cnt));
//    dump("$$$$");

    int n, q;
    char s[N];
    scanf("%d%d", &n, &q); getchar();
    scanf("%s", s);
    ++cnt[0][s[0]-'A'];
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < 26; ++j) cnt[i][j] = cnt[i-1][j];
      ++cnt[i][s[i]-'A'];
    }
//    dump("$$$$");

    int ans = 0;
    for (int i = 0; i < q; ++i) {
      int l, r;
      scanf("%d%d", &l, &r);
      int c = 0;
      for (int j = 0; j < 26; ++j)
        c += (cnt[r-1][j] - (l - 1 == 0 ? 0 : cnt[l-2][j])) % 2;
      ans += (c <= 1);
    }
    printf("Case #%d: %d\n", ncase, ans);
  }
  return 0;
}
