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
const int N = 2000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int malted[N], unmalted[N][N], cnt[N];

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int t;
  scanf("%d", &t);
  for (int ncase = 1; ncase <= t; ++ncase) {
    int n, m;
    scanf("%d%d", &n, &m);
    memset(malted, -1, sizeof(malted));
    memset(unmalted, 0, sizeof(unmalted));
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < m; ++i) {
      int num;
      scanf("%d", &num);
      while (num--) {
        int x, y;
        scanf("%d%d", &x, &y);
        --x;
        if (y == 1) {
          malted[i] = x;
        } else {
          unmalted[i][x] = 1;
          ++cnt[i];
        }
      }
    }

    int choice[N];
    memset(choice, 0, sizeof(choice));
    int satisfied[N];
    memset(satisfied, 0, sizeof(satisfied));

    int possible = 1;
    while (true) {
      int update = 0;
      for (int i = 0; i < m; ++i) {
        if (cnt[i] == 0 && !satisfied[i]) {
          update = 1;
          int v = malted[i];
          if (v == -1) {
            possible = 0;
            break;
          }
          satisfied[i] = 1;
          if (choice[v]) continue;

          choice[v] = 1;
          for (int j = 0; j < m; ++j)
            if (unmalted[j][v]) {
              unmalted[j][v] = 0;
              --cnt[j];
            }
        }
      }
      if (!possible) break;
      if (!update) break;
    }

    printf("Case #%d: ", ncase);
    if (possible) {
      for (int i = 0; i < n; ++i) printf("%d ", choice[i]);
    } else {
      printf("IMPOSSIBLE");
    }
    printf("\n");
  }
  return 0;
}
