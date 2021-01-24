/*
ID: ck891191
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
#define CL(a,x) memset(a,x,sizeof(a))
#define MP(A,B) make_pair(A,B)
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
//freopen("","r",stdin);
//freopen("","w",stdout);
//ifstream fin("");
//ofstream fout("");
const int MAXN=99999;
const int INF=(1<<30);
const double PI=acos(-1.0);
const double EPS=1e-11;

long long x, y, m;

int main(){
    long long step, t;
    cin >> x >> y >> m;
    if (x >= m || y >= m) {
        cout << 0 << endl;
        return 0;
    }
    if (x <= 0 && y <= 0 && x < m && y < m) {
        cout << -1 << endl;
        return 0;
    }
    step = 0;
    if (x > y) swap(x, y);
    if (x < 0 && y > 0) {
        t = (-x) / y + 1;
        step += t;
        x += y * t;
    }
    while (y < m) {
        t = x;
        x = y;
        y += t;
        step += 1;
    }
    cout << step << endl;
    return 0;
}
