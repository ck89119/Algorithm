#include <bits/stdc++.h>
using namespace std;

#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0x80
#define mp(A, B) make_pair(A, B)
#define pb(A) push_back(A)
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(x) x & (-x)
#define X first 
#define Y second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 3000 + 5;
const int M = 9999999;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n, m;
int p[N];

int cmp(int a, int b, int op) {
  if (op > 0) return a > b;
  else return a < b;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif
  int inv_num = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &p[i]);
    for (int j = 0; j < i; ++j)
      if (p[j] > p[i]) ++inv_num;
  }
  scanf("%d", &m);
  //dump(inv_num); dump(m);

  int ans = abs(inv_num - m);
  int flag;
  printf("%d\n", ans);
  while (ans) {
    flag = 1;
    for (int i = 0; flag && i < n; ++i)
      for (int j = i + 1; flag && j < n; ++j) {
        if (cmp(p[i], p[j], inv_num - m)) {
          printf("%d %d ", i + 1, j + 1);
          swap(p[i], p[j]);
          --ans; flag = 0;
        }
      }
    }

  return 0;
}
