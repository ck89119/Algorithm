/*
ID: ck89119
PROG: fence3
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
#include <ctime>
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
#define fin freopen("fence3.in","r",stdin);
#define fout freopen("fence3.out","w",stdout);
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

// ++++++++
// Ä£ÄâÍË»ð
// ++++++++

struct Fence {
    int x1, y1;
    int x2, y2;
};
int F;
Fence fence[155];
int maxx, maxy, minx, miny;
double ans_dis;
int ans_x, ans_y;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int input() {
    fin fout
    int i;
    cin >> F;
    for (i = 0; i < F; ++i) {
        cin >> fence[i].x1 >> fence[i].y1 >> fence[i].x2 >> fence[i].y2;
        fence[i].x1 *= 10; fence[i].y1 *= 10; fence[i].x2 *= 10; fence[i].y2 *= 10;
        if (fence[i].x1 > fence[i].x2) swap(fence[i].x1, fence[i].x2);
        if (fence[i].y1 > fence[i].y2) swap(fence[i].y1, fence[i].y2);
        maxx = max(maxx, fence[i].x2);
        maxy = max(maxy, fence[i].y2);
        minx = min(minx, fence[i].x1);
        miny = min(miny, fence[i].y1);
    }
    return 0;
}

double dis(double x1, double y1, double x2, double y2) {
    return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}

double count(int x, int y) {
    double ans = 0.0;
    int i;
    for (i = 0; i < F; ++i) {
        if (fence[i].x1 == fence[i].x2) {
            if (y >= fence[i].y1 && y <= fence[i].y2) ans += abs(x-fence[i].x1);
            else if (y < fence[i].y1) ans += dis(x, y, fence[i].x1, fence[i].y1);
                 else ans += dis(x, y, fence[i].x2, fence[i].y2);
        }
        else {
            if (x >= fence[i].x1 && x <= fence[i].x2) ans += abs(y-fence[i].y1);
            else if (x < fence[i].x1) ans += dis(x, y, fence[i].x1, fence[i].y1);
                 else ans += dis(x, y, fence[i].x2, fence[i].y2);
        }
    }
    return ans;
}

int sa() {
    int i, j;
    int t, neig, step;
    ans_x = fence[0].x1; ans_y = fence[0].y1;
    ans_dis = count(ans_x, ans_y);
    t = 40; neig = 200; step = 5;
    srand(time(NULL));
    while (t--) {
        for (i = 0; i < neig; ++i)
            for (j = 0; j < 4; ++j) {
                int d = rand() % step;
                int x = ans_x + dx[j]*d;
                int y = ans_y + dy[j]*d;
                if (x >= 0 && x <= 1000 && y >= 0 && y <= 1000) {
                    double tmp = count(x, y);
                    if (tmp < ans_dis) {
                        ans_dis = tmp;
                        ans_x = x;
                        ans_y = y;
                    }
                }

            }
    }

    return 0;
}

int output() {
    printf("%.1lf ", 1.0*ans_x/10);
    printf("%.1lf ", 1.0*ans_y/10);
    printf("%.1lf\n", ans_dis/10);
    return 0;
}

int main() {
    input();
    sa();
    output();
    return 0;
}



// ++++++++
// ¾Ö²¿ËÑË÷
// ++++++++

//struct Fence {
//    int x1, y1;
//    int x2, y2;
//};
//int F;
//Fence fence[155];
//int maxx, maxy, minx, miny;
//const int step = 150;
//int ans_x, ans_y;
//double ans_dis;
//
//double dis(int x1, int y1, int x2, int y2) {
//    return sqrt(1.0*(x2-x1)*(x2-x1) + 1.0*(y2-y1)*(y2-y1));
//}
//
//int input() {
//    int i;
//    fin fout
//    cin >> F;
//    maxx = maxy = -1;
//    minx = miny = 101;
//    for (i = 0; i < F; ++i) {
//        cin >> fence[i].x1 >> fence[i].y1 >> fence[i].x2 >> fence[i].y2;
//        fence[i].x1 *= 10; fence[i].y1 *= 10; fence[i].x2 *= 10; fence[i].y2 *= 10;
//        if (fence[i].x1 > fence[i].x2) swap(fence[i].x1, fence[i].x2);
//        if (fence[i].y1 > fence[i].y2) swap(fence[i].y1, fence[i].y2);
//        maxx = max(maxx, fence[i].x2);
//        maxy = max(maxy, fence[i].y2);
//        minx = min(minx, fence[i].x1);
//        miny = min(miny, fence[i].y1);
//    }
//    return 0;
//}
//
//double count(int x, int y) {
//    double ans = 0;
//    int i;
//    for (i = 0; i < F; ++i) {
//        if (fence[i].x1 == fence[i].x2) {
//            if (y >= fence[i].y1 && y <= fence[i].y2) ans += abs(x-fence[i].x1);
//            else if (y < fence[i].y1) ans += dis(x, y, fence[i].x1, fence[i].y1);
//                 else ans += dis(x, y, fence[i].x2, fence[i].y2);
//        }
//        else {
//            if (x >= fence[i].x1 && x <= fence[i].x2) ans += abs(y-fence[i].y1);
//            else if (x < fence[i].x1) ans += dis(x, y, fence[i].x1, fence[i].y1);
//                 else ans += dis(x, y, fence[i].x2, fence[i].y2);
//        }
//    }
//    return ans;
//}
//
//int search() {
//    int i, j;
//    int tx, ty;
//    ans_dis = 99999999;
//    for (i = minx;  i <= maxx;  i += step)
//        for (j = miny; j <= maxy; ++j) {
//            double tmp = count(i, j);
//            if (tmp < ans_dis) {
//                ans_dis = tmp;
//                tx = i;
//                ty = j;
//            }
//        }
//    ans_dis = 99999999;
//    for (i = tx-step; i <= tx+step; ++i)
//        for (j = ty-step; j <= ty+step; ++j) {
//            double tmp = count(i, j);
//            if (tmp < ans_dis) {
//                ans_dis = tmp;
//                ans_x = i;
//                ans_y = j;
//            }
//        }
//
//    return 0;
//}
//
//int output() {
//    printf("%.1lf ", 1.0*ans_x/10);
//    printf("%.1lf ", 1.0*ans_y/10);
//    printf("%.1lf\n", ans_dis/10);
//    return 0;
//}
//
//int main() {
//    input();
//    search();
//    output();
//    return 0;
//}
