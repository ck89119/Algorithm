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
  int dfs(int cur, int cnt, vector<bool> &visited, vector<int> &record, int k, int base) {
    visited[cur] = true;
    record[cnt] = cur;
    if (cnt == 0) return 1;
    for (int i = 0; i < k; ++i) {
      int num = (cur * 10 + i) % base;
      // dump(num);
      if (!visited[num]) {
        // dfs(num, cnt-1, visited, record, k, base);
        if (dfs(num, cnt-1, visited, record, k, base)) return 1;
      }
    }
    visited[cur] = false;
    return 0;
  }

  string crackSafe(int n, int k) {
    vector<bool> visited(10000, false);

    int total = pow(k, n);
    vector<int> record(total);
    dfs(0, total-1, visited, record, k, pow(10, n));
  
    string ans(n, '0');
    for (int i = total-2; i >= 0; --i) {
      // dump(i), dump(record[i]);
      ans += record[i] % 10 + '0';
      // dump(ans);
    }
    return ans;
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  Solution s;
  // cout << s.crackSafe(1, 2) << endl;
  // cout << s.crackSafe(2, 2) << endl;
  cout << s.crackSafe(2, 3) << endl;
  cout << s.crackSafe(4, 6) << endl;
  return 0;
}
