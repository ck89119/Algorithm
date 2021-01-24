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
const int N = 1000005;
const int M = 9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;
const int CHILD_NUM = 26;
const int MOD = 1000000007;

int n;
int pre[N], Next[N];
int ans[N];


int main() {
  //#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  //#endif
  scanf("%d", &n);
  CLR(pre, -1); CLR(Next, -1);
  for (int i = 0; i < n; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    pre[b] = a;
    Next[a] = b;
  }
    
  if (n & 1) {
    int cur = 0;
    for (int i = 1; i < n; i += 2) {
      ans[i] = Next[cur];
      cur = Next[cur];
    }
    for (cur = 1; cur < N; ++cur)
      if (pre[cur] == -1 && Next[cur] != -1) break;
    for (int i = 0; i < n; i += 2) {
      ans[i] = cur;
      cur = Next[cur];
    }

  } else {
    int cur = 0;
    for (int i = 1; i < n; i += 2) {
      ans[i] = Next[cur];
      cur = Next[cur];
    }
    cur = 0;
    for (int i = n-2; i >= 0; i -= 2) {
      ans[i] = pre[cur];
      cur = pre[cur];
    }
  }
  
  for (int i = 0; i < n; ++i)
    printf("%d ", ans[i]);
  printf("\n");

  return 0;
}
