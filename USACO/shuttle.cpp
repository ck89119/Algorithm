/*
ID: ck89119
PROG: shuttle
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
//#include <cstring>
#include <cstdlib>
using namespace std;
#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl;
#define FR(i,a,b) for(int i=(a);i<(b);++i)//[a,b)
#define CLR(a,x) memset(a,x,sizeof(a))
#define MP(A,B) make_pair(A,B)
#define PB push_back
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
const int MAXM=9999999;
const int INF=(1<<30);
const double PI=acos(-1.0);
const double EPS=1e-11;

int n;
int wood[30];
int index;
int res[1000], size;

int swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
    return 0;
}

int main() {
    int i, j, k;
    int op = -1;
    freopen("shuttle.in", "r", stdin);
    freopen("shuttle.out", "w", stdout);
    scanf("%d", &n);
    for (i = 1; i <= n; i++) wood[i] = 1;
    wood[n+1] = 0; index = n+1;
    for (i = n+2; i <= 2*n+1; i++) wood[i] = -1;
    size = 0;
    for (k = 1; k <= 2*n+1; k++) {
        int t;
        op *= -1;
        if (k <= n) t = k;
        if (k == n+1) t = n;
        if (k > n+1) t = 2*n + 2 - k;
        //dump(t);
        if (op == 1) {
            for (j = 1; j <= t; j++) {
                i = index;
                while (wood[i] != op) i--;
                swap(wood[i], wood[index]);
                res[size++] = i;
                index = i;
            }
        }
        else {
            for (j = 1; j <= t; j++) {
                i = index;
                while (wood[i] != op) i++;
                swap(wood[i], wood[index]);
                res[size++] = i;
                index = i;
            }
        }
    }

    for (i = 0; 20*(i+1) < size; i++) {
        for (k = 0; k < 19; k++)
            printf("%d ", res[20*i+k]);
        printf("%d\n", res[20*i+19]);
    }
    if (20 * i < size) {
        for (i = 20*i; i < size-1; i++)
            printf("%d ", res[i]);
        printf("%d\n", res[size-1]);
    }

    return 0;
}
