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
  int is_prime(int n) {
    for (int i = 2; i * i < n; ++i) {
      if (n % i == 0) return 0;  
    }
    return 1;  
  }

  int xx10(int n) {
    int ans = 1;
    while (n--) ans *= 10;
    return ans;
  }

  int gen(int n, int over) {
    vector<int> digits;
    int ans = n;
    while (n) {
      digits.push_back(n % 10);
      n /= 10;
    }
    for (int i = over; i < digits.size(); ++i)
      ans = ans * 10 + digits[i];
    return ans;
  }

  int primePalindrome(int N) {
    vector<int> p;
    for (int w = 1; w <= 4; ++w) {
      int a = xx10(w-1);
      int b = xx10(w);
      for (int i = a; i < b; ++i) {
        p.push_back(gen(i, 1));
      }
      for (int i = a; i < b; ++i) {
        p.push_back(gen(i, 0));
      }
    }
    for (int i = 10000; i < 20000; ++i) {
      p.push_back(gen(i, 1));
    }
    out(p);

    for (auto it = lower_bound(p.begin(), p.end(), N); it != p.end(); ++it) {
      if (is_prime(*it)) return *it;
    }
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  Solution s;
  cout << s.primePalindrome(10502) << endl;
  return 0;
}

