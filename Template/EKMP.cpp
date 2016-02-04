#include <bits/stdc++.h>
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
const int N = 200000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

char a[N], b[N];
// fail[i] means the longest common prefix of b[i..] and b
int fail[N];
// ekmp[i] means the longest common prefix of a[i..] and b
int ekmp[N];

int EKMP(char a[N], char b[N]) {
  int la = strlen(a);
  int lb = strlen(b);
  int j, k;
  for (j = 0; j + 1 < lb && b[j] == b[j+1]; ++j) {}
  fail[0] = lb; fail[1] = j;
  k = 1;
  for (int i = 2; i < lb; ++i) {
    int p = k + fail[k] - 1;
    int q = fail[i-k];
    if (p - i + 1 > q) {
      fail[i] = q;
    } else {
      j = max(0, p - i + 1);
      while (j < lb && b[i+j] == b[j]) ++j;
      fail[k = i] = j;
    }
  }
  //out(fail, lb);
 
  for (j = 0; j < la && j < lb && a[j] == b[j]; ++j) {}
  ekmp[0] = j;
  k = 0;
  for (int i = 1; i < la; ++i) {
    int p = k + ekmp[k] - 1;
    int q = fail[i-k];
    if (p - i + 1 > q) {
      ekmp[i] = q;
    } else {
      j = max(0, p - i + 1);
      while (i + j < la && j < lb && a[i+j] == b[j]) ++j;
      ekmp[k = i] = j;
    }
  }
  //out(ekmp, la);
  return 0;
}
