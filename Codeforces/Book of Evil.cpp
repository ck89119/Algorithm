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

struct EDGE {
    int to, w;
    int next;
}edge[100005*2];

int n, m, d;
int mark[100005];
int head[100005];
int k;
int disDown[100005], disUp[100005];

int addEdge(int u, int v) {
    edge[k].to = v;
    edge[k].next = head[u];
    head[u] = k++;
    edge[k].to = u;
    edge[k].next = head[v];
    head[v] = k++;
    return 0;
}

int input() {
    int i;
    scanf("%d%d%d", &n, &m, &d);
    CLR(mark, 0);
    for (i = 0; i < m; i++) {
        int t;
        scanf("%d", &t);
        mark[t] = 1;
    }
    CLR(head, -1); k = 0;
    for (i = 0; i < n-1; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        addEdge(u, v);
    }
    return 0;
}

int dfs1(int v, int pre) {
    int i;
    disDown[v] = mark[v]?0:-1;
    for (i = head[v]; i != -1; i = edge[i].next) {
        int u = edge[i].to;
        if (u == pre) continue;
        int d = dfs1(u, v);
        if (d != -1)
            disDown[v] = max(disDown[v], d+1);
    }
    return disDown[v];
}

int dfs2(int v, int pre) {
    int i;
    int max1, max2;
    max1 = max2 = -1;
    for (i = head[v]; i != -1; i = edge[i].next) {
        int u = edge[i].to;
        if (u == pre) continue;
        if (disDown[u] > max1) {
            max2 = max1;
            max1 = disDown[u];
        }
        else if (disDown[u] > max2) {
            max2 = disDown[u];
        }
    }

    for (i = head[v]; i != -1; i = edge[i].next) {
        int u = edge[i].to;
        if (u == pre) continue;
        int broDis;
        broDis = (disDown[u]==max1)?max2:max1;
        if (broDis != -1) broDis += 2;
        disUp[u] = broDis;
        if (disUp[v] != -1)
            disUp[u] = max(disUp[u], disUp[v]+1);
        if (mark[u])
            disUp[u] = max(disUp[u], 0);
        dfs2(u, v);
    }
    return 0;
}

int solve() {
    int res;
    int i;
    dfs1(1, -1);
    disUp[1] = mark[1]?0:-1;
    dfs2(1, -1);
    //out(disDown, n+1);out(disUp, n+1);
    res = 0;
    for (i = 1; i <= n; i++)
        res += (disDown[i]<=d&&disUp[i]<=d)?1:0;
    printf("%d\n", res);
    return 0;
}

int main(){
    input();
    solve();
    return 0;
}
