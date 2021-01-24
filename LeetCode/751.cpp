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
  ll ip2ll(string ip) {
    ll ans = 0;
    int i = 0;
    while (i < ip.size()) {
      if (ip[i] == '.') ++i;
      ll sec = 0;
      int j = i;
      while (j < ip.size() && ip[j] != '.') {
        sec = sec * 10 + ip[j] - '0';
        ++j;
      }
      ans = (ans << 8) + sec;
      i = j;
    }
    return ans;
  }

  string ll2str(ll n) {
    ostringstream os;
    os << n; 
    return os.str();
  }

  string parse(ll ip, ll mask) {
    string ans;
    for (int i = 0; i < 4; ++i) {
      ll masked = ip & 0xff; ip >>= 8;
      ans = "." + ll2str(masked) + ans; 
    }
    ans = ans.substr(1);
    ans += "/";

    ll mask_len = 0;
    while (mask) {
      ++mask_len;
      mask >>= 1;
    }
    ans += ll2str(33-mask_len);
    return ans;
  }

  vector<string> ipToCIDR(string ip, int range) {
    ll l = ip2ll(ip);
    ll r = l + range; 
    vector<pair<ll, ll>> ans_ll;
    while (l < r) {
      ll lb = lowbit(l);
      while (l + lb > r) lb >>= 1;
      ans_ll.push_back(make_pair(l, lb));
      l += lb;
    }
    
    vector<string> ans;
    for (auto p: ans_ll) {
      ans.push_back(parse(p.first, p.second)); 
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
  out(s.ipToCIDR("255.0.0.7", 10));
  out(s.ipToCIDR("255.0.0.7", 9));
  out(s.ipToCIDR("255.0.0.7", 8));
  return 0;
}
