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
const int N = 1000000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;


int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int n, k;
  set<int> a;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < k; ++i) {
    int tmp;
    scanf("%d", &tmp);
    a.insert(tmp - n);
  }
  
  queue<pair<int, int>> q;
  int cnt = 0;
  set<int> visited;
  q.push(make_pair(0, 0));
  while (!q.empty()) {
    auto p = q.front(); q.pop();
    int s = p.first;
    int t = p.second;
    if (s == 0) {
      ++cnt;
      if (cnt == 2) {
        printf("%d\n", t);
        return 0;
      }
    }

    for (auto v: a) {
      if (s + v > 1000 || s + v < -1000) continue;
      if (visited.find(s + v) != visited.end()) continue; 
      visited.insert(s + v);
      q.push(make_pair(s + v, t + 1));
    }
  }
  printf("-1\n");
  return 0;
}
