#include <bits/stdc++.h>
using namespace std;

#define dump(x) cout <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
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

struct SegmentTree {
  int n, h;
  int t[2*N];

  int get_h(int n) {
    int h = 0;
    while (n) ++h, n >>= 1;
    return h - 1;
  }
  
  SegmentTree(int n) {
    this->n = n;
    this->h = get_h(2*n-1);
    clr(t, 0);
  } 
  
  int apply(int p, int v) {
    t[p] = max(t[p], v);
    return 0;
  }

  // int push(int p) {
  //   for (int s = h; s > 0; --s) {
  //     int i = p >> s;
  //     if (d[i]) {
  //       apply(i<<1, d[i]);
  //       apply(i<<1|1, d[i]);
  //       d[i] = 0;
  //     }
  //   }
  //   return 0;
  // }

  int assign(int l, int r, int v) {
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) apply(l++, v);
      if (r & 1) apply(--r, v);
    }
    return 0;
  }

  int push() {
    for (int i = 1; i < n; ++i) {
      apply(i<<1, t[i]);
      apply(i<<1|1, t[i]);
      t[i] = 0;
    }
    return 0;
  }
};

class Solution {
 public:
  int find_index(int value, int *x, int len) {
    int l = 0, r = len;
    while (l < r) {
      int mid = (l + r) / 2;
      if (x[mid] == value) return mid;
      else if (x[mid] < value) l = mid + 1;
      else r = mid;
    }
    return l;
  }

  vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
    vector<pair<int, int>> ans;
    int n = buildings.size();
    if (n == 0) return ans;
    
    int x[n<<1];
    for (int i = 0; i < n; ++i) {
      x[i<<1] = buildings[i][0];
      x[i<<1|1] = buildings[i][1];
    }
    sort(x, x+2*n);
    int m = 1;
    for (int i = 1; i < 2 * n; ++i)
      if (x[i] != x[i-1]) x[m++] = x[i];

    SegmentTree tree(m-1);
    for (int i = 0; i < n; ++i) {
      vector<int> building = buildings[i];
      int l = find_index(building[0], x, m);
      int r = find_index(building[1], x, m);
      int h = building[2];
      tree.assign(l, r, h);
    }
    tree.push();
    // dump(m); 
    // out(tree.t, 2 * m);
     
    ans.push_back(make_pair(x[0], tree.t[tree.n])); 
    for (int i = 1; i < m-1; ++i)
      if (tree.t[tree.n+i] != tree.t[tree.n+i-1])
        ans. push_back(make_pair(x[i], tree.t[tree.n+i]));
    ans.push_back(make_pair(x[m-1], 0)); 
    return ans;
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  Solution s;
  vector<vector<int>> buildings;
  vector<int> tmp;
  // [2 9 10], 
  tmp.push_back(2);
  tmp.push_back(9);
  tmp.push_back(10);
  buildings.push_back(tmp);
  tmp.clear();
  // [3 7 15], 
  tmp.push_back(3);
  tmp.push_back(7);
  tmp.push_back(15);
  buildings.push_back(tmp);
  tmp.clear();
  // [5 12 12], 
  tmp.push_back(5);
  tmp.push_back(12);
  tmp.push_back(12);
  buildings.push_back(tmp);
  tmp.clear();
  // [15 20 10], 
  tmp.push_back(15);
  tmp.push_back(20);
  tmp.push_back(10);
  buildings.push_back(tmp);
  tmp.clear();
  // [19 24 8]
  tmp.push_back(19);
  tmp.push_back(24);
  tmp.push_back(8);
  buildings.push_back(tmp);
  tmp.clear();

  auto ans = s.getSkyline(buildings);
  for (auto it: ans)
    printf("%d %d,", it.first, it.second);
  return 0;
}
