#include <bits/stdc++.h>
using namespace std;

#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0x80
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
const double EPS = 1e-11;
const double PI	= acos(-1.0);

double sqr(double x) { return x * x; }
int sgn(double x) { return (x > EPS) - (x < -EPS); }

struct Point {
  double x, y;
  Point(double _x, double _y): x(_x), y(_y) {};
  bool operator == (const Point& p) {
    return sgn(x - p.x) == 0 && sgn(y - p.y) == 0;
  }
};

struct Segment {
  Point p0, p1;
  Segment(const Point& _p0, const Point& _p1): p0(_p0), p1(_p1) {};
};

struct Vector {
  double dx, dy;
  Vector(double _dx, double _dy): dx(_dx), dy(_dy) {};
  Vector(const Point& p0, const Point& p1): dx(p1.x - p0.x), dy(p1.y - p0.y) {};
};

double Cross(const Vector& v0, const Vector& v1) {
  return v0.dx * v1.dy - v1.dx * v0.dy;
}

double Dot(const Vector& v0, const Vector& v1) {
  return v0.dx * v1.dx + v0.dy * v1.dy;
}

double DisSqr(const Point& p0, const Point& p1) {
  return sqr(p0.x - p1.x) + sqr(p0.y - p1.y);
}

double Dis(const Point& p0, const Point& p1) {
  return sqrt(sqr(p0.x - p1.x) + sqr(p0.y - p1.y));
}

double Angle(const Vector& v0, const Vector& v1) {
  double cr = Cross(v0, v1);
  double dt = Dot(v0, v1);
  if (sgn(dt) == 0) return PI / 2.0;
  return atan2(cr, dt);
}

int PointOnLine(const Point& p0, const Point& p1, const Point& p2) {
  return sgn(Cross(Vector(p0, p1), Vector(p0, p2))) == 0;
}

int PointOnSegment(const Point& p0, const Segment& s1) {
  Point p1 = s1.p0, p2 = s1.p1;
  return PointOnLine(p0, p1, p2) && sgn(Dot(Vector(p0, p1), Vector(p0, p2))) <= 0;
}

bool SegmentIntersection(const Segment& s0, const Segment& s1) {
  Point p0 = s0.p0, p1 = s0.p1, p2 = s1.p0, p3 = s1.p1;
  if (max(p0.x, p1.x) >= min(p2.x, p3.x) + EPS &&
      max(p2.x, p3.x) >= min(p0.x, p1.x) + EPS &&
      max(p0.y, p1.y) >= min(p2.y, p3.y) + EPS &&
      max(p2.y, p3.y) >= min(p0.y, p1.y) + EPS &&
      Cross(Vector(p0, p2), Vector(p2, p3)) * Cross(Vector(p2, p3), Vector(p1, p2)) >= 0 &&
      Cross(Vector(p2, p0), Vector(p0, p1)) * Cross(Vector(p0, p1), Vector(p3, p0)) >= 0)
    return true;
  else
    return false;
}

// 0: outside; 1: inside;	2: boundary
int PointInPolygon(const Point &cp, Point p[], int n) {
  int wn = 0;
  p[n] = p[0];
  for(int i = 0; i < n; i++) {
    if (PointOnSegment(cp, Segment(p[i], p[i+1]))) return 2;
    int k = sgn(Cross(Vector(p[i], p[i+1]), Vector(p[i+1], cp)));
    d1=sgn(p[i+0].y-cp.y);
    d2=sgn(p[i+1].y-cp.y);
    if(k>0&&d1<=0&&d2>0) wn++;
    if(k<0&&d2<=0&&d1>0) wn--;
  }
  return wn!=0;
}

// //p0到p1,p2所在直线的距离,cp为垂足
// double PointToLine(Point p0,Point p1,Point p2,Point &cp) {
//   double d=dis(p1,p2);
//   double s=cross(p1,p2,p0)/d;
//   cp.x=p0.x+s*(p2.y-p1.y)/d;
//   cp.y=p0.y-s*(p2.x-p1.x)/d;
//   return s;
// }

// //cp为垂足
// int PointProjLine(Point p0,Point p1,Point p2,Point &cp) {
//   double t=dot(p1,p2,p0)/dot(p1,p2,p2);
//   cp.x=p1.x+t*(p2.x-p1.x);
//   cp.y=p1.y+t*(p2.y-p1.y);
//   return 0;
// }

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif
  
  Vector v0(1, 0);
  Vector v1(0, 1);
  Vector v2(-1, 0);
  printf("%.10lf\n", Angle(v0, v2));

  return 0;
}

