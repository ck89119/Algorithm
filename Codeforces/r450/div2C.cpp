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

int n;
int a[N], cnt[N];
pair<int, int> c[N];

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  
  int fir, sec;
  fir = sec = -INF;
  clr(cnt, 0);
  for (int i = 0; i < n; ++i) {
    if (a[i] > fir) {
      --cnt[a[i]];
      sec = fir; fir = a[i];
    } else if (a[i] > sec) {
      ++cnt[fir]; 
      sec = a[i];
    }
    // out(cnt, n+1);
    // dump(fir), dump(sec);
  }
  
  int max_cnt = -INF;
  int ans = -1;
  for (int i = 1; i <= n; ++i) {
    if (cnt[i] > max_cnt) {
      max_cnt = cnt[i];
      ans = i;
    } else if (cnt[i] == max_cnt) {
      ans = min(ans, i); 
    }
  }

  printf("%d\n", ans);
  return 0;
}
