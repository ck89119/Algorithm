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

string s;
int a, b, dx[105], dy[105];

int check(int x1, int y1, int x2, int y2) {
    int mul = 0;
    if (x1 != 0) mul = x2/x1;
    if (y1 != 0) mul = y2/y1;
    if (mul < 0) return 0;
    return ((x1 * mul == x2) && (y1 * mul == y2));
}


int main() {
    int i;
    cin>>a>>b;
    cin>>s;
    dx[0] = 0; dy[0] = 0;
    for (i = 0; i < s.size(); i++) {
        if (s[i] == 'U') {
            dx[i+1] = dx[i];
            dy[i+1] = dy[i] + 1;
            }
        else if (s[i] == 'D') {
            dx[i+1] = dx[i];
            dy[i+1] = dy[i] - 1;
        }
        else if (s[i] == 'L') {
            dx[i+1] = dx[i] - 1;
            dy[i+1] = dy[i];
        }
        else if (s[i] == 'R') {
            dx[i+1] = dx[i] + 1;
            dy[i+1] = dy[i];
        }
    }

    for (i = 0; i <= s.size(); i++)
        if (check(dx[s.size()], dy[s.size()], a-dx[i], b-dy[i])) {
            printf("Yes\n");
            return 0;
        }
    printf("No\n");
    return 0;
}
