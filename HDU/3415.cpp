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
const int MAXN=99999;
const int INF=(1<<30);
const double PI=acos(-1.0);
const double EPS=1e-11;

int n, k;
int a[200005], sum[200005];
int q[200005], index[200005], head, tail;
int res, start, end;


int main(){
    int t;
    int i;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &k);
        sum[0] = 0;
        for (i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            sum[i] = sum[i-1] + a[i];
        }
        for (i = n+1; i <= n+n; i++) {
            a[i] = a[i-n];
            sum[i] = sum[i-1] + a[i];
        }
        res = -INF;
        head = tail = 0;
        q[0] = sum[0]; index[0] = 0; tail++;
        for (i = 1; i <= n+k-1; i++) {

            while (head < tail && index[head] < i-k) head++;
            if (res < sum[i] - q[head]) {
                res = sum[i] - q[head];
                start = index[head] + 1;
                end = i;
                if (end > n) end -= n;
            }

            while (head < tail && q[tail-1] > sum[i]) tail--;
            q[tail] = sum[i];
            index[tail++] = i;
        }
        printf("%d %d %d\n", res, start, end);

    }
    return 0;
}
