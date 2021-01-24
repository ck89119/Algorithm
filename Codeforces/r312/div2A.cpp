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
const int N = 100 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n;
vector<pii> pos, neg;

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int a, x;
    scanf("%d%d", &a, &x);
    if (a > 0) pos.pb(mp(a, x));
    else neg.pb(mp(-a, x));
  }
  sort(pos.begin(), pos.end());
  sort(neg.begin(), neg.end());

  int s, i, j;
  int ans = 0;

  s = i = j = 0;
  while (i < pos.size()) {
    s += pos[i++].Y;
    if (j < neg.size()) s += neg[j++].Y;
    else break;
  }
  ans = max(ans, s);

  s = i = j = 0;
  while (i < neg.size()) {
    s += neg[i++].Y;
    if (j < pos.size()) s += pos[j++].Y;
    else break;
  }
  ans = max(ans, s);

  printf("%d\n", ans);
  return 0;
}
