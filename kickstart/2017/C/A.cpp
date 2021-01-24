#include <bits/stdc++.h>
using namespace std;

#define dump(x) cout <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0xc0
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define lowbit(x) x & (-x)
typedef long long ll;
typedef pair<int, int> pii;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 50 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int main() {
#ifndef ONLINE_JUDGE
  freopen("A-large-practice.in", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int T;
  scanf("%d", &T);
  for (int ncase = 1; ncase <= T; ++ncase) {
    char s[N];
    scanf("%s", s);
    int n = strlen(s);
    if (n & 1) {
      printf("Case #%d: AMBIGUOUS\n", ncase);
      continue;
    }
    
    char ans[N];
    ans[1] = s[0]; ans[n-2] = s[n-1];
    for (int i = 3; i < n; i += 2) {
      int a = ans[i-2] - 'A';
      int b = s[i-1] - 'A';
      int x = (b - a + 26) % 26;
      ans[i] = 'A' + x;
    }
    for (int i = n-4; i >= 0; i -= 2) {
      int a = ans[i+2] - 'A';
      int b = s[i+1] - 'A';
      int x = (b - a + 26) % 26;
      ans[i] = 'A' + x;
    }
    ans[n] = '\0';
    printf("Case #%d: %s\n", ncase, ans);
  }
  return 0;
}
