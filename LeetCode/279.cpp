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

class Solution {
 public:
  int max_sqrt(int n) {
    if (n == 0 || n == 1) return n;

    int l = 0;
    int r = n;
    while (l + 1 < r) {
      int m = l + (r - l) / 2;
      if (m * m > n) r = m;
      else l = m;
    }
    return l;
  }

  int search(int n, vector<int> &f) {
    if (n == 0) return 0;
    if (f[n] != -1) return f[n];
    int ans = INF;
    for (int i = max_sqrt(n); i >= 1; --i) {
      ans = min(ans, search(n-i*i, f) + 1);
    }
    return f[n] = ans;
  }

  int numSquares(int n) {
    vector<int> f(n+1, -1);
    return search(n, f);
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  Solution s;
  cout << s.numSquares(5) << endl;
  return 0;
}
