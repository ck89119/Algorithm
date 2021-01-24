/*
ID: ck89119
PROG: window
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
#define fin freopen("window.in","r",stdin);
#define fout freopen("window.out","w",stdout);
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

struct Rect {
    char ch;
    int x1, y1, x2, y2;
    int next;
};
Rect rect[100];
int rect_size;
//int max_h, min_h;

int add(char ch, int x1, int y1, int x2, int y2) {
    rect[rect_size].ch = ch;
    rect[rect_size].x1 = x1;
    rect[rect_size].y1 = y1;
    rect[rect_size].x2 = x2;
    rect[rect_size].y2 = y2;
    rect_size++;
    return 0;
}

int top(char ch) {
    int i;
    Rect tmp;
    for (i = 0; i < rect_size; ++i)
        if (rect[i].ch == ch) {tmp = rect[i]; break;}
    for (; i < rect_size-1; ++i)
        rect[i] = rect[i+1];
    rect[rect_size-1] = tmp;
    return 0;
}

int bottom(char ch) {
    int i;
    Rect tmp;
    for (i = 0; i < rect_size; ++i)
        if (rect[i].ch == ch) {tmp = rect[i]; break;}
    for (; i > 0; --i)
        rect[i] = rect[i-1];
    rect[0] = tmp;
    return 0;
}

int destroy(char ch) {
    int i;
    Rect tmp;
    for (i = 0; i < rect_size; ++i)
        if (rect[i].ch == ch) {tmp = rect[i]; break;}
    for (; i < rect_size-1; ++i)
        rect[i] = rect[i+1];
    rect_size--;
    return 0;
}

int dfs(int h, int x1, int y1, int x2, int y2) {
    int ans = 0;
    int i = h + 1;
    //dump(h) dump(x1) dump(y1) dump(x2) dump(y2)
    while (i < rect_size && (rect[i].x1 >= x2 || rect[i].y1 >= y2 || rect[i].x2 <= x1 || rect[i].y2 <= y1)) i++;

    if (i >= rect_size) {
        ans = (x2-x1) * (y2-y1);
    }
    else {
        if (rect[i].x1 > x1 ) ans += dfs(i, x1, y1, rect[i].x1, y2);
        if (rect[i].y1 > y1 ) ans += dfs(i, max(x1, rect[i].x1), y1, min(rect[i].x2, x2), rect[i].y1);
        if (rect[i].x2 < x2 ) ans += dfs(i, rect[i].x2, y1, x2, y2);
        if (rect[i].y2 < y2 ) ans += dfs(i, max(x1, rect[i].x1), rect[i].y2, min(rect[i].x2, x2), y2);
    }
    return ans;
}

double cal(char ch) {
    int sum, vis;
    int i;
    for (i = 0; i < rect_size; ++i)
        if (rect[i].ch == ch) break;
    sum = (rect[i].x2-rect[i].x1)*(rect[i].y2-rect[i].y1);
    vis = dfs(i, rect[i].x1, rect[i].y1, rect[i].x2, rect[i].y2);
    //dump(i) dump(sum) dump(vis)
    return 100.0*vis/sum;
}

int main() {
    char str[100];
    int i;
    fin fout
    rect_size = 0;
    while (~scanf("%s", str)) {
        char op, ch;
        int x1, y1, x2, y2;
        if (str[0] == 'w') {
            sscanf(str, "%c(%c,%d,%d,%d,%d)", &op, &ch, &x1, &y1, &x2, &y2);
            if (x1 > x2) swap(x1, x2);
            if (y1 > y2) swap(y1, y2);
            //dump(op)dump(ch)dump(x1)dump(y1)dump(x2)dump(y2)
            add(ch, x1, y1, x2, y2);
        }
        if (str[0] == 't') {
            top(str[2]);
        }
        if (str[0] == 'b') {
            bottom(str[2]);
        }
        if (str[0] == 'd') {
            destroy(str[2]);
        }
        if (str[0] == 's') {
            printf("%.3lf\n", cal(str[2]));
        }
    }
    return 0;
}
