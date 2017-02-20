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
const int N = 50000 + 5;
const int M = 20 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n, a[M];
int f[1<<M];

int search(int length, int bit_mask, int target) {
  if (f[bit_mask] != -1) return f[bit_mask];
  if (length > target) return 0;
  if (length == target) {
    if (bit_mask == (1 << n) - 1) {
      return 1;
    }
    length = 0;
  }
  
  int &ans = f[bit_mask];
  ans = 0;
  for (int i = 0; i < n; ++i)
    if ((bit_mask & (1 << i)) == 0 && search(length + a[i], bit_mask | (1 << i), target))
      ans = 1;
  return ans;
}


int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int t;
  scanf("%d", &t);
  while (t--) {
    int sum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
      sum += a[i];
    }

    int target = sum / 4;
    if (target * 4 != sum) {
      printf("no\n");
      continue;
    }
    
    clr(f, -1);
    printf("%s\n", search(0, 0, target) ? "yes" : "no");
  }
  return 0;
}
