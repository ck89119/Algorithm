#include <bits/stdc++.h>
using namespace std;

#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
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
const int N = 6400;
const int M = 9999999;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n;
vector<int> w;
int f[N];
int pre[N];

int contain61(int x) {
  int digit[20];
  int num = 0;
  while (x) {
    digit[num++] = x % 10;
    x /= 10;
  }
  for (int i = 0; i < num - 1; ++i)
    if (digit[i] == 1 && digit[i+1] == 6) return 1;
  return 0;
}

int complete_pack(int w, int v) {
  for (int i = w; i <= N; ++i)
    if (f[i] > f[i-w] + v) {
      f[i] = f[i-w] + v;
      pre[i] = i - w;
    }
  return 0;
}

int init() {
  for (int i = 61; i <= 6161; ++i)
    if (contain61(i)) w.push_back(i);
  CLR(f, INF);  CLR(pre, -1);
  f[0] = 0;
  for (int i = 0; i < w.size(); ++i)
    complete_pack(w[i], 1);
  return 0;
}

int output(int i) {
  if (pre[i] == -1) return 0;
  output(pre[i]);
  printf("%d ", i - pre[i]);
  return 0;
} 

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif
  int t;
  init();
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    if (n > 6161) {
      if (contain61(n)) {
        printf("1 %d\n", n);
      } else {
        printf("2 ");
        int x, y;
        x = 6100;
        y = n % 100;
        if (y < 61) y += 100;
        x += y - 61;
        printf("%d %d\n", x, n - x);
      }
    }
    else {
      printf("%d ", f[n] == INF ? 0 : f[n]);
      output(n);
      printf("\n");
    }
  }
  return 0;
}
