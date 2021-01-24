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
const int N = 1000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n, m;
int a[N], b[N];

double calc(double m, double b) {
  return m / (b - 1);
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    if (a[i] == 1) {
      printf("-1\n");
      return 0;
    }
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &b[i]);
    if (b[i] == 1) {
      printf("-1\n");
      return 0;
    }
  }
  
  double ans = m;
  for (int i = n-1; i >= 0; --i) {
    int c = b[(i+1)%n];
    ans += calc(ans, c);    
    c = a[i];
    ans += calc(ans, c);    
  }
  printf("%.6lf\n", ans - m);
  return 0;
}
