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

#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0x80
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(x) x & (-x)
#define X first
#define Y second
typedef long long ll;
typedef pair<int, int> pii;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 100000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

char a[N], b[N];
// fail[i] means the longest common prefix of b[i..] and b
int fail[N];
// ekmp[i] means the longest common prefix of a[i..] and b
int ekmp[N];

int EKMP() {
  int la = strlen(a);
  int lb = strlen(b);
  int i, j, p0;

  fail[0] = lb;
  for (j = 0; j + 1 < lb; ++j)
    if (b[j] != b[j+1]) break;
  fail[1] = j;
  
  p0 = 1;
  for (i = 1; i < lb - 1; ++i) {
    dump(i);
    int len = fail[i-p0+1];
    int p = p0 + fail[p0] - 1;
    dump(len);
    dump(p0);
    dump(p);
    if (len + i < p) {
      dump("len + i < p");
      fail[i+1] = len;
    } else {
      dump("len + i >= p");
      j = max(p - i, 0);
      while (i + 1 + j < lb && j < lb) {
        if (b[i+1+j] != b[j]) break;
        ++j;
      }
      fail[i+1] = j;
      p0 = i + 1;
    }
  }
  out(fail, lb);
  
  for (i = 0, j = 0; i < la && j < lb; ++i, ++j)
    if (a[i] != b[j]) break;
  ekmp[0] = i;
  
  p0 = 0;
  for (int i = 0; i < la - 1; ++i) {
    dump(i);
    int len = fail[i-p0+1];
    int p = p0 + ekmp[p0] - 1;
    dump(len);
    dump(p0);
    dump(p);
    if (len + i < p) {
      dump("len + i < p");
      ekmp[i+1] = len;
    } else {
      dump("len + i >= p");
      j = max(p - i, 0);
      while (i + 1 + j < la && j < lb) {
        if (a[i+1+j] != b[j]) break;
        ++j;
      }
      ekmp[i+1] = j;
      p0 = i + 1;
    }
  }
  out(ekmp, la);
  return 0;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif
  scanf("%s", a);
  scanf("%s", b);
  EKMP();
  return 0;
}
