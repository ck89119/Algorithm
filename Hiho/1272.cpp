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
const int N = 50 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int a[N], b[N];
int n;
int max_sum;

int dfs(int dep, int s, int sum_a, int sum_b) {
  if (dep >= 3 || s >= n) {
    if (sum_a % 50 == 0) {
      max_sum = max(max_sum, sum_b);
    }
    return 0;
  } 
  
  dfs(dep, s + 1, sum_a, sum_b);
  dfs(dep + 1, s + 1, sum_a + a[s], sum_b + b[s]);
  return 0;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif
  int q;
  scanf("%d", &q);
  while (q--) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      char s[10];
      scanf("%s %d", s, &b[i]);
      a[i] = (s[0] - '0') * 10 + s[2] - '0';
    }
    //out(a, n);
    //out(b, n);
    
    max_sum = 0;
    dfs(0, 0, 0, 0);
    printf("%d\n", max_sum);
  }
  return 0;
}
