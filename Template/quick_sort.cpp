#include <bits/stdc++.h>
using namespace std;

#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0xc0
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(x) x & (-x)
#define X first
#define Y second
typedef long long ll;
typedef pair<int, int> pii;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 100000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int sort(int a[], int left, int right) {
  if (left >= right) return 0;

  int p = a[right];
  int l = left;
  int r = right;
  do {
    while (l < r && a[l] <= p) ++l;
    while (l < r && a[r] >= p) --r;
    swap(a[l], a[r]);
  } while(l < r);
  a[right] = a[l];
  a[l] = p;

  sort(a, left, l - 1);
  sort(a, l + 1, right);
  return 0;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif
  int a[5] = {2, 1, 5, 3, 4};
  sort(a, 0, 4);
  out(a, 5);
  return 0;
}
