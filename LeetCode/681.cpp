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
  int str2int(string s) {
    istringstream is(s);
    int t;
    is >> t;
    return t;
  }

  string int2str(int t) {
    ostringstream os;
    os << t;
    string ans = os.str();
    if (t < 10) ans = "0" + ans;
    return ans;
  }

  string nextClosestTime(string time) {
    set<int> s;
    s.insert(time[0]-'0');
    s.insert(time[1]-'0');
    s.insert(time[3]-'0');
    s.insert(time[4]-'0');

    int cur = str2int(time.substr(0, 2)) * 60 + str2int(time.substr(3));
    pair<int, int> ans;
    int min = INF;
    for (auto a: s)
      for (auto b: s)
        for (auto c: s)
          for (auto d: s) {
            // dump(a), dump(b), dump(c), dump(d);
            int h = a * 10 + b;
            int m = c * 10 + d;
            if (h < 24 && m < 60) {
              int x = h * 60 + m;
              if (x <= cur) x += 24 * 60 * 60; 
              if (x - cur < min) {
                min = x - cur;
                ans = make_pair(h, m);
              }
            }
          }
      return int2str(ans.first) + ":" + int2str(ans.second);
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  Solution s;
  cout << s.nextClosestTime("19:34");
  return 0;
}
