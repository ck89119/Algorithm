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
const int N = 2000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

struct SegmentTree {
  int n, h;
  int t[N<<1], d[N];

  SegmentTree(int _n): n(_n) {
    clr(t, 0);
    clr(d, 0);
    h = 0; _n = _n * 2 - 1;
    while (_n) _n >>= 1, ++h;
  }

  int apply(int p, int v) {
    t[p] = v;
    if (p < n) d[p] = v;
    return 0;
  }
  
  int push(int l, int r) {
    int s = h;
    for (l += n, r += n-1; s > 0; --s)
      for (int i = (l >> s); i <= (r >> s); ++i)
        if (d[i]) {
          apply(i<<1, d[i]);
          apply(i<<1|1, d[i]);
          d[i] = 0;
        } 
    return 0;
  }
  
  int build(int l, int r) {
    l += n, r += n-1;
    for (l >>= 1, r >>= 1; l > 0; l >>= 1, r >>= 1)
      for (int i = r; i >= l; --i)
        t[i] = max(t[i<<1], t[i<<1|1]);
    return 0;
  }

  int update(int l, int r, int v) {
    // dump(l), dump(r), dump(v);
    int tl = l, tr = r;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) apply(l++, v);
      if (r & 1) apply(--r, v);
    }
    push(tl, tr);
    build(tl, tr);
    return 0;
  }

  int query(int l, int r) {
    int ans = -INF;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) ans = max(ans, t[l++]);
      if (r & 1) ans = max(ans, t[--r]);
    }
    return ans;
  }
};

int find_index(int x, vector<int> points) {
  return lower_bound(points.begin(), points.end(), x) - points.begin();
}

class Solution {
 public:
  vector<int> fallingSquares(vector<pair<int, int>>& positions) {
    vector<int> idx;
    for (auto p: positions) {
      idx.push_back(p.first);
      idx.push_back(p.first + p.second);
    }
    sort(idx.begin(), idx.end());
    
    vector<int> points = {idx[0]};
    for (int i = 1; i < idx.size(); ++i) 
      if (idx[i] != idx[i-1]) points.push_back(idx[i]);
    
    vector<int> ans;
    SegmentTree tree(points.size() - 1);
    for (auto p: positions) {
      int l = find_index(p.first, points);
      int r = find_index(p.first + p.second, points);
      int ma = tree.query(l, r);
      tree.update(l, r, ma + p.second);
      ans.push_back(tree.t[1]);
    } 
    return ans;
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  Solution s;
  vector<pair<int, int>> positions;
  positions.push_back(make_pair(9, 7)); 
  positions.push_back(make_pair(1, 9)); 
  positions.push_back(make_pair(3, 1)); 

  out(s.fallingSquares(positions)); 
  return 0;
}
