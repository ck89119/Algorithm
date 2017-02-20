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
  string int_to_string(ll a) {
    string s;
    if (a == 0) {
      s += '0';
      return s;
    }
    
    vector<char> tmp;
    while (a) {
      tmp.push_back('0' + a % 10);
      a /= 10;
    }
    for (int i = tmp.size() - 1; i >= 0; --i)
      s += tmp[i];

    return s; 
  }

  string fractionToDecimal(int numerator, int denominator) {
    if (numerator == 0) return int_to_string(0);

    ll num = numerator;
    ll den = denominator;
    int op = 0;
    if (num < 0) {
      num = -num;
      op += 1;
    }
    if (den < 0) {
      den = -den;
      op += 1;
    }

    ll d = num / den; 
    ll r = num % den; 
    string ans;
    if (op & 1) ans += '-';
    ans += int_to_string(d); 

    if (r == 0) {
      return ans;
    }

    ans += '.';
    vector<pair<ll, ll>> remainder;
    while (r) {
      r *= 10;
      d = r / den;
      r = r % den;
      pair<ll, ll> p = make_pair(d, r);

      int flag = 0;
      for (int i = 0; i < remainder.size(); ++i)
        if (remainder[i] == p) {
          for (int j = 0; j < i; ++j)
            ans += int_to_string(remainder[j].first);
          ans += '(';
          for (int j = i; j < remainder.size(); ++j)
            ans += int_to_string(remainder[j].first);
          ans += ')';
          flag = 1;
          break;
        }
      if (flag) return ans;
      remainder.push_back(p);
    }
    
    for (int i = 0; i < remainder.size(); ++i)
      ans += int_to_string(remainder[i].first);
    return ans;
  }
};

int main() {
#ifndef ONLINE_JUDGE
  // freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  Solution *s = new Solution();
  cout << s->fractionToDecimal(-1, -2147483648) << endl;
  return 0;
}
