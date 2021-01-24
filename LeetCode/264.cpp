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
  int nthUglyNumber(int n) {
    vector<int> array(1, 1);
    int idx2 = 0;
    int idx3 = 0;
    int idx5 = 0;

    for (int i = 0; i < n; ++i) {
      int a = min(array[idx2] * 2, min(array[idx3] * 3, array[idx5] * 5));
      array.push_back(a);
      if (array[idx2] * 2 == a) ++idx2; 
      if (array[idx3] * 3 == a) ++idx3; 
      if (array[idx5] * 5 == a) ++idx5; 
    }
    return array[n-1]; 
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  
  return 0;
}
