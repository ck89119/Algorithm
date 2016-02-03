#include <bits/stdc++.h>
using namespace std;

#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0x80
#define mp(A, B) make_pair(A, B)
#define pb(A) push_back(A)
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(x) x & (-x)
#define X first 
#define Y second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 2000;
const int M = 9999999;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n;
vector<int> l;

int dfs(int dep, int max_dep, int num) {
  if (dep == max_dep) {
    l.pb(num);
    return 0;
  }
  dfs(dep + 1, max_dep, num * 10 + 4);
  dfs(dep + 1, max_dep, num * 10 + 7);
  return 0;
}

int init() {
  for (int len = 1; len <= 9; ++len)
    dfs(0, len, 0);
  return 0;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif
  cin >> n;
  init();
  int p = lower_bound(l.begin(), l.end(), n) - l.begin();
  cout << p + 1 << endl;
  return 0;
}
