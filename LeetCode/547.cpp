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

struct UnionFindSet {
  int n;
  vector<int> f;
  UnionFindSet(int _n): n(_n) {
    for (int i = 0; i < n; ++i)
      f.push_back(i);
  }

  int merge(int x, int y) {
    f[x = find(x)] = f[y = find(y)];
    return 0;
  }

  int find(int x) {
    if (f[x] == x) return x;
    else return f[x] = find(f[x]);
  }
};

class Solution {
 public:
  int findCircleNum(vector<vector<int>>& M) {
    int n = M.size();
    UnionFindSet s(n);
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        if (M[i][j]) s.merge(i, j); 

    set<int> ans;
    for (int i = 0; i < n; ++i)
      ans.insert(s.find(i));
    return ans.size();
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  Solution s;
  vector<vector<int>> M;
  vector<int> tmp;
  tmp.push_back(1);
  tmp.push_back(1);
  tmp.push_back(0);
  M.push_back(tmp);
  tmp.clear();
  tmp.push_back(1);
  tmp.push_back(1);
  tmp.push_back(0);
  M.push_back(tmp);
  tmp.clear();
  tmp.push_back(0);
  tmp.push_back(0);
  tmp.push_back(1);
  M.push_back(tmp);
  cout << s.findCircleNum(M) << endl;
  return 0;
}
