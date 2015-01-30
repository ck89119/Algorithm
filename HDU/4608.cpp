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

int t;
string x;
int x_int[100005], x_size;

int input() {
    int i;
    CL(x_int, 0);
    cin >> x;
    x_size = x.size();
    for (i = x_size-1; i >= 0; i--)
        x_int[x_size-1-i] = x[i] - '0';
    return 0;
}

int digitSum() {
    int sum = 0;
    int i;
    for (i = 0; i < x_size; i++)
        sum += x_int[i];
    return sum%10;
}

int plus1() {
    int i;
    i = 0; x_int[i]++;
    while (x_int[i] == 10) {
        x_int[i++] = 0;
        x_int[i]++;
    }
    x_size = max(x_size, i+1);
    return 0;
}

int solve() {
    int i;
    while (1) {
        plus1();
        if (!digitSum()) {
            for (i = x_size-1; i >= 0; i--)
                cout << x_int[i];
            cout << endl;
            return 0;
        }
    }
    return 0;
}

int main(){
    cin >> t;
    while (t--) {
        input();
        solve();
    }
    return 0;
}
