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
  int f[N];
  
  int search(int n) {
    if (f[n] != -1) return f[n];
    int ans = INF;
    for (int i = 1; i < n; ++i) {
      if (n % i) continue;
      ans = min(ans, search(i) + n / i);
    }
    return f[n] = ans;
  }

  int minSteps(int n) {
    clr(f, -1);
    f[1] = 0;
    return search(n);
  }
};

int main() {
#ifndef ONLINE_JUDGE
  // freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  Solution s;
  cout << s.minSteps(1000) << endl;
  cout << s.minSteps(29) << endl;
  cout << s.minSteps(3) << endl;
  cout << s.minSteps(4) << endl;
  return 0;
}
