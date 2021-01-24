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
const int N = 10 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

class Solution {
 public:
  vector<int> numbers;
  int digits[N];
  int f[N][2][2];

  int dfs(int pos, int leading, int limit) {
    if (pos == -1) return 1;

    int &ans = f[pos][leading][limit];
    if (ans != -1) return ans;

    ans = 0;
    if (leading) {
      ans += dfs(pos-1, 1, limit && 0 == digits[pos]);
    }

    for (auto d: numbers) {
      if (limit && d > digits[pos]) break;
      ans += dfs(pos-1, 0, limit && d == digits[pos]);
    }

    return ans;
  }

  int char2int(const string &s) {
    return s[0] - '0';
  }

  int atMostNGivenDigitSet(vector<string>& D, int n) {
    for (auto s: D) numbers.push_back(char2int(s));
    int pos = 0;
    while (n) {
      digits[pos++] = n % 10;
      n /= 10;
    }
    clr(f, -1);
    return dfs(pos-1, 1, 1) - 1;
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  Solution s;
  vector<string> D;
  D.push_back("1");
  D.push_back("3");
  D.push_back("5");
  D.push_back("7");
  cout << s.atMostNGivenDigitSet(D, 100) << endl;
  return 0;
}
