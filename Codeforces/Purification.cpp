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
//struct Edge {
//    int to;
//    int w;
//    int next;
//};
//int head[];
const int MAXN=99999;
const int INF=(1<<30);
const double PI=acos(-1.0);
const double EPS=1e-11;

int n;
int grid[105][105];

int input() {
    int i, j;
    string s;
    CL(grid, 0);
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> s;
        for (j = 0; j < n; j++)
            if (s[j] == 'E') grid[i][j] = 1;
    }
    return 0;
}

int solve() {
    int i, j;
    int flag1, flag2;
    for (i = 0; i < n; i++) {
        flag1 = 0;
        for (j = 0; j < n; j++)
            if (grid[i][j] == 0) {
                flag1 = 1;
                break;
            }
        if (!flag1) break;
    }

    for (j = 0; j < n; j++){
        flag2 = 0;
        for (i = 0; i < n; i++)
            if (grid[i][j] == 0) {
                flag2 = 1;
                break;
            }
        if (!flag2) break;
    }

    if (!(flag1||flag2)) {
        cout << -1 << endl;
        return 0;
    }

    if (flag1) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++)
                if (grid[i][j] == 0) {
                    cout << i+1 << ' ' << j+1 << endl;
                    break;
                }
        }
        return 0;
    }

    if (flag2) {
        for (j = 0; j < n; j++) {
            for (i = 0; i < n; i++)
                if (grid[i][j] == 0) {
                    cout << i+1 << ' ' << j+1 << endl;
                    break;
                }
        }
        return 0;
    }

}

int main(){
    input();
    solve();
    return 0;
}
