#include <bits/stdc++.h>
using namespace std;

#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0xc0
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
const int N = 100000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

class Solution {
public:
    int sum(int n) {
      int ans = 0;
      while (n) {
        int digit = n % 10;
        ans += digit * digit;
        n /= 10;
      }
      return ans;
    }

    bool search(int n, int *vis) {
      if (n == 1) return true;
      if (n >= 1000) return search(sum(n), vis);

      vis[n] = 1;
      if (vis[sum(n)]) return false;
      return search(sum(n), vis);
    }

    bool isHappy(int n) {
      int vis[1000];
      clr(vis, 0);
      return search(n, vis);
    }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif

  return 0;
}
