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
#define fin freopen("in.txt","r",stdin);
#define fout freopen("out.txt","w",stdout);
#define LL long long
//ifstream fin("");
//ofstream fout("");

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out (vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int MAXN=99999;
const int INF=(1<<30);
const double PI=acos(-1.0);
const double EPS=1e-11;

int n, m, s[10005];
LL dp[2][10005];

int input() {
    int i;
    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++) scanf("%d", &s[i]);
    sort(s+1, s+n+1);
    return 0;
}

LL DP() {
    int i, j;
    int g1, g2;
    int q[10005], head, tail;
    for (i = 0; i < 2; i++)
        for (j = 0; j <= n; j++)
            dp[i][j] = INF;
    for (i = 1; i <= n; i++)
        dp[1][i] = (s[i]-s[1])*(s[i]-s[1]);

    g1 = 0, g2 = 1;
    for (i = 2; i <= m; i++) {
        g1 ^= 1, g2 ^= 1;
        head = tail = 0;
        q[tail++] = i - 1;
        for (j = i; j <= n; j++) {
            while (head < tail-1) {
                int q1 = q[head], q2 = q[head+1];
                LL t1 = dp[g1][q2] + s[q2+1] * s[q2+1];
                LL t2 = dp[g1][q1] + s[q1+1] * s[q1+1];
                if (t1 - t2 < 2*s[j]*(s[q2+1]-s[q1+1])) head++;
                else break;
            }
            int q1 = q[head], q2 = q[head+1];
            dp[g2][j] = dp[g1][q1] + (s[j]-s[q1+1]) * (s[j]-s[q1+1]);
            while (head < tail-1) {
                int q3 = q[tail-2], q4 = q[tail-1];
                LL t1 = dp[g1][q3] + s[q3+1] * s[q3+1];
                LL t2 = dp[g1][q4] + s[q4+1] * s[q4+1];
                LL t3 = dp[g1][j] + s[j+1] * s[j+1];
                if ((t2-t1)*(s[j+1]-s[q4+1]) >= (t3-t2)*(s[q4+1]-s[q3+1])) tail--;
                else break;
            }
            q[tail++] = j;
        }
       // out();
    }

    return dp[g2][n];
}

int main() {
    int tcase, i;
    scanf("%d", &tcase);
    for (i = 1; i <= tcase; i++) {
        input();
        printf("Case %d: %lld\n", i, DP());
    }
    return 0;
}
