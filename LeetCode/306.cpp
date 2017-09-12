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
  ll str2int(string s) {
    istringstream sin(s);
    ll t;
    sin >> t;
    return t;
  }

  bool dfs(int cur, ll n1, ll n2, const string &num) {
    if (cur >= num.size()) return true;
    
    if (num[cur] == '0') {
      if (n1 + n2 == 0 && dfs(cur+1, n2, 0, num)) return true;
    } else {
      for (int l = 1; cur + l <= num.size(); ++l) {
        ll n3 = str2int(num.substr(cur, l));
        if (n1 + n2 == n3) {
          if (dfs(cur+l, n2, n3, num)) return true;
        }
      }
    }
    return false;
  }

  bool isAdditiveNumber(string num) {
    if (num.size() < 3) return false;
    
    if (num[0] == '0') {
      if (num[1] == '0') {
        if (dfs(1, 0, 0, num)) return true;
      } else {
        for (int j = 1; j <= num.size() - 1; ++j) {
          ll n2 = str2int(num.substr(0, j));
          if (dfs(j, 0, n2, num)) return true;
        }
      }
    } else {
      for (int i = 1; i <= num.size() - 2; ++i) {
        ll n1 = str2int(num.substr(0, i));
        if (num[i] == '0') {
          if (dfs(i+1, n1, 0, num)) return true;
        } else {
          for (int j = i + 1; j <= num.size() - 1; ++j) {
            ll n2 = str2int(num.substr(i, j-i));
            if (dfs(j, n1, n2, num)) return true;
          }
        }
      }
    }
    return false;
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  Solution s;
  cout << s.isAdditiveNumber("0") << endl;
  cout << s.isAdditiveNumber("10") << endl;
  cout << s.isAdditiveNumber("101") << endl;
  cout << s.isAdditiveNumber("112358") << endl;
  cout << s.isAdditiveNumber("199100199") << endl;
  cout << s.isAdditiveNumber("0235813") << endl;
  cout << s.isAdditiveNumber("121474836472147483648") << endl;
  return 0;
}
