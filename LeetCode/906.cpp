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
  ll pow_10(int n) {
    ll ans = 1;
    while (n--) {
      ans *= 10;
    }
    return ans;
  }

  bool is_palindrome(ll n) {
    string s = ll2str(n);
    int l = 0;
    int r = s.size() - 1;
    while (l < r) {
      if (s[l] != s[r]) return false;
      ++l, --r;
    }
    return true;
  }

  string ll2str(ll n) {
    ostringstream sout;
    sout << n;
    return sout.str();
  }

  ll str2ll(string s) {
    istringstream sin(s);
    ll n;
    sin >> n;
    return n;
  } 

  int get(ll n) {
    int ans = 0;
    for (int d = 0; d < 10; ++d) {
      ll x = d * d;
      if (x > n) break;
      ans += is_palindrome(x);
    }

    for (int len = 1; ; ++len) {
      bool f = false;
      for (int i = pow_10(len-1); i < pow_10(len); ++i) {
        string s = ll2str(i);
        string rs = s;
        reverse(rs.begin(), rs.end());
        s += rs;
        // dump(s);
        ll x = str2ll(s);
        x *= x;
        if (x > n) {
          f = true;
          break;
        }
        ans += is_palindrome(x);
      }
      if (f) break;

      for (int i = pow_10(len-1); !f && i < pow_10(len); ++i) {
        string s = ll2str(i);
        string rs = s;
        reverse(rs.begin(), rs.end());
        for (int d = 0; d < 10; ++d) {
          string ns = s + ll2str(d) + rs;
          // dump(ns);
          ll x = str2ll(ns);
          x *= x;
          if (x > n) {
            f = true;
            break;
          }
          ans += is_palindrome(x);
        }
      }
    } 
    return ans;
  }

  int superpalindromesInRange(string L, string R) {
    return get(str2ll(R)) - get(str2ll(L)-1);
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  Solution s;
  cout << s.get(19028) << endl;
  return 0;
}
