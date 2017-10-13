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
const int N = 55 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int main() {
#ifndef ONLINE_JUDGE
  freopen("B-small-practice.in", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int T;
  scanf("%d", &T);
  for (int ncase = 1; ncase <= T; ++ncase) {
    int n;
    char maze[N][N];
    scanf("%d", &n); getchar();
    for (int i = 0; i < n; ++i) scanf("%s", maze[i]);
    int c[N], r[N];
    clr(c, 0); clr(r, 0);
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        if (maze[i][j] == 'X') ++r[i], ++c[j];
  
    bool ans = true;
    for (int i = 0; i < n && ans; ++i) {
      if (r[i] != 1 && r[i] != 2) {
        ans = false;
        break;
      }
      if (r[i] == 1) {
        for (int j = 0; j < n; ++j)
          if (maze[i][j] == 'X' && c[j] !=1 ) {
            ans = false;
            break;
          }
      }
    }


    printf("Case #%d: %s\n", ncase, ans ? "POSSIBLE" : "IMPOSSIBLE"); 
  }
  return 0;
}
