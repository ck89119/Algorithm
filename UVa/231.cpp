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

int n;
vector<int> a;

int lis(vector<int> a) {
  vector<int> b;
  for (auto c: a) {
    auto it = lower_bound(b.begin(), b.end(), c);
    if (it == b.end()) b.push_back(c);
    else *it = c;
  }
  return b.size();
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif
  int tmp;
  int ncase = 1;
  while (scanf("%d", &tmp), tmp != -1) {
    a.clear();
    a.push_back(-tmp);
    while (scanf("%d", &tmp), tmp != -1)
      a.push_back(-tmp);
    if (ncase != 1) printf("\n");
    printf("Test #%d:\n", ncase++);
    printf("  maximum possible interceptions: %d\n", lis(a)); 
  }
  
  return 0;
}
