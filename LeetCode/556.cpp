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
  vector<int> get_digits(int n) {
    vector<int> ans;
    if (n == 0) {
      ans.push_back(0);
      return ans;
    }
    while (n) {
      ans.push_back(n % 10);
      n /= 10;
    }
    return vector<int>(ans.rbegin(), ans.rend());
  }

  int get_int(const vector<int> &digits) {
    int ans = 0;
    for (auto digit: digits)
      ans = ans * 10 + digit;
    return ans;
  }

  int nextGreaterElement(int n) {
    vector<int> digits = get_digits(n);
    next_permutation(digits.begin(), digits.end());
    int new_n = get_int(digits);
    return new_n > n ? new_n : -1; 
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  
  return 0;
}
