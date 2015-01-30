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
#define dump(x) cout <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl;
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

int n, m;
LL a[1005], sum[1005], w[1005];
LL f[2][1005];

int input() {
    int i;
    w[0] = 0; sum[0] = 0;
    for (i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        sum[i] = sum[i-1] + a[i];
        w[i] = w[i-1] + a[i] * sum[i-1];
       // dump(i) dump(sum[i]) dump(w[i])
    }
    return 0;
}

#define k1 q[head]
#define k2 q[head+1]
#define k3 q[tail-2]
#define k4 q[tail-1]

long long S(int x) {
    return w[x]-sum[x]*sum[x];
}

int dp() {
    int q[1005], head, tail;
    int i, j;
    int g1, g2;
    for (i = 0; i <= 1; i++)
        for (j = 0; j <= n; j++)
            f[i][j] = INF;
    for (j = 1; j <= n; j++)
        f[1][j] = w[j];

    g1 = 0; g2 = 1;
    for (i = 2; i <= m+1; i++) {
        g1 ^= 1; g2 ^= 1;
        head = tail = 0;
        q[tail++] = 1;
        for (j = 2; j <= n; j++) {
            while (head < tail-1 ) {
                long long p;
                p = f[g1][k2] - S(k2) - f[g1][k1] + S(k1);
                if (p < sum[j]*(sum[k2]-sum[k1])) head++;
                else break;
            }
            f[g2][j] = f[g1][k1] + w[j] - w[k1] - sum[k1] * (sum[j] - sum[k1]);
            while (head < tail-1 ) {
                long long p, pp;
                p = f[g1][j] - S(j) - f[g1][k4] + S(k4);
                pp = f[g1][k4] - S(k4) - f[g1][k3] + S(k3);
                if ((sum[k4]-sum[k3])*p < (sum[j]-sum[k4])*pp) tail--;
                else break;
            }
            q[tail++] = j;
        }
        //out();
    }
    printf("%lld\n", f[g2][n]);
    return 0;
}

int main() {
    //fin;fout;
    while (scanf("%d%d", &n, &m), m + n) {
        input();
        dp();
    }
    return 0;
}
