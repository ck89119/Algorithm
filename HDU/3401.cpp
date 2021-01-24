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
#define CLR(a,x) memset(a,x,sizeof(a))
#define MP(A,B) make_pair(A,B)
#define PAU system("pause");
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(n) (n^(n-1))&n
//freopen("","r",stdin);
//freopen("","w",stdout);
//ifstream fin("");
//ofstream fout("");

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out (vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int MAXN=2005;
const int INF=(1<<30);
const double PI=acos(-1.0);
const double EPS=1e-11;

int tcase, T, MaxP, W;
int ap[MAXN], bp[MAXN], as[MAXN], bs[MAXN];
int f[MAXN][MAXN];

int input() {
    int i;
    scanf("%d%d%d", &T, &MaxP, &W);//dump(T)dump(MaxP)dump(W)
    for (i = 1; i <= T; i++)
        scanf("%d%d%d%d", &ap[i], &bp[i], &as[i], &bs[i]);
    return 0;
}

int out() {
    int i, j;
    for (i = 1; i <= T; i++){
        for (j = 0; j <= MaxP; j++) cout << f[i][j] << ' ';cout << endl;}
    cout << endl;
    return 0;
}

int dp() {
    int i, j;
    int q[MAXN], index[MAXN], head, tail;

    for (i = 1; i <= T; i++)
        for (j = 0; j <= MaxP; j++)
            f[i][j] = -INF;

    for (i = 1; i <= W+1; i++)
        for (j = 0; j <= min(MaxP, as[i]); j++)
            f[i][j] = -ap[i] * j;
    //out();

    for (i = 2; i <= T; i++) {

        for (j = 0; j <= MaxP; j++)
            f[i][j] = max(f[i][j], f[i-1][j]);

        if (i < W+2) continue;

        head = tail = 0;
        for (j = 0; j <= MaxP; j++) {
            int tmp = f[i-W-1][j] + j * ap[i];
            while (head < tail && q[tail-1] < tmp) tail--;
            q[tail] = tmp; index[tail++] = j;
            while (head < tail && j - index[head] > as[i]) head++;
            f[i][j] = max(f[i][j], q[head] - j * ap[i]);
        }

        head = tail = 0;
        for (j = MaxP; j >= 0; j--) {
            int tmp = f[i-W-1][j] + j * bp[i];
            while (head < tail && q[tail-1] < tmp) tail--;
            q[tail] = tmp; index[tail++] = j;
            while (head < tail && index[head] - j > bs[i]) head++;
            f[i][j] = max(f[i][j], q[head] - j * bp[i]);
        }

       // out();
    }

    return 0;
}

int output() {
    int j;
    int res = 0;
    for (j = 0; j <= MaxP; j++)
        res = max(res, f[T][j]);
    printf("%d\n", res);
    return 0;
}

int main(){
    scanf("%d", &tcase);
    while (tcase--) {
        input();
        dp();
        output();
    }
    return 0;
}
