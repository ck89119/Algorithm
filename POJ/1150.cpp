//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <vector>

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
int n, m;
int mul[4][4] = {
  {6, 2, 4, 8},
  {1, 3, 9, 7},
  {1, 7, 9, 3},
  {1, 9, 1, 9}
};

int g(int n, int x) {
  if (n == 0) return 0;
  if (x == 2 || x == 5) 
    return n / x + g(n / x, x);
  else 
    return n / 10 + (x <= n % 10) + g(n / 5, x);
}

int f(int n, int x) {
  if (n == 0) return 0;
  else return f(n / 2, x) + g(n, x);
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif

  while (scanf("%d%d", &n, &m) != EOF) {
    int n2 = g(n, 2) - g(n-m, 2);
    int n5 = g(n, 5) - g(n-m, 5);
    int n3 = f(n, 3) - f(n-m, 3);
    int n7 = f(n, 7) - f(n-m, 7);
    int n9 = f(n, 9) - f(n-m, 9);

    int ans = 1;
    if (n2 < n5) {
      ans = 5;
    }
    else {
      if (n2 > n5) ans = ans * mul[0][(n2 - n5) % 4] % 10;
      ans = ans * mul[1][n3 % 4] % 10;
      ans = ans * mul[2][n7 % 4] % 10;
      ans = ans * mul[3][n9 % 4] % 10;
    }
    printf("%d\n", ans);
  }

  return 0;
}
