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

int kth(int l, int r, vector<int> &&v, int k) {
  // cout << "l = " << l << ", r = " << r << ", k = " << k << endl;
  if (l == r) return v[l];
  
  int p = v[l + rand() % (r - l + 1)], i = l, j = r;
  // int p = v[l], i = l, j = r;
  while (true) {
    while (v[i] < p) ++i;
    while (v[j] > p) --j;
    if (i >= j) break;

    swap(v[i++], v[j--]);
  }
  // cout << "i = " << i << ", j = " << j <<  ", p = " << p << ", v = ";
  // out(v);
  
  return k <= j - l + 1 ? kth(l, j, std::move(v), k) : kth(j + 1, r, std::move(v), k - (j - l + 1));
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  for (int i = 1; i <= 6; ++i) 
    cout << kth(0, 5, {3, 2, 1, 5, 6, 4}, i) << endl;
  cout << kth(0, 2, {1, 2, 2}, 2) << endl;
  return 0;
}
