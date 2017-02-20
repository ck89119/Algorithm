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

bool cmp(const string &a, const string &b) {
  return a + b > b + a;
}

class Solution {
public:
  string IntToString(int n) {
    if (n == 0) return "0";
    string ans = "";
    while (n) {
      ans += '0' + n % 10;
      n /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }

  string largestNumber(vector<int>& nums) {
    vector<string> strs;
    for (auto x: nums) {
      string str_x = IntToString(x);
      strs.push_back(str_x);
    }
    sort(strs.begin(), strs.end(), cmp);
    string ans = "";
    for (auto s: strs)
      ans += s;
    if (ans[0] == '0') return "0";
    else return ans;
  }
};

int main() {
#ifndef ONLINE_JUDGE
  // freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  Solution *s = new Solution();
  vector<int> v = {9, 99, 98, 8, 0};
  cout << s->largestNumber(v) << endl;
  return 0;
}
