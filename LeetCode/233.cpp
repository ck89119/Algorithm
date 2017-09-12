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
  int countDigitOne(int n) {
    if (n == 0) return 0;

    int ans = 0;
    ll cur = 1, num = n;
    while (cur <= num) {
      // dump(cur * 10);
      int h = num / (cur * 10);
      int l = num % cur;
      int digit = num / cur % 10;
      if (digit > 1) {
        ans += (h + 1) * cur;
      } else if (digit == 1) {
        ans += h * cur + l + 1;
      } else {
        ans += h * cur;
      }
      cur *= 10;
    } 
    return ans;
  }
};

// class Solution {
//  public:
//   int f[35][35][2];
//   int digits[35];

//   int dfs(int pos, int num, int limit) {
//     if (pos < 0) return num;
//     if (f[pos][num][limit] != -1) return f[pos][num][limit];
      
//     int ans = 0;
//     int end = limit ? digits[pos] : 9;
//     for (int i = 0; i <= end; ++i) {
//       ans += dfs(pos-1, num + (i == 1), limit && i == end);
//     }
//     return  f[pos][num][limit] = ans;
//   }

//   int countDigitOne(int n) {
//     if (n == 0) return 0;

//     int pos = 0;
//     while (n) {
//       digits[pos++] = n % 10;
//       n /= 10;
//     }
//     clr(f, -1);
//     return dfs(pos-1, 0, 1);
//   }
// };

int main() {
#ifndef ONLINE_JUDGE
  // freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  Solution s;
  dump(s.countDigitOne(1410065408));
  return 0;
}
