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

typedef pair<ll, char> pic;
int n, m;
pic a[N], b[N];
int fail[N], kmp[N];

int KMP(pic *a, int la, pic *b, int lb) {
  int j;
  fail[0] = j = -1;
  for (int i = 1; i < lb; ++i) {
    while (j >= 0 && b[i] != b[j+1]) j = fail[j];
    if (b[i] == b[j+1]) ++j;
    fail[i] = j;
  }
  // out(fail, lb);
  j = -1;
  for (int i = 0; i < la; ++i) {
    while (j >= 0 && a[i] != b[j+1]) j = fail[j];
    if (a[i] == b[j+1]) ++j;
    kmp[i] = j;
    // if (kmp[i] == lb - 1) printf("%d\n", i);
  }
  // out(kmp, la);
  // for (int i = 99995; i < 100010; ++i)
    // dump(i), dump(kmp[i]);
  return 0;
}


int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif
 
  ll l;
  char c;
  int la, lb;
  scanf("%d%d", &n, &m);
  la = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%I64d-%c", &l, &c);
    // scanf("%lld-%c", &l, &c);
    if (la > 0 && c == a[la-1].second) a[la-1].first += l;
    else a[la++] = mp(l, c);
  }
  lb = 0;
  for (int i = 0; i < m; ++i) {
    scanf("%I64d-%c", &l, &c);
    // scanf("%lld-%c", &l, &c);
    if (lb > 0 && c == b[lb-1].second) b[lb-1].first += l;
    else b[lb++] = mp(l, c);
  }
  // dump(la); dump(lb); 
  ll ans = 0;
  if (lb == 1) {
    for (int i = 0; i < la; ++i) {
      l = a[i].first;
      c = a[i].second;
      if (b[0].second == c && b[0].first <= l) ans += (l - b[0].first + 1);
    }
  } else if (lb == 2) {
    for (int i = 0; i + 1 < la; ++i)
      if ((b[0].second == a[i].second && b[0].first <= a[i].first) &&
          (b[1].second == a[i+1].second && b[1].first <= a[i+1].first))
        ans += 1;
  } else {
    pic tmp1 = b[0];
    pic tmp2 = b[lb-1];
    b[0].second = b[lb-1].second = 'A';
    KMP(a, la, b + 1, lb - 2);
    for (int i = 0; i < la; ++i)
      if (kmp[i] == lb - 3) {
        if ((i - lb + 2 >= 0 && a[i-lb+2].second == tmp1.second && a[i-lb+2].first >= tmp1.first) && 
           (i + 1 < la && a[i+1].second == tmp2.second && a[i+1].first >= tmp2.first)) ++ans;
      } 
  }
  printf("%I64d\n", ans);
  // printf("%lld\n", ans);


  return 0;
}
