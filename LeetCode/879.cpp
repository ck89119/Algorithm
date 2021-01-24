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
const int N = 100 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

class Solution {
 public:
  int profitableSchemes(int G, int P, vector<int>& group, vector<int>& profit) {
    int n = group.size();
    // dump(n);
    int f[N][N];
    clr(f, 0); f[0][0] = 1;

    for (int i = 0; i < n; ++i)
      for (int j = G; j >= 0; --j)
        for (int k = P; k >= 0; --k) {
          int nj = j + group[i];
          int nk = min(P, k + profit[i]);
          if (nj > G) continue;
          (f[nj][nk] += f[j][k]) %= MOD;
        }
    ll ans = 0;
    for (int j = 0; j <= G; ++j)
      (ans += f[j][P]) %= MOD;
    return ans;  
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  vector<int> group, profit;
  group.push_back(2);
  group.push_back(3);
  group.push_back(5);
  profit.push_back(6);
  profit.push_back(7);
  profit.push_back(8);
  Solution s;
  cout << s.profitableSchemes(10, 5, group, profit) << endl;
  return 0;
}
