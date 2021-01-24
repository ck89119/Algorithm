/*
ID: ck89119
PROG:
LANG: C++
*/
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
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
const int N = 100005;
const int M = 9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;
const int CHILD_NUM = 26;
const int MOD = 1000000007;

LL n;
int inv[N];

int is_prime(LL x) {
  for (int i = 2; i * i <= x; ++i) 
    if (x % i == 0) return 0;
  return 1;
}

int init() {
  inv[1] = 1;
  for (int i = 2; i < n; ++i)
    inv[i] = (n - (n / i) * inv[n % i] % n) % n;
  return 0;
}

int main() {
  //#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  //#endif
  scanf("%I64d", &n);
  if (!is_prime(n) && n != 1 && n != 4) {
    printf("NO\n");
    return 0;
  }
    
  if (n == 4) {
    printf("YES\n");
    printf("1\n3\n2\n4\n");
    return 0;
  }

  init();
  printf("YES\n1\n");
  for (int i = 2; i < n; ++i) {
    printf("%I64d\n", (LL)i * inv[i-1] % n);
  }
  if (n != 1) {
    printf("%d\n", n);
  }
  return 0;
}
