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
  double eps = 0.00001;
  bool judgePoint24(vector<int>& nums) {
    vector<double> d_nums;
    for (auto num: nums) d_nums.push_back((double)num);
    return judge(d_nums); 
  }

  bool judge(vector<double>& nums) {
    int n = nums.size();
    if (n == 1) return abs(nums[0]-24) < eps;
    
    for (int i = 0; i < n; ++i)
      for (int j = i+1; j < n; ++j) {
        vector<double> v(n-1);
        for (int k = 0, cnt = 0; k < n; ++k)
          if (k != i && k != j) v[cnt++] = nums[k];
        double a = nums[i], b = nums[j];
        vector<double> x = {a+b, a-b, b-a, a*b};
        if (abs(a) > eps) x.push_back(b/a);
        if (abs(b) > eps) x.push_back(a/b);
        for (auto num: x) {
          v[n-2] = num;
          if (judge(v)) return true;
        }
      }
    return false;
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  
  return 0;
}
