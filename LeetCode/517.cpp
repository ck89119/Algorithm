#include <bits/stdc++.h>
using namespace std;

#define dump(x) cout <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
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
const int N = 10000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

class Solution {
 public:
  int findMinMoves(vector<int>& machines) {
    int n = machines.size();
    int sum = 0;
    for (int i = 0; i < n; ++i)
      sum += machines[i];
    if (sum % n) return -1;
    
    int avg = sum / n;
    int ans = 0;
    int balance = 0;
    for (int i = 0; i < n; ++i) {
      balance += machines[i] - avg;
      ans = max(ans, max(abs(balance), abs(machines[i]-avg)));
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
  vector<int> machines;
  machines.push_back(4);
  machines.push_back(0);
  machines.push_back(0);
  machines.push_back(4);
  cout << s.findMinMoves(machines) << endl;
  return 0;
}
