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
  vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    auto i = lower_bound(arr.begin(), arr.end(), x);
    auto j = upper_bound(arr.begin(), arr.end(), x);
    k -= j - i;
    while (k) {
      if (i <= arr.begin()) ++j; 
      else if (j >= arr.end()) --i;
      else if (x - *(i - 1) <= *j - x) --i;
      else ++j;
      --k;
      dump(i-arr.begin()); dump(j-arr.begin());
      dump(k);
    }
    return vector<int>(i, j);
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  Solution s;
  vector<int> arr;
  arr.push_back(1);
  arr.push_back(2);
  arr.push_back(3);
  arr.push_back(4);
  arr.push_back(5);
  out(s.findClosestElements(arr, 4, 3));
  out(s.findClosestElements(arr, 4, -1));
  return 0;
}
