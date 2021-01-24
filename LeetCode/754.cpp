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
  int reachNumber(int target) {
    queue<pair<int, int>> q;
    q.push(make_pair(1, 1));
    q.push(make_pair(1, -1));
    while (!q.empty()) {
      auto p = q.front(); q.pop();
      if (p.second == target) return p.first;
      q.push(make_pair(p.first + 1, p.second + p.first + 1));
      q.push(make_pair(p.first + 1, p.second - p.first - 1));
    }
    return 0;
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  Solution s;
  for (int i = 1; i < 100; ++i)
    cout << s.reachNumber(i) << endl;
  return 0;
}
