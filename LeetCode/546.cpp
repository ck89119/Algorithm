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

class Solution {
 public:
  vector<int> len, color, pre;
  vector<vector<vector<int>>> f;

  int search(int l, int r, int k) {
    if (l > r) return 0;
    if (f[l][r][k]) return f[l][r][k];
    
    int ans = search(l, r-1, 0) + (len[r] + k) * (len[r] + k);
    for (int p = pre[r]; p >= l; p = pre[p])
      ans = max(ans, search(l, p, k+len[r]) + search(p+1, r-1, 0));
    return f[l][r][k] = ans;
  }

  int removeBoxes(vector<int>& boxes) {
    int n = boxes.size();
    len = vector<int>(n);
    color = vector<int>(n);

    int m = -1, p = -1;
    for (int i = 0; i < n; ++i)
      if (boxes[i] != p) {
        color[++m] = p = boxes[i];
        len[m] = 1;
      } else {
        ++len[m];
      }
    // dump(m);
    // out(color), out(len);

    pre = vector<int>(m+1);
    map<int, int> pos;
    for (int i = 0; i <= m; ++i) {
      if (pos.find(color[i]) == pos.end()) pre[i] = -1;
      else pre[i] = pos[color[i]];
      pos[color[i]] = i;
    }
    // out(pre); 
    f = vector<vector<vector<int>>>(m+1, vector<vector<int>>(m+1, vector<int>(n, 0)));
    return search(0, m, 0);
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  Solution s;
  vector<int> boxes;
  boxes.push_back(1);
  // boxes.push_back(3);
  // boxes.push_back(2);
  // boxes.push_back(2);
  // boxes.push_back(2);
  // boxes.push_back(3);
  // boxes.push_back(4);
  // boxes.push_back(3);
  // boxes.push_back(1);
  cout << s.removeBoxes(boxes) << endl;
  return 0;
}
