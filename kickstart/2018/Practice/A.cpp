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
const int N = 5000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int x[N];
int n, p;

int main() {
#ifndef ONLINE_JUDGE
  freopen("A-large-practice.in", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int t;
  scanf("%d", &t);
  for (int ncase = 1; ncase <= t; ++ncase) {
    clr(x, 0);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      int a, b;
      scanf("%d%d", &a, &b);
      ++x[a], --x[b+1];
    }
    for (int i = 1; i < N; ++i) x[i] += x[i-1];

    printf("Case #%d:", ncase);
    scanf("%d", &p);
    while (p--) {
      int a;
      scanf("%d", &a);
      printf(" %d", x[a]);
    }
    printf("\n");
  }
  return 0;
}
