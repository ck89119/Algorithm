/*
ID: ck89119
PROG: fc
LANG: C++
*/
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
using namespace std;
#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl;
#define FR(i,a,b) for(int i=(a);i<(b);++i)//[a,b)
#define CLR(a,x) memset(a,x,sizeof(a))
#define MP(A,B) make_pair(A,B)
#define PB(A) push_back(A)
#define PAU system("pause");
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(n) (n^(n-1))&n
#define fin freopen("fc.in","r",stdin);
#define fout freopen("fc.out","w",stdout);
//ifstream fin("");
//ofstream fout("");
#define LL long long

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out (vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int MAXN=10005;
const int MAXM=9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;

struct CPoint{double x,y;};
CPoint points[MAXN];
int n;

int dcmp(double x) {if (x<-EPS) return -1;else return (x>EPS);}
double sqr(double x) {return x*x;}
//cross product
double cross(CPoint p0, CPoint p1, CPoint p2) {
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
//dot product
double dot(CPoint p0, CPoint p1, CPoint p2) {
    return (p1.x-p0.x)*(p2.x-p0.x)+(p1.y-p0.y)*(p2.y-p0.y);
}

double dis(CPoint p1, CPoint p2) {
    return sqrt(sqr(p1.x-p2.x)+sqr(p1.y-p2.y));
}

int cmp(const CPoint &p1, const CPoint &p2) {
    CPoint p0 = points[0];
    int u = dcmp(cross(p0, p1, p2));
    return u > 0 || (u == 0 && dcmp(dis(p0, p1)-dis(p0, p2)) < 0);
}

int ConvexHull(CPoint ch[], int &chSize) {
    int i, j, k, u, v;
    k = 0;
    for (i = 1; i < n; i++) {
        u = dcmp(points[i].x - points[k].x);
        v = dcmp(points[i].y - points[k].y);
        if (v < 0 || (v == 0 && u < 0)) k = i;
    }
    CPoint tmp = points[0];
    points[0] = points[k];
    points[k] = tmp;
    sort(points+1, points+n, cmp);
    memcpy(ch, points, n*sizeof(CPoint));
    ch[n++] = ch[0];
    i = 1;//栈顶指针
    for (j = 2; j < n; j++) {
        while (i > 0 && dcmp(cross(ch[i-1], ch[i], ch[j])) <= 0) i--;
        ch[++i] = ch[j];
    }
    chSize = i;
    return 0;
}

int main() {
    int i;
    double res;
    fin fout
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> points[i].x >> points[i].y;

    CPoint ch[MAXN];
    int chSize;
    ConvexHull(ch, chSize);
    res = dis(ch[chSize-1], ch[0]);
    for (i = 0; i < chSize-1; i++) {
        res += dis(ch[i], ch[i+1]);
    }

    printf("%.2lf\n", res);
    return 0;
}
