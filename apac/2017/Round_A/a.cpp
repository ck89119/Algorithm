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
const int N = 100 + 5;
const int M = 10000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n;
char names[N][M];
int cnt[N];

int main() {
#ifndef ONLINE_JUDGE
  freopen("A-large-practice.in", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int T;
  scanf("%d", &T);
  for (int ncase = 1; ncase <= T; ++ncase) {
    printf("Case #%d: ", ncase);
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; ++i) {
      gets(names[i]);
      // dump(names[i]);
      int alpha[26] = {0};
      for (int j = 0; names[i][j]; ++j) {
        // dump(names[i][j]);
        if (names[i][j] >= 'A' && names[i][j] <= 'Z')
          ++alpha[names[i][j]-'A'];
      }
      cnt[i] = 0;
      for (int j = 0; j < 26; ++j) {
        // dump(alpha[j]);
        if (alpha[j]) ++cnt[i];
      }
      // dump(cnt[i]);
    }
    
    int max_cnt = 0;
    int max_idx = -1;
    for (int i = 0; i < n; ++i) {
      if (cnt[i] > max_cnt) {
        max_cnt = cnt[i];
        max_idx = i;
      } else if (cnt[i] == max_cnt) {
        if (strcmp(names[i], names[max_idx]) < 0)
          max_idx = i;
      }
    }
    printf("%s\n", names[max_idx]); 
  }
  return 0;
}
