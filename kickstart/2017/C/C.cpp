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

int n, q;
int scores[N];
char answers[3][N];

int get_max(int n, int s, int score) {
  return n - abs(s - score); 
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("C-large-practice.in", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int T;
  scanf("%d", &T);
  for (int ncase = 1; ncase <= T; ++ncase) {
    scanf("%d%d", &n, &q); getchar();
    for (int i = 0; i <= n; ++i) scanf("%s", answers[i]);
    for (int i = 0; i < n; ++i) scanf("%d", &scores[i]);

    int same = 0;
    for (int i = 0; i < q; ++i)
      if (answers[0][i] == answers[1][i]) ++same;
    if (n == 1)  {
      printf("Case #%d: %d\n", ncase, get_max(q, same, scores[0]));
    } else {
      int diff = q - same;
      int x = (scores[0] + scores[1] - diff) / 2;
      int y = (scores[0] - scores[1] + diff) / 2;

      int s1 = 0;
      int s2 = 0;
      for (int i = 0; i < q; ++i)
        if (answers[0][i] == answers[1][i]) {
          s1 += answers[0][i] == answers[2][i]; 
        } else {
          s2 += answers[0][i] == answers[2][i]; 
        }
      printf("Case #%d: %d\n", ncase, get_max(same, s1, x) + get_max(diff, s2, y));
    }
  }
  return 0;
}
