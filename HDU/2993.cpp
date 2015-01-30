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

int n, k;
long long sum[100005];
int a[100005];
int q[100005];

int GetInt(){
     char ch=getchar();
     while(ch<'0'||ch>'9')ch=getchar();
     int num=0;
     while(ch>='0'&&ch<='9'){
         num=num*10+ch-'0';
         ch=getchar();
     }
     return num;
}

int input() {
    int i;
    sum[0] = 0;
    for (i = 1; i <= n; i++) {
        a[i] = GetInt();
        //scanf("%d", &a[i]);
        sum[i] = sum[i-1] + a[i];
    }
    return 0;
}

int solve() {
    int head, tail;
    int i;
    double ans = 0;

    head = tail = 0;
    for (i = k; i <= n; i++) {
        int now = i - k;
        while (head + 1 < tail) {
            long long dx1, dy1, dx2, dy2;
            dx1 = q[tail-1] - q [tail-2];
            dy1 = sum[q[tail-1]] - sum[q[tail-2]];
            dx2 = now - q[tail-1];
            dy2 = sum[now] - sum[q[tail-1]];
            if (dy1 * dx2 >= dy2 * dx1) tail--;
            else break;
        }
        q[tail++] = now;

        while (head + 1 < tail) {
            long long dx1, dy1, dx2, dy2;
            dx1 = q[head+1] - q[head];
            dy1 = sum[q[head+1]] - sum[q[head]];
            dx2 = i - q[head];
            dy2 = sum[i] - sum[q[head]];
            if (dy2 * dx1 > dy1 * dx2) head++;
            else break;
        }

        ans = max(ans, (1.0*sum[i]-sum[q[head]])/(i-q[head]));
    }
    printf("%.2lf\n", ans);
    return 0;
}

int main(){
    while (scanf("%d%d", &n, &k)!=EOF) {
        input();
        solve();
    }
    return 0;
}
