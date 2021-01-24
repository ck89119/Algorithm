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
#define PB(A) push_back(A)
#define PAU system("pause");
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(n) (n^(n-1))&n
#define fin freopen("in.txt","r",stdin);
#define fout freopen("out.txt","w",stdout);
//ifstream fin("");
//ofstream fout("");
#define LL long long

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out (vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int MAXN=99999;
const int MAXM=9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;

int n, m;
LL h[100005], p[100005];
LL dp[2][100005];
//LL q[100005], index[100005], head, tail;

int main() {
    int i, j, k;
    int g1, g2;
    int ma;
    cin >> n >> m;
    for (i = 1; i <= n; i++) scanf("%I64d", &h[i]);
    for (j = 1; j <= m; j++) scanf("%I64d", &p[j]);
    //CLR(dp, INF);
    for (j = 1; j <= m; j++)
        dp[1][j] = (p[j]-p[1]) + min(abs(p[j]-h[1]), abs(p[1]-h[1]));
    dp[1][0] = 0;
    //out(dp, m+1);
    g1 = 0; g2 = 1;
    for (i = 2; i <= n; i++) {
        g1 ^= 1; g2 ^= 1;
        //head = tail = 0;
        //q[tail] = index[tail] = ;

        for (j = 1; j <= m; j++) {
            dp[g2][j] = INF;


            for (k = 0; k < j; k++) {
                LL tmp = (p[j]-p[k+1]) + min(abs(p[j]-h[i]), abs(p[k+1]-h[i]));
                dp[g2][j] = min(dp[g2][j], max(dp[g1][k], tmp));
            }
        //out(dp, m+1);
        }
    }
    cout << dp[g2][m] << endl;
    return 0;
}
