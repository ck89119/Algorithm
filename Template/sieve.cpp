/*
ID: ck89119
PROG:
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl
#define CLR(a,x) memset(a,x,sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0x80
#define MP(A,B) make_pair(A,B)
#define PB(A) push_back(A)
#define PAU system("pause")
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(x) x & (-x)
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out (vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 99999;
const int M = 9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;
const int CHILD_NUM = 26;
const int MOD = 1000000007;

int phi[N], p[N];
int cnt;

int Euler(int n) {
  CLR(phi, 0);
  cnt = 0;

  phi[1] = 1;
  for (int i = 2; i <= n; ++i) {
    if (!phi[i]) {
      p[cnt++] = i;
      phi[i] = i - 1;
    }
    for (int j = 0; j < cnt && i * p[j] <= n; ++j) {
      if (i % p[j]) {
        phi[i * p[j]] = phi[i] * phi[p[j]];
      }
      else {
        phi[i * p[j]] = phi[i] * p[j];
        break;
      }
    }
  }
  return 0;
}

int Eartosthenes(int n) {
  CLR(phi, 0);
  cnt = 0;
  
  phi[1] = 1;
  for (int i = 2; i <= n; ++i)
    if (!phi[i]) {
      p[cnt++] = i;
      for (int j = i; j <= n; j += i) {
        if (!phi[j]) phi[j] = j;
        phi[j] = phi[j] / i * (i -1);
      }
    }
  return 0;
}

int main() {
  //#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  //#endif
  
  int n;
  cin >> n;
  Eartosthenes(n);
  out(phi, n);
  out(p, n);
  Euler(n);
  out(phi, n);
  out(p, n);
  return 0;
}
