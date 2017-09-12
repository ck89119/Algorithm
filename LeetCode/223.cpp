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

class Solution {
 public:
  struct Segment {
    int l, r, h;
    int flag;
    Segment(int l_, int r_, int h_, int flag_): l(l_), r(r_), h(h_), flag(flag_) {}
    bool operator < (const Segment &s) const {
      return h < s.h;
    }
  };

  int find_v(int v, int x[], int m) {
    for (int i = 0; i < m; ++i)
      if (v == x[i]) return i;
    return -1;
  }

  int get_length(int value[], int x[], int m) {
    int l = 0;
    for (int i = 0; i < m; ++i)
      if (value[i] > 0) l += x[i+1] - x[i];
    return l;
  }

  int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    vector<Segment> segments;
    segments.push_back(Segment(A, C, B, 1));
    segments.push_back(Segment(A, C, D, -1));
    segments.push_back(Segment(E, G, F, 1));
    segments.push_back(Segment(E, G, H, -1));
    sort(segments.begin(), segments.end());

    int x[4] = {A, C, E, G};
    sort(x, x+4);

    int m = 1;
    for (int i = 1; i < 4; ++i)
      if (x[i] != x[i-1]) x[m++] = x[i];
    
    int value[4] = {0};
    int ans = 0;
    int h = -INF;
    for (auto s: segments) {
      ans += (s.h - h) * get_length(value, x, m-1);

      int l = find_v(s.l, x, m);
      int r = find_v(s.r, x, m);
      for (int i = l; i < r; ++i)
        value[i] += s.flag;
      h = s.h;
    }
    return ans;
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  Solution s;
  cout << s.computeArea(-3, 0, 3, 4, 0, -1, 9, 2) << endl;

  
  return 0;
}
