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
const int N = 99999;
const int M = 9999999;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int LIS(int a[], int n) {
  int top = 0;
  int b[N];
  for (int i = 0; i < n; ++i) {
    int p = lower_bound(b, b + top, a[i]) - b;
    if (p == top) b[top++] = a[i];
    else b[p] = a[i];
  }
  out(b, top);
  return 0;
}


int LNDS(int a[], int n) {
  int top = 0;
  int b[N];
  for (int i = 0; i < n; ++i) {
    int p = upper_bound(b, b + top, a[i]) - b;
    if (p == top) b[top++] = a[i];
    else b[p] = a[i];
  }
  out(b, top);
  return 0;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif
  int a[5] = {1,6,3,3,5};
  LIS(a, 5);
  LNDS(a, 5);
  return 0;
}
