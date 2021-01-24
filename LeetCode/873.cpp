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
const int N = 1000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

class Solution {
 public:
  int lenLongestFibSubseq(vector<int>& a) {
    int n = a.size();
    int f[N][N];
    for (int i = 0; i < N; ++i)
      for (int j = 0; j < N; ++j)
        f[i][j] =2;

    int ans = 0;
    for (int j = 2; j < n; ++j)
      for (int i = 1; i < j; ++i) {
        int x = a[j] - a[i];
        if (x > a[i]) continue;
        auto idx = lower_bound(a.begin(), a.end(), x) - a.begin();
        if (a[idx] != x) continue; 
        f[i][j] = max(f[i][j], f[idx][i]);
        ans = max(ans, f[i][j]);
      }
    return ans;
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  
  return 0;
}
