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
const int MAXN = 9999;
const int INF=(1<<30);
const double PI=acos(-1.0);
const double EPS=1e-11;

int main() {
    int r, g, b;
    int sum;
    scanf("%d%d%d", &r, &g, &b);
    sum = 0;

    if (r >= 3) {
        sum += r/3; r %= 3;
        if (r == 0) {
            r += 3;
            sum--;
        }
    }

    if (g >= 3) {
        sum += g/3; g %= 3;
        if (g == 0) {
            g += 3;
            sum--;
        }
    }

    if (b >= 3) {
        sum += b/3; b %= 3;
        if (b == 0) {
            b += 3;
            sum--;
        }
    }

    int mi;
    mi = min(min(r, g), b);
    if (mi == 2 || mi == 3) sum += mi;
    else if (mi == 1){
        if (r + g + b == 7) sum += 2;
        else sum += 1;
    }
    else if (mi == 0){
        if (r == 3) sum++;
        if (g == 3) sum++;
        if (b == 3) sum++;
    }

    printf("%d\n", sum);
    return 0;
}
