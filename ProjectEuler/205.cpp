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

int sum[2][40];

int dfs(int l, int type, int s) {
  if (l == 0) {
    ++sum[type][s];
    return 0;
  }

  int up = type == 0 ? 4 : 6;
  for (int i = 1; i <= up; ++i)
    dfs(l-1, type, s+i);
  return 0;
}


int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  clr(sum, 0); 
  dfs(9, 0, 0);
  dfs(6, 1, 0);
  ll total = pow(4, 9) * pow(6, 6);
  ll cnt = 0;
  int s = 0;
  for (int i = 0; i <= 36; ++i) {
    cnt += sum[0][i] * s;
    s += sum[1][i]; 
  }
  printf("%.7lf\n", 1.0 * cnt / total);
  return 0;
}
