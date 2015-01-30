/*
ID: ck89119
PROG:
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
#define fin freopen("in.txt","r",stdin);
#define fout freopen("out.txt","w",stdout);
//ifstream fin("");
//ofstream fout("");
#define LL long long

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out (vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int MAXN=99999;
const int MAXM=9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;

struct Point {
    int x, y;
};
Point points[305];
int n;

int det(Point a, Point b) {
    return a.x*b.y-a.y*b.x;
}

double area(Point a, Point b, Point c) {
    return 0.5*(det(a, b) + det(b, c) + det(c, a));
}

int main() {
    int i, j, k;
    double res;
    cin >> n;
    for (i = 0; i < n; i++)
        scanf("%d%d", &points[i].x, &points[i].y);
    res = -9999999999999999.0;
    for (i = 0; i < n; i++)
        for (j = i+1; j < n; j++) {
            double maxPos, maxNeg;
            maxPos = maxNeg = -1;
            //dump(i)dump(j)
            for (k = 0; k < n; k++)
                if (k != i && k != j) {
                    double tmp = area(points[i], points[j], points[k]);
                    //dump(k) dump(tmp)
                    if (tmp > EPS) {
                        maxPos = max(maxPos, tmp);
                    }
                    else maxNeg = max(maxNeg, -tmp);
                }
                //dump(maxNeg) dump(maxPos)
            if (maxNeg < EPS || maxPos < EPS) continue;
            res = max(res, maxNeg+maxPos);
        }
    printf("%.9lf\n", res);
    return 0;
}
