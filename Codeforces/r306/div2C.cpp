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
const int N = 105;
const int M = 9999999;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

char s[N];
int len_s;

int contain(int x) {
  int i = len_s - 1;
  if (x == 0) {
    while (i >= 0) {
      if (s[i] == '0') return 1;
      --i;
    }
    return 0;
  }

  while (x) {
    char ch = '0' + x % 10;
    int flag = 0;
    while (i >= 0) {
      if (s[i] == ch) { --i; flag = 1; break; }
      --i;
    }
    //dump(x); dump(ch); dump(flag);
    if (!flag) return 0;
    x /= 10;
  }
  return 1;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif
  scanf("%s", s);
  len_s = strlen(s);
  //contain(344);
  for (int i = 0; i * 8 < 800; ++i) {
    if (contain(i * 8)) {
      printf("YES\n%d\n", i * 8);
      return 0;
    }
  }
  printf("NO\n");
  return 0;
}
