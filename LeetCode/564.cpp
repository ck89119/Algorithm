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
  string ll2str(ll n) {
    ostringstream os;
    os << n;
    return os.str();
  }

  ll str2ll(string n) {
    istringstream is(n);
    ll ans;
    is >> ans;
    return ans;
  }

  string gen(int n, int l) {
    string s = ll2str(n);
    string rs(s.rbegin(), s.rend());
    // dump(s), dump(rs), dump(s.size()), dump(s.size()-l);
    return s + rs.substr(l);
  }

  string nearestPalindromic(string n) {
    if (n.size() == 0) return n;

    int len = n.size();
    set<ll> can;
    can.insert(ll(pow(10, len) + 1));
    can.insert(ll(pow(10, len-1) - 1));
    ll prefix = str2ll(n.substr(0, (len+1)/2));
    for (int d = -1; d <= 1; ++d)
      can.insert(str2ll(gen(prefix+d, len&1)));
    
    ll nn = str2ll(n);
    ll d = INF;
    string ans;
    for (auto c: can) {
      ll diff = abs(c - nn);
      // dump(c), dump(diff);
      if (diff == 0) continue;
      if (diff < d) {
        d = diff;
        ans = ll2str(c);
      } else if (diff == d && str2ll(ans) > c) {
        ans = ll2str(c);
      }
    }
    return ans;
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  Solution s;
  cout << s.nearestPalindromic("1000") << endl;
  cout << s.nearestPalindromic("21313") << endl;
  cout << s.nearestPalindromic("21399") << endl;
  cout << s.nearestPalindromic("99101") << endl;
  cout << s.nearestPalindromic("99") << endl;
  cout << s.nearestPalindromic("101") << endl;
  return 0;
}
