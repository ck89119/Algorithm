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
const int N = 200000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n;
vector<pii> w;
map<pii, int> num;
ll ans;

int cmp(const pii &a, const pii &b) {
  return a.second < b.second;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int x, y;
    pii z;
    scanf("%d%d", &x, &y);
    z = mp(x, y);
    w.pb(z);
    num[z] += 1;
  }
  
  ans = 0;
  sort(w.begin(), w.end());
  for (int i = 0; i < n; ) {
    int j = i + 1;
    int x = w[i].first;
    while (j < n && x == w[j].first) ++j;
    ans += (ll)(j - i) * (j - i - 1) / 2;
    i = j;
  }

  sort(w.begin(), w.end(), cmp);
  for (int i = 0; i < n; ) {
    int j = i + 1;
    int x = w[i].second;
    while (j < n && x == w[j].second) ++j;
    ans += (ll)(j - i) * (j - i - 1) / 2;
    i = j;
  }
  
  for (auto &i : num)
    ans -= (ll)i.second * (i.second - 1) / 2;

  printf("%I64d\n", ans);
  return 0;
}
