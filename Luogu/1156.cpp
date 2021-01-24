#include <bits/stdc++.h>
using namespace std;

#define dump(x) cout <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0xc0
typedef long long ll;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 1000000 + 5;
const int H = 100 + 26;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

struct Node {
  int t, f, h;
};

int cmp(const Node &a, const Node &b) {
  return a.t < b.t;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  int d, g;
  vector<Node> v;
  scanf("%d%d", &d, &g);
  for (int i = 0; i < g; ++i) {
    int t, f, h;
    scanf("%d%d%d", &t, &f, &h);
    v.push_back({t, f, h}); 
  }
  sort(v.begin(), v.end(), cmp); 

  int f[H];
  memset(f, 0, sizeof(f));
  f[0] = 10;
  for (int k = 0; k < g; ++k)
    for (int i = H-1; i >= 0; --i) {
      if (f[i] >= v[k].t) f[i] += v[k].f;
      if (i >= v[k].h && f[i-v[k].h] >= v[k].t) f[i] = max(f[i], f[i-v[k].h]);
      if (i >= d && f[i] >= v[k].t) {
        printf("%d\n", v[k].t);
        return 0;
      }
    }
  printf("%d\n", f[0]);
  return 0;
}