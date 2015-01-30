/*
ID: ck89119
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

int n;
int num[100005], pre[100005], cnt[100005];
int res;

int input() {
    int i;
    cin >> n;
    for (i = 0; i < n; i++) cin >> num[i];
    return 0;
}

//int check() {
//    int i;
//    int numInc;
//    int flag = 0;
//    i = 0; node = 0; node1 = 0;
//    numInc = 0;
//    while (next[i] != -1) {
//        if (num[i] > num[next[i]]) {
//            i = next[i];
//            flag = 1;
//            continue;
//        }
//        if (num[next[i]] < num[node1]) {
//            numInc++;
//        }
//        else {
//            node1 = i;
//        }
//        next[node] = next[i];
//        node = next[i];
//        i = next[i];
//
//    }
//    next[node] = -1;
//    return flag;
//}

int solve() {
    int i, j;
    pre[0] = -1; cnt[0] = 0;
    res = 0;
    for (i = 1; i < n; i++) {
        int t = 0;
        j = i - 1;
        while (num[i] > num[j] && pre[j] != -1) {
            t = max(t, cnt[j]);
            j = pre[j];

        }
        if (num[i] > num[j]) {
            pre[i] = -1;
            cnt[i] = 0;
        }
        else {
            pre[i] = j;
            cnt[i] = t + 1;
        }
        res = max(res, cnt[i]);

    }
    cout << res << endl;
}

int main() {
    input();
    solve();
    return 0;
}
