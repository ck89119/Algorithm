#include <bits/stdc++.h>
using namespace std;

#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define CLR(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0x80
#define MP(A, B) make_pair(A, B)
#define PB(A) push_back(A)
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(x) x & (-x)
#define X first
#define Y second
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 200000 + 5;
const int M = 9999999;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n;
int p[N];
int size[N];
int ans[N];
PII a[N];

int get(int x) {
  if (x == p[x]) return x;
  else return p[x] = get(p[x]);
}

int unite(int x, int y) {
  if (x < 0 || x >= n) return 0;
  if (y < 0 || y >= n) return 0;
  if (p[x] == -1 || p[y] == -1) return 0;
  x = get(x);
  y = get(y);
  p[y] = x;
  size[x] += size[y];
  return 0;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    a[i] = make_pair(x, i);
    size[i] = 1;
    p[i] = -1;
  }
  sort(a, a + n);
 
  CLR(ans, -1);
  for (int i = n - 1; i >= 0; --i) {
    int index = a[i].Y;
    p[index] = index;
    unite(index, index - 1);
    unite(index, index + 1);
    ans[size[index]] = max(ans[size[index]], a[i].X);
  }
  for (int i = n - 1; i >= 0; --i)
    ans[i] = max(ans[i], ans[i+1]);
  for (int i = 1; i <= n; ++i)
    printf("%d ", ans[i]);
  printf("\n");
  return 0;
} 
