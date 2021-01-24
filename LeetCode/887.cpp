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
const int K = 100 + 5;
const int N = 10000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int f[K][N];

class Solution {
 public:
  int superEggDrop(int k, int n) {
    for (int j = 1; j <= n; ++j) f[1][j] = j;
    for (int i = 1; i <= k; ++i) f[i][0] = 0;
    
    for (int i = 2; i <= k; ++i)
      for (int j = 1; j <= n; ++j)
        f[i][j] = f[i-1][j-1] + f[i][j-1] + 1;  

    for (int j = 1; j <= n; ++j)
      if (f[k][j] >= n) return j;
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  Solution s;
  cout << s.superEggDrop(1, 2) << endl;
  cout << s.superEggDrop(2, 6) << endl;
  cout << s.superEggDrop(3, 14) << endl;
  return 0;
}
