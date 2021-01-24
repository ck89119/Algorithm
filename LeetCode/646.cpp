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
const int N = 1000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int cmp(const vector<int> &a, const vector<int> &b) {
  if (a[0] != b[0]) return a[0] < b[0];
  else return a[1] < b[1];
}

class Solution {
 public:
  int search(int cur, int n, vector<int> &f, vector<vector<int>> &pairs) {
    if (cur >= n) return 0;
    if (f[cur] != -1) return f[cur];
    
    int ans = 0;
    for (int i = cur+1; i < n; ++i)
      ans = max(ans, search(i, n, f, pairs) + (pairs[i][0] > pairs[cur][1]));
    return f[cur] = ans; 
  }

  int findLongestChain(vector<vector<int>>& pairs) {
    sort(pairs.begin(), pairs.end(), cmp);
    int n = pairs.size();
    vector<int> f(n, -1);
    return search(0, n, f, pairs);
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  
  return 0;
}
