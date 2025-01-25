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
const int N = 100000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  int x1, y1, x2, y2, x, y; 
  int ret = 0;
  while (scanf("Button A: X+%d, Y+%d\n", &x1, &y1) != EOF) {
    scanf("Button B: X+%d, Y+%d\n", &x2, &y2);
    scanf("Prize: X=%d, Y=%d\n", &x, &y);
    // dump(x1), dump(y1);
    // dump(x2), dump(y2);
    // dump(x), dump(y);
    
    int ans = INF;
    for (int i = 0; i <= 100; ++i)
      for (int j = 0; j <= 100; ++j)
        if (x1 * i + x2 * j == x && y1 * i + y2 * j == y) {
          ans = min(ans, 3 * i + j);
        }

    if (ans != INF) ret += ans;
  }
  printf("%d\n", ret);
  return 0;
}
