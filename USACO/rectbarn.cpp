/*
ID: ck89119
PROG: rectbarn
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
#define CLR(a,x) memset(a,x,sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0x80
#define MP(A,B) make_pair(A,B)
#define PB(A) push_back(A)
#define PAU system("pause");
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(n) (n^(n-1))&n
#define fin freopen("rectbarn.in","r",stdin);
#define fout freopen("rectbarn.out","w",stdout);
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
Point point[30005];
int r, c, p;
int ans;

int cmp_x(const Point &a, const Point &b) {
    return a.x < b.x;
}

int cmp_y(const Point &a, const Point &b) {
    return a.y < b.y;
}

int input() {
    int i;
    cin >> r >> c >> p;
    for (i = 0; i < p; ++i)
        cin >> point[i].x >> point[i].y;
    return 0;
}

int solve() {
    int left, right, upper, bottom;
    int i, j;
    ans = 0;
    sort(point, point+p, cmp_x);
    ans = max(ans, c * (point[0].x - 1));
    for (i = 1; i < p; ++i)
        ans = max(ans, c * (point[i].x-point[i-1].x-1));
    ans = max(ans, c * (r-point[p-1].x));

    sort(point, point+p, cmp_y);
    for (i = 0; i < p; ++i) {
        left = point[i].y;
        upper = 0; bottom = r+1;
        for (j = i+1; j < p; ++j) {
            if (point[j].x < upper || point[j].x > bottom) continue;
            right = point[j].y;
            ans = max(ans, (right-left-1)*(bottom-upper-1));
            if (point[j].x >= point[i].x) bottom = min(bottom, point[j].x);
            if (point[j].x <= point[i].x) upper = max(upper, point[j].x);
            if (bottom <= upper + 1) break;
        }
        right = c+1;
        ans = max(ans, (right-left-1)*(bottom-upper-1));
    }
    //dump(ans)
    for (i = p-1; i >= 0; --i) {
        right = point[i].y;
        upper = 0; bottom = r+1;
        for (j = i-1; j >= 0; --j) {
            //right = point[j].y;
            //ans = max(ans, (right-left-1)*(bottom-upper-1));
            if (point[j].x < upper || point[j].x > bottom) continue;
            if (point[j].x >= point[i].x) bottom = min(bottom, point[j].x);
            if (point[j].x <= point[i].x) upper = max(upper, point[j].x);
            if (bottom <= upper + 1) break;
        }
        left = 0;
        ans = max(ans, (right-left-1)*(bottom-upper-1));
    }
    //dump(ans)
    return 0;
}

int output() {
    cout << ans << endl;
    return 0;
}

int main() {
    fin fout
    ios :: sync_with_stdio(false);
    cout << fixed << setprecision(16);
    input();
    solve();
    output();
    return 0;
}
