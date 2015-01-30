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

int r, c, grid[11][11];
int sumR[11], sumC[11];
int res;

int input() {
    int i, j;
    string s;
    cin >> r >> c;
    CL(sumC, 0); CL(sumR, 0);
    for (i = 0; i < r; i++) {
        cin >> s;
        for (j = 0; j < c; j++)
            if (s[j] == '.') grid[i][j] = 0;
            else {grid[i][j] = 1; sumR[i]++; sumC[j]++;}
    }
    return 0;
}

int solve() {
    int i, j;
    res = 0;
    for (i = 0; i < r; i++)
        if (sumR[i] == 0) {
            for (j = 0; j < c; j++)
                if (grid[i][j] == 0) {res++; grid[i][j] = -1;}
        }
    for (j = 0; j < c; j++)
        if (sumC[j] == 0) {
            for (i = 0; i < r; i++)
                if (grid[i][j] == 0) {res++; grid[i][j] = -1;}
        }
    cout << res << endl;
}

int main(){
    input();
    solve();
    return 0;
}
