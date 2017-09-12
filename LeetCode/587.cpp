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

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

int cmp(const Point &a, const Point &b) {
  return a.x < b.x || a.x == b.x && a.y < b.y;
}

int cross(const Point &a, const Point &b) {
  return a.x * b.y - a.y * b.x;
}
 
Point get_vector(const Point &a, const Point &b) {
  return Point(a.x-b.x, a.y-b.y);
}

class Solution {
 public:
  vector<Point> outerTrees(vector<Point>& points) {
    int n = points.size();
    // if (n <= 3) return points;

    sort(points.begin(), points.end(), cmp);
    vector<Point> ans(n+1);
    int top = 0;
    for (int i = 0; i < n; ++i) {
      while (top >= 2 && cross(get_vector(ans[top-1], ans[top-2]), get_vector(points[i], ans[top-1])) < 0) --top;
      ans[top++] = points[i];
    }
    int k = top;
    for (int i = n - 2; i >= 0; --i) {
      while (top >= k + 1 && cross(get_vector(ans[top-1], ans[top-2]), get_vector(points[i], ans[top-1])) < 0) --top;
      ans[top++] = points[i];
    }
    if (n > 1) --top;
    return vector<Point>(ans.begin(), ans.begin()+top); 
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  Solution s;
  vector<Point> points;
  points.push_back(Point(1, 2));
  points.push_back(Point(2, 2));
  points.push_back(Point(4, 2));
  points.push_back(Point(5, 2));
  // points.push_back(Point(0, 1));
  // points.push_back(Point(1, 0));
  // points.push_back(Point(100, 100));
  // points.push_back(Point(99, 100));
  // points.push_back(Point(100, 99));
  for (auto p: s.outerTrees(points)) {
    cout << p.x << ' ' << p.y << endl;
  }
  return 0;
}
