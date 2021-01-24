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
      ans.push_back(n%10);
      n /= 10;
    }
    return ans;
  }

  int get_n(const vector<int> &digits) {
    int ans = 0;
    for (int i = digits.size()-1; i >= 0; --i) {
      ans = ans * 10 + digits[i]; 
    }
    return ans;
  }

  int monotoneIncreasingDigits(int N) {
    vector<int> digits = get_digits(N);
    int n = digits.size();
    int i = n-2;
    while (digits[i] >= digits[i+1] && i >= 0) --i;
    if (i < 0) return get_n(digits);
    
    ++i;
    while (i < n-1 && digits[i] <= digits[i+1]) ++i;
    --digits[i];
    for (int j = i-1; j >= 0; --j) digits[j] = 9;
    return get_n(digits);
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  Solution s;
  cout << s.monotoneIncreasingDigits(10) << endl;
  cout << s.monotoneIncreasingDigits(1234) << endl;
  cout << s.monotoneIncreasingDigits(322) << endl;
  return 0;
}
