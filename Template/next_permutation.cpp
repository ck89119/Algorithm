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

int next_permutation(int *a, int n) {
  for (int i = n-1; i > 0; i--) {
    if (a[i-1] < a[i]) {
      int j = n-1;
      while (a[i-1] >= a[j]) j--;
      swap(a[i-1], a[j]);
      sort(a+i, a+n);
      return 0;
    }
  }
  sort(a, a+n);
  return 0;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
#endif
  int n = 5;
  int a[5] = {3, 2, 5, 4, 1};
  next_permutation(a, n);
  out(a, 5);
  return 0;
} 
