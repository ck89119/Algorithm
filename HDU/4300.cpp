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
char f[30], inv_f[30];
int la, lb;

int EKMP() {
  int i, j, p0;

  fail[0] = lb;
  for (j = 0; j + 1 < lb; ++j)
    if (b[j] != b[j+1]) break;
  fail[1] = j;
  
  p0 = 1;
  for (i = 1; i < lb - 1; ++i) {
    int len = fail[i-p0+1];
    int p = p0 + fail[p0] - 1;
    if (len + i < p) {
      fail[i+1] = len;
    } else {
      j = max(p - i, 0);
      while (i + 1 + j < lb && j < lb) {
        if (b[i+1+j] != b[j]) break;
        ++j;
      }
      fail[i+1] = j;
      p0 = i + 1;
    }
  }
  
  for (i = 0, j = 0; i < la && j < lb; ++i, ++j)
    if (a[i] != b[j]) break;
  ekmp[0] = i;
  
  p0 = 0;
  for (int i = 0; i < la - 1; ++i) {
    int len = fail[i-p0+1];
    int p = p0 + ekmp[p0] - 1;
    if (len + i < p) {
      ekmp[i+1] = len;
    } else {
      j = max(p - i, 0);
      while (i + 1 + j < la && j < lb) {
        if (a[i+1+j] != b[j]) break;
        ++j;
      }
      ekmp[i+1] = j;
      p0 = i + 1;
    }
  }
  return 0;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif
  int ncase;
  scanf("%d", &ncase);
  while (ncase--) {
    scanf("%s", f);
    for (int i = 0; i < 26; ++i)
      inv_f[f[i]-'a'] = 'a' + i;

    scanf("%s", b);
    la = lb = strlen(b);
    for (int i = 0; i < lb; ++i)
      a[i] = f[b[i] - 'a'];
    a[la] = '\0';
    EKMP();
  
    int l = 0;
    for (int i = la - la / 2; i < la; ++i)
      if (i + ekmp[i] == la)
        l = max(l, ekmp[i]);
    l = la - l;

    for (int i = 0; i < l; ++i)
      b[i+l] = inv_f[b[i]-'a'];
    b[2*l] = '\0';
    printf("%s\n", b);
  }
  return 0;
}
