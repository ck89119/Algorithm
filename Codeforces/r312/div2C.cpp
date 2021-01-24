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
const int N = 100000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n;
int a[N];

int operation(int x, int s) {
  int ans = 0;
  while (x < s) {
    x <<= 1;
    ++ans;
  }
  if (x == s) return ans;
  else return -1;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  sort(a, a + n);
  
  int ans = 0;
  int flag = 1;
  for (int i = 0; i < n; ++i) {
    int op;
    if (i < n / 2) op = operation(a[i], a[n/2]);
    else op = operation(a[n/2], a[i]);
    operation(a[i], a[n/2]);
    if (op == -1) {
      flag = 0;
      break;
    } else {
      ans += op;
    }
  }

  if (flag) {
    printf("%d\n", ans);
    return 0;
  }
  
  ans = 0;
  for (int i = 0; i < n; ++i) {
    while (a[i] != 1) {
      a[i] >>= 1;
      ++ans;
    }
  }
  printf("%d\n", ans);
  return 0;
}
