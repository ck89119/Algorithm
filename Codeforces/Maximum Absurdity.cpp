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

int n, k;
const int maxn=200005;
long long int sum[maxn];
int ab[maxn];
long long int MAX[maxn];
int MAXa[maxn];

int input() {
    int i, j;
    long long tmp;
    scanf("%d%d", &n, &k);
    for (i = 1; i <= n; i++) scanf("%d", &ab[i]);
    tmp = 0;
    for (i = 1; i <= n; i++) {
        if (i > k) {
            sum[i-k] = tmp;
            tmp = tmp + ab[i] - ab[i-k];
        }
        else tmp += ab[i];
    }
    sum[n-k+1] = tmp;
    //for (i = 0; i <= n-k; i++) dump(sum[i]);
    return 0;
}

int solve() {
    int i;
    int i1, i2;
    long long res = 0;
    MAX[n-k+1] = sum[n-k+1]; MAXa[n-k+1] = n-k+1;
    for (i = n-k; i >= 1; i--) {
        if (sum[i] >= MAX[i+1]) {
            MAX[i] = sum[i];
            MAXa[i] = i;
        }
        else {
            MAX[i] = MAX[i+1];
            MAXa[i] = MAXa[i+1];
        }
    }
    for (i = 0; i <= n; i++){
        int a = i;
        int b = i + k;
        if (b > n-k+1) break;

        if (sum[a] + MAX[b] > res) {
            res = sum[a] + MAX[b];
            i1 = a; i2 = MAXa[b];
        }
    }

    //dump(sum[])
    printf("%d %d\n", i1, i2);
}

int main(){
    input();
    solve();
    return 0;
}
