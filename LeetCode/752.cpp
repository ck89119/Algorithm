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
const int N = 10000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

class Solution {
 public:
  int dx[2] = {1, 9};
  int str2int(const string &s) {
    istringstream is(s);
    int n;
    is >> n;
    return n;
  }

  int get_num(int digits[4]) {
    int base = 1;
    int ans = 0;
    for (int i = 0; i < 4; ++i) {
      ans += digits[i] * base;
      base *= 10;
    }
    return ans;
  }

  int openLock(vector<string>& deadends, string target) {
    set<int> deadends_s;
    for (auto d: deadends)
      deadends_s.insert(str2int(d));
    if (deadends_s.find(0) != deadends_s.end()) return -1;
    
    int target_int = str2int(target);
    int cnt[N];
    clr(cnt, 0x3f); cnt[0] = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    while (!q.empty()) {
      auto p = q.front(); q.pop();
      int status = p.first;
      int step = p.second;
      if (status == target_int) return step;

      int digits[4];
      digits[0] = status % 10; status /= 10;
      digits[1] = status % 10; status /= 10;
      digits[2] = status % 10; status /= 10;
      digits[3] = status % 10; status /= 10;
      
      for (int i = 0; i < 4; ++i) {
        int t = digits[i];
        for (int j = 0; j < 2; ++j) {
          digits[i] = (t + dx[j]) % 10;
          int n = get_num(digits);
          if (deadends_s.find(n) != deadends_s.end()) continue;
          if (step + 1 < cnt[n]) {
            cnt[n] = step + 1;
            q.push(make_pair(n, step+1));
          }
        }
        digits[i] = t;
      }
    }
    return -1;
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  vector<string> deadends = {"0201","0101","0102","1212","2002"};
  Solution s;
  cout << s.openLock(deadends, "0202") << endl;
  return 0;
}
