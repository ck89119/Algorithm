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
  vector<int> advantageCount(vector<int>& A, vector<int>& B) {
    int n = A.size();
    vector<pii> a, b;
    for (int i = 0; i < n; ++i) {
      a.emplace_back(A[i], i);
      b.emplace_back(B[i], i);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    vector<int> ans(n);
    stack<int> unused;
    int i = 0;
    int j = 0;
    while (i < n && j < n) {
      int a_v = a[i].first;
      int b_v = b[j].first;
      int b_i = b[j].second;

      if (a_v > b_v) {
        ans[b_i] = a_v;
        ++i, ++j;
      } else {
        unused.push(a_v);
        ++i; 
      }
    }
    for (; j < n; ++j) {
      int b_i = b[j].second;
      ans[b_i] = unused.top(); unused.pop(); 
    } 
    return ans;
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  
  return 0;
}
