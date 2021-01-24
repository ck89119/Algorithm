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

string s;
int sa[N], r[N], h[N];

int build_sa(int m) {
  int cnt[N], r1[N], r2[N], t_sa[N];
  s += "$";
  int n = s.size();
  memset(cnt, 0, sizeof(cnt)); 
  for (int i = 0; i < n; ++i) ++cnt[(int)s[i]];
  for (int i = 1; i < m; ++i) cnt[i] += cnt[i-1];
  for (int i = 0; i < n; ++i) r[i] = cnt[(int)s[i]] - 1;
  for (int l = 1; l < n; l <<= 1) {
    for (int i = 0; i < n; ++i)
      r1[i] = r[i], r2[i] = (i+l >= n ? 0 : r[i+l]);
    out(r1, n);
    out(r2, n);
    memset(cnt, 0, sizeof(cnt)); 
    for (int i = 0; i < n; ++i) ++cnt[r2[i]];
    for (int i = 1; i < n; ++i) cnt[i] += cnt[i-1];
    for (int i = n-1; i >= 0; --i) t_sa[--cnt[r2[i]]] = i;
    out(t_sa, n);
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n ;++i) ++cnt[r1[i]];
    for (int i = 1; i < n; ++i) cnt[i] += cnt[i-1];
    for (int i = n-1; i >= 0; --i) sa[--cnt[r1[t_sa[i]]]] = t_sa[i];
    out(sa, n);

    int flag = 1;
    r[sa[0]] = 0;
    for (int i = 1; i < n; ++i) {
      r[sa[i]] = r[sa[i-1]];
      if (r1[sa[i]] == r1[sa[i-1]] && r2[sa[i]] == r2[sa[i-1]]) flag = 0;
      else ++r[sa[i]];
    }
    if (flag) break;
//    cout << "##############" << endl;
  }
  return 0;
}

int get_h() {
  int n = s.size();
  int k = 0;
  for (int i = 0; i < n-1; ++i) {
    if (k) --k; 
    int j = sa[r[i]-1];
    while (s[i+k] == s[j+k]) ++k;
    h[i] = k;
  }
  return 0;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  cin >> s;
  build_sa(128);
  out(sa, s.size());
  get_h();
  out(h, s.size());
  return 0;
}    
