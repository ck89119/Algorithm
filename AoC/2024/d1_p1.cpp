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

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  vector<int> v0, v1;
  int a, b;
  while (scanf("%d %d", &a, &b) != EOF) {
    v0.push_back(a);
    v1.push_back(b);
  }

  sort(v0.begin(), v0.end());
  sort(v1.begin(), v1.end());

  int ans = 0;
  for (int i = 0; i < v0.size(); i++) {
    ans += abs(v0[i] - v1[i]);
  }
  printf("%d\n", ans);
  return 0;
}
