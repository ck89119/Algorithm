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

vector<int> get_digits(int n) {
  vector<int> s;
  while (n) {
    s.push_back(n % 10);
    n /= 10;
  }
  return s;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  for (int i = 100; i < 1000; ++i) {
    if (i * 3 >= 1000) continue;
    vector<bool> used(10);
    for (int j = 1; j <= 3; ++j)
      for (auto d: get_digits(i * j))
        used[d] = true;
    int flag = 0;
    for (int i = 1; i < 10; ++i)
      if (!used[i]) {
        flag = 1;
        break;
      }
    if (!flag) printf("%d %d %d\n", i, 2*i, 3*i);
  }
  return 0;
}
