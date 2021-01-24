#include <bits/stdc++.h>
using namespace std;

#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0x80
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
const int N = 100 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int c[N][N];

int search(int a, int b) {
  int &ans = c[a][b];
  if (ans != -1) return ans;
  if (a == 1) return ans = search(a+1, b-2) + 1;
  if (b == 1) return ans = search(a-2, b+1) + 1;
  return ans = max(search(a-2, b+1), search(a+1, b-2)) + 1;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif
  int a, b;
  scanf("%d%d", &a, &b);
  clr(c, -1);
  for (int i = 0; i < N; ++i)
    c[0][i] = c[i][0] = 0;
  c[1][1] = 0;
  printf("%d\n", search(a, b));
  return 0;
}
