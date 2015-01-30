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
const int MAXN=99999;
const int INF=(1<<30);
const double PI=acos(-1.0);
const double EPS=1e-11;

long long a[100005], b[100005];
long long dp[100005];
int n;

int input() {
    int i;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        scanf("%I64d", &a[i]);
    for (i = 1; i <= n; i++)
        scanf("%I64d", &b[i]);
    return 0;
}

#define q0 q[head]
#define q1 q[head+1]
#define q2 q[tail-2]
#define q3 q[tail-1]

int sgn(double d1, double d2) {
    if (d1 - d2 > EPS) return 1;
    else if (d2 - d1 > EPS) return -1;
    else return 0;
}

int solve() {
    int i, j;
    long long q[100005], head, tail;
    CLR(dp, -1);
    dp[1] = 0;
    head = tail = 0;
    q[tail++] = 1;
    for (i = 2; i <= n; i++) {
        while (head < tail-1 && dp[q1]-dp[q0] <= a[i]*(b[q0]-b[q1]))
            head++;
        dp[i] = dp[q0] + a[i] * b[q0];
        while (head < tail-1 && sgn((double)(dp[q3]-dp[q2])*(b[i]-b[q3]), (double)(dp[i]-dp[q3])*(b[q3]-b[q2]))<=0)
            tail--;
        q[tail++] = i;
    }
    printf("%I64d", dp[n]);
    return 0;
}


int main(){
    input();
    solve();
    return 0;
}
