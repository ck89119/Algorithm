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
  int shortestSubarray(vector<int>& A, int K) {
    vector<pair<ll, int>> sums;
    ll sum = 0;
    sums.emplace_back(sum, 0);
    for (int i = 0; i < A.size(); ++i) {
      sum += A[i];
      sums.emplace_back(sum, i+1);
    }
    sort(sums.begin(), sums.end());

    // for (int i = 0; i < sums.size(); ++i) {
    //   cout << "(" << sums[i].first << ", " << sums[i].second << "), ";
    // }
    // cout << endl;
    
    int ans = INF;
    int l = 0;
    set<int> indice;
    for (int i = 1; i < sums.size(); ++i) {
      ll s = sums[i].first;
      int idx = sums[i].second;
      while (l < i && s - sums[l].first >= K) {
        indice.insert(sums[l].second);
        ++l;
      } 
      auto it = indice.lower_bound(sums[i].second);
      if (it != indice.begin()) {
        --it;
        ans = min(ans, idx - *it);
      }
      // dump(i), dump(idx), dump(ans);
      // dump("$$$$$");
   }
    return ans == INF ? -1 : ans;
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  vector<int> a;
  a.push_back(45);
  a.push_back(95);
  a.push_back(97);
  a.push_back(-34);
  a.push_back(-42);
  int k = 21;

  // a.push_back(56);
  // a.push_back(-21);
  // a.push_back(56);
  // a.push_back(35);
  // a.push_back(-9);
  // int k = 61;

  Solution s;
  cout << s.shortestSubarray(a, k) << endl;
  return 0;
}
