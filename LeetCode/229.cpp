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
  vector<int> majorityElement(vector<int>& nums) {
    int n1, n2, cnt1, cnt2;
    n1 = n2 = cnt1 = cnt2 = 0;
    for (auto n: nums) {
      if (n == n1) ++cnt1;
      else if (n == n2) ++cnt2;
      else if (cnt1 == 0) n1 = n, cnt1 = 1;
      else if (cnt2 == 0) n2 = n, cnt2 = 1;
      else --cnt1, --cnt2;
    }
    
    vector<int> ans;
    cnt1 = cnt2 = 0;
    for (auto n: nums)
      if (n == n1) ++cnt1;
      else if (n == n2) ++cnt2;
    if (cnt1 > nums.size() / 3) ans.push_back(n1);
    if (cnt2 > nums.size() / 3) ans.push_back(n2);
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
