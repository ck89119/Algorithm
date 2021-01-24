#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
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
const int N = 10000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

struct Node {
  int l, p;
  bool operator<(const Node &a) const {
    return l < a.l;
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int n;
  int l, p;
  Node nodes[N];
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d%d", &nodes[i].l, &nodes[i].p);
  scanf("%d%d", &l, &p);
  for (int i = 0; i < n; ++i)
    nodes[i].l = l - nodes[i].l;
  nodes[n].l = l, nodes[n].p = 0;
  sort(nodes, nodes+n);
  
  int ans = 0;
  priority_queue<int> q;
  for (int i = 0; i <= n; ++i) {
    while (nodes[i].l > p) {
      if (q.empty()) {
        printf("-1\n");
        return 0;
      }
      p += q.top(); q.pop();
      ++ans;
    }
    q.push(nodes[i].p);
  } 
  printf("%d\n", ans);
  return 0;
}
