#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
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
// fail[i] means the end index of the largest prefix of b,
// which equals one of the suffixes of b[0..i]
int fail[N];
// kmp[i] means the end index of the largest prefix of b,
// which equals one of the suffixes of a[0..i]
int kmp[N];

int KMP() {
  int la = strlen(a);
  int lb = strlen(b);
  int j;
  fail[0] = j = -1;
  for (int i = 1; i < lb; ++i) {
    while (j >= 0 && b[i] != b[j+1]) j = fail[j];
    if (b[i] == b[j+1]) ++j;
    fail[i] = j;
  }
  out(fail, lb);

  j = -1;
  for (int i = 0; i < la; ++i) {
    dump(a[i]);
    dump(b[j+1]);
    while (j >= 0 && a[i] != b[j+1]) j = fail[j];
    if (a[i] == b[j+1]) ++j;
    kmp[i] = j;
  }
  out(kmp, la);
  return 0;
}


int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif
  scanf("%s", a);
  scanf("%s", b);
  KMP();
  return 0;
}
