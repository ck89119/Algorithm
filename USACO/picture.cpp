/*
ID: ck89119
PROG: picture
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
#define fin freopen("picture.in","r",stdin);
#define fout freopen("picture.out","w",stdout);
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

struct Segment {
    int s, t, p;
    int start;
};
int n;
int ans;
Segment seg_x[10005], seg_y[10005];

int cmp(const Segment &a, const Segment &b) {
    if (a.p != b.p) return (a.p < b.p);
    return (a.start > b.start);
}

int input() {
    int i;
    cin >> n;
    for (i = 0; i < n; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        seg_x[i*2].p = y1;
        seg_x[i*2].s = x1;
        seg_x[i*2].t = x2;
        seg_x[i*2].start = 1;
        seg_x[i*2+1].p = y2;
        seg_x[i*2+1].s = x1;
        seg_x[i*2+1].t = x2;
        seg_x[i*2+1].start = 0;
        seg_y[i*2].p = x1;
        seg_y[i*2].s = y1;
        seg_y[i*2].t = y2;
        seg_y[i*2].start = 1;
        seg_y[i*2+1].p = x2;
        seg_y[i*2+1].s = y1;
        seg_y[i*2+1].t = y2;
        seg_y[i*2+1].start = 0;
    }
    sort(seg_x, seg_x+2*n, cmp);
    sort(seg_y, seg_y+2*n, cmp);
    return 0;
}

int scan(Segment *seg) {
    int i, j;
    int level[20005];
    CLR(level, 0);

    for (i = 0; i < 2*n; ++i) {
        if (seg[i].start) {
            for (j = seg[i].s; j < seg[i].t; ++j) {
                level[10000+j]++;
                if (level[10000+j] == 1) ans++;
            }
        }
        else {
            for (j = seg[i].s; j < seg[i].t; ++j) {
                level[10000+j]--;
                if (level[10000+j] == 0) ans++;
            }
        }
    }
    return 0;
}

int solve() {
    ans = 0;
    scan(seg_x);
    scan(seg_y);
    cout << ans << endl;
    return 0;
}

int main() {
    fin fout
    input();
    solve();
    return 0;
}
