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
//ifstream fin("");
//ofstream fout("");

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out (vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int MAXN=99999;
const int INF=(1<<30);
const double PI=acos(-1.0);
const double EPS=1e-11;

int n, m;
int c[500005], sum[500005];
int f[500005];

int sumSquare(int i, int j) {
    return (sum[j]-sum[i])*(sum[j]-sum[i]);
}

int sgn(double d1, double d2) {
    if (d1 - d2 > EPS) return 1;
    else if (d2 - d1 > EPS) return -1;
    else return 0;
}

int input() {
    int i, j;
    sum[0] = 0;
    for (i = 1; i <= n; i++) {
        scanf("%d", &c[i]);
        sum[i] = sum[i-1] + c[i];
    }
    return 0;
}

#define q0 q[head]
#define q1 q[head+1]
#define q2 q[tail-2]
#define q3 q[tail-1]

int dp() {
    int i, j;
    int q[500005], head, tail;
    f[0] = 0;
    head = tail = 0;
    q[tail++] = 0;
    for (i = 1; i <= n; i++) {
        //dump(i);
        while (head < tail-1 && f[q1]-f[q0] < sumSquare(q0,i)-sumSquare(q1,i)) head++;
        f[i] = f[q[head]] + sumSquare(q0,i) + m;
        int y1, y2, y3;
        y1 = f[q2] + sumSquare(0, q2);
        y2 = f[q3] + sumSquare(0, q3);
        y3 = f[i] + sumSquare(0, i);
        while (head < tail-1 && sgn((double)(y2-y1)*(sum[i]-sum[q3]),(double)(y3-y2)*(sum[q3]-sum[q2]))>=0) {
            tail--;
            y1 = f[q2] + sumSquare(0, q2);
            y2 = f[q3] + sumSquare(0, q3);
            y3 = f[i] + sumSquare(0, i);
        }
        q[tail++] = i;
    }
    printf("%d\n", f[n]);
    return 0;
}

int main(){
    while (~scanf("%d%d", &n, &m)) {
        input();
        dp();
    }
    return 0;
}
