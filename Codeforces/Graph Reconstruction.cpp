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

struct Edge {
    int to;
    int w;
    int next;
};
int head[100005];
Edge edge[2*100005];
int n, m;
int vis[100005];

int input() {
    int i, k;
    scanf("%d%d", &n, &m);
    CL(head, -1); k = 0;
    for (i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        edge[k].to = v;
        edge[k].next = head[u];
        head[u] = k;
        k++;

        edge[k].to = u;
        edge[k].next = head[v];
        head[v] = k;
        k++;
    }
    return 0;
}

int solve () {
    int cur;
    CL(vis, 0);
    if (4*m > n*(n-1)) {
        cout << -1 << endl;
        return 0;
    }

    cur = 1; vis[1] = 1;
    for (i = 0; i < m; i++) {
        int j, k;
        int con[3];
        k = 0;
        for (j = head[cur]; j != -1; j = edge[j].next) {
            con[k] = edge[j].to;
            k++;
        }
        con[k] = -1;

        j = 1;
        while (j <= n) {
            if (vis[j]) {j++; continue;}
            k = 0;
            while (con[k] != j) k++;

        }
    }

    return 0;
}

int main(){

    return 0;
}
