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
  bool search(vector<vector<int>> &matrix, int x0, int y0, int x1, int y1, int target) {
    // dump(x0), dump(y0), dump(x1), dump(y1);
    // dump("#######");
    if (x0 >= x1 || y0 >= y1) return false;

    int xm = (x0 + x1) / 2;
    int ym = (y0 + y1) / 2;
    if (matrix[xm][ym] == target) return true;
    if (matrix[xm][ym] < target) {
      if (search(matrix, x0, ym + 1, x1, y1, target)) return true;
      if (search(matrix, xm + 1, y0, x1, y1, target)) return true;
      return false;
    }
    if (search(matrix, x0, y0, x1, ym, target)) return true;
    if (search(matrix, x0, y0, xm, y1, target)) return true;
    return false;
  }

  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    if (n == 0) return false;
    int m = matrix[0].size();
    if (m == 0) return false;
    return search(matrix, 0, 0, n, m, target);
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  vector<vector<int>> matrix;
  vector<int> v;
  v.push_back(1);
  v.push_back(4);
  v.push_back(7);
  v.push_back(11);
  v.push_back(15);
  matrix.push_back(v);
  v.clear();
  v.push_back(2);
  v.push_back(5);
  v.push_back(8);
  v.push_back(12);
  v.push_back(19);
  matrix.push_back(v);
  v.clear();
  v.push_back(3);
  v.push_back(6);
  v.push_back(9);
  v.push_back(16);
  v.push_back(22);
  matrix.push_back(v);
  v.clear();
  v.push_back(10);
  v.push_back(13);
  v.push_back(14);
  v.push_back(17);
  v.push_back(24);
  matrix.push_back(v);
  v.clear();
  v.push_back(18);
  v.push_back(21);
  v.push_back(23);
  v.push_back(26);
  v.push_back(30);
  matrix.push_back(v);
  v.clear();
  Solution s;
  cout << s.searchMatrix(matrix, 5) << endl;
  cout << s.searchMatrix(matrix, 20) << endl;
  return 0;
}
