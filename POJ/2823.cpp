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
int a[1000005];
int q[1000005], index[1000005], head, tail;

int getInt() {
    int n = 0;
    int op = 1;
    char ch = getchar();
    while ((ch > '9' || ch < '0') && ch != '-') ch = getchar();
    if (ch == '-') {op = -1;ch = getchar();}
    while (ch <= '9' && ch >= '0') {
        n = n * 10 + ch - '0';
        ch = getchar();
    }
    return n*op;
}

int input() {
    int i;
    scanf("%d%d", &n, &k);
    for (i = 1; i <= n; i++)
        a[i] = getInt();
    return 0;
}

int getmin() {
    int i;
    head = tail = 0;
    for (i = 1; i < k; i++) {
        while (head < tail && q[tail-1] > a[i]) tail--;
        q[tail] = a[i];
        index[tail++] = i;
    }

    for (i = k; i <= n; i++) {
        while (head < tail && q[tail-1] > a[i]) tail--;
        q[tail] = a[i];
        index[tail++] = i;
        while (head < tail && index[head] <= i-k) head++;
        if (i != n) printf("%d ", q[head]);
        else printf("%d\n", q[head]);
    }

    return 0;
}

int getmax() {
    int i;
    head = tail = 0;
    for (i = 1; i < k; i++) {
        while (head < tail && q[tail-1] < a[i]) tail--;
        q[tail] = a[i];
        index[tail++] = i;
    }

    for (i = k; i <= n; i++) {
        while (head < tail && q[tail-1] < a[i]) tail--;
        q[tail] = a[i];
        index[tail++] = i;
        while (head < tail && index[head] <= i-k) head++;
        if (i != n) printf("%d ", q[head]);
        else printf("%d\n", q[head]);
    }

    return 0;
}

int main(){
    input();
    getmin();
    getmax();
    return 0;
}
