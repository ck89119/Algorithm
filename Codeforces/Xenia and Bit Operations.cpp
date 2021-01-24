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

int tree[1<<18];
int n, m;

int input() {
    int i;
    cin >> n >> m;
    for (i = 1<<n; i < 1<<(n+1); i++)
        scanf("%d", &tree[i]);
    return 0;
}

int solve() {
    int i, j;
    int p, b, k;
    int op = -1;
    for (i = n; i >= 1; i--) {
        op *= -1;
        for (j = (1<<i)-1; j >= 1<<(i-1); j--) {
            //dump(j)
            if (op == 1) tree[j] = (tree[2*j]|tree[2*j+1]);
            else tree[j] = (tree[2*j]^tree[2*j+1]);
        }

    }
    //out(tree, 1<<(n+1));
    for (k = 1; k <= m; k++) {
        int t;
        scanf("%d%d", &p, &b);
        t = (1<<n) + p - 1;
        tree[t] = b; op = -1;
        while (t > 1) {
            op *= -1;
            int tmp = t/2;
            if (op == 1) tree[tmp] = tree[tmp*2]|tree[tmp*2+1];
            else tree[tmp] =  tree[tmp*2]^tree[tmp*2+1];
            t /= 2;
        }
        printf("%d\n", tree[1]);
    }

    return 0;
}

int main() {
    input();
    solve();
    return 0;
}
