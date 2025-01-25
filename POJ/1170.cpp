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

struct DISCOUNT {
    int n;
    int total[5];
    int p;
};

int total[5], code[5], price[5];
DISCOUNT discount[205];
int b, s;
int dp[7800];
int pow6[7] = {1, 6, 36, 216, 1296, 7776, 46656};

int getIndex(int c) {
    int res;
    res = 0;
    while (c != code[res]) res++;
    if (res < b) return res;
    else return -1;
}

int input() {
    int c ,k ,p, n;
    int i, j;
    scanf("%d", &b);
    for (i = 0; i < b; i++) {
        scanf("%d%d%d", &c, &k, &p);
        total[i] = k; code[i] = c; price[i] = p;
    }

    for (i = 0; i < b; i++) {
        discount[i].n = 1;
        discount[i].p = price[i];
        CL(discount[i].total, 0);
        discount[i].total[i] = 1;
    }

    scanf("%d", &s);
    for (i = 0; i < s; i++) {
        scanf("%d", &n);
        discount[b+i].n = n;
        for (j = 0; j < n; j++){
            scanf("%d%d", &c, &k);
            //dump(getIndex(c))
            discount[i+b].total[getIndex(c)] = k;
        }

        scanf("%d", &discount[b+i].p);
    }
    return 0;
}

int setArr(int state, int arr[]) {
    int i;
    for (i = 0; i < b; i++) {
        arr[i] = state % 6;
        state /= 6;
    }
    return 0;
}

int getState(int arr[]) {
    int res = 0;
    int i;
    for (i = b-1; i >= 0; i--)
        res = res * 6 + arr[i];
    return res;
}

int mem(int state) {
    int i, j;
    int stateArr[5];
        //dump(state)
    if (dp[state] != INF) return dp[state];
//    dump(state)
    setArr(state, stateArr);
//    for (j = 0; j < b; j++) cout << stateArr[j] << ' ';cout << endl;
    for (i = 0; i < b+s; i++) {
        int flag = 0;

        for (j = 0; j < b; j++)
            if (stateArr[j] < discount[i].total[j]) {
                flag = 1;
                break;
            }
        if (flag) continue;

        int stateTmp[5];
        for (j = 0; j < b; j++) stateTmp[j] = stateArr[j];
        for (j = 0; j < b; j++)
            stateTmp[j] -= discount[i].total[j];

        int t = getState(stateTmp);
        //dump(t)getchar();
        dp[state] = min(dp[state], mem(t)+discount[i].p);
    }


    return dp[state];
}

int solve() {
    int state;
    int i;
    for (i = 0; i < pow6[b]; i++) dp[i] = INF;
    dp[0] = 0;
    state = 0;
    for (i = b-1; i >= 0; i--)
        state = state*6 + total[i];
    mem(state);
    cout << dp[state] << endl;
    return 0;
}

int main(){
    input();
    solve();
    return 0;
}
