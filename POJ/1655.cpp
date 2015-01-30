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
}edge[20005*2];
int head[20005];
int f[20005];
int visited[20005];
int n, k;

int addEdge(int u, int v) {
    edge[k].to = v;
    edge[k].next = head[u];
    head[u] = k;
    k++;
    edge[k].to = u;
    edge[k].next = head[v];
    head[v] = k;
    k++;
    return 0;
}

int dfs(int v) {
    int i;
    int sum, maxSize;
    visited[v] = 1;
    sum = 1; maxSize = 0;
    for (i = head[v]; i != -1; i = edge[i].next) {
        int u = edge[i].to;
        if (!visited[u]) {
            int t = dfs(u);
            maxSize = max(maxSize, t);
            sum += t;
        }
    }

    f[v] = max(maxSize, n-sum);

    return sum;
}

int main(){
    int t;
    cin >> t;
    while (t--) {
        int i, index, res;
        cin >> n;
        k = 0;
        CL(head, -1);
        CL(visited, 0);
        for (i = 0; i < n-1; i++) {
            int u, v;
            cin >> u >> v;
            addEdge(u, v);
        }
        for (i = 1; i <= n; i++) f[i] = INF;
        dfs(1);
        res = INF; index = -1;
        for (i = 1; i <= n; i++)
            if (f[i] < res){
                res = f[i];
                index = i;
            }
        cout << index << ' ' << res << endl;
    }
    return 0;
}
