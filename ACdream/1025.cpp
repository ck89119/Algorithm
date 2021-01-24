#include <bits/stdc++.h>
using namespace std;

#define dump(x) cout <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define CLR(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0x80
#define MP(A, B) make_pair(A, B)
#define PB(A) push_back(A)
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(x) x & (-x)
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 100000 + 5;
const int M = 9999999;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int a, b;
int f[N];

int search(int n) {
  //dump(n);
  //if (n > b) return INF;
  if (f[n] != -1) return f[n];
  int ans = INF;
  
  for (int i = 1; i * i <= n; ++i) {
    if (n % i) continue;
    if (n + n / i <= b) 
      ans = min(ans, search(n + n / i) + 1);
    if (n + i <= b) 
      ans = min(ans, search(n + i) + 1);
  }
  
  return f[n] = ans;
}


int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif
  while (scanf("%d%d", &a, &b) != EOF) {
    if (a > b) {
      printf("-1\n");
      continue;
    }
    CLR(f, -1);
    f[b] = 0;
    printf("%d\n", search(a));
    //out(f, b+1);
  }
  return 0;
}
