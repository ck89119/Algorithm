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
  int leastInterval(vector<char>& tasks, int n) {
    int cnt[26];
    clr(cnt, 0);
    for (auto ch: tasks) {
      ++cnt[ch-'A'];
    }
    int m = -INF, k = 1;
    for (int i = 0; i < 26; ++i) {
      if (cnt[i] > m) {
        m = cnt[i];
        k = 1;
      } else if (cnt[i] == m) {
        ++k;
      }  
    }
    return max((int)tasks.size(), (m - 1) * (n + 1) + k);
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  
  return 0;
}
