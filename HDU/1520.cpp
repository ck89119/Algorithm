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
//int head[6005];
const int MAXN=99999;
const int INF=(1<<30);
const double PI=acos(-1.0);
const double EPS=1e-11;

struct Edge {
    int to;
    int w;
    int next;
};
Edge edge[6005];
int head[6005];
int weight[6005];
int isRoot[6005], root;
int n;
int dp[6005][2];

int input() {
    int i, k;
    int a, b;
    for (i = 1; i <= n; i++)
        scanf("%d", &weight[i]);
    //weight[0] = 0;
    CL(head, -1); CL(isRoot, 0);
    k = 0;
    //cin >> a >> b;
    scanf("%d%d", &a, &b);
    while (a + b) {
//        edge[k].to = b;
//        edge[k].next = head[a];
//        head[a] = k;
//        k++;
        isRoot[a] = 1;
        edge[k].to = a;
        edge[k].next = head[b];
        head[b] = k;
        k++;
        //cin >> a >> b;
        scanf("%d%d", &a, &b);
    }
    for (i = 1; i <= n; i++)
        if (!isRoot[i]) {
            root = i;
            break;
        }
//    dump(n)dump(root)
//    for (i = 1; i <= n; i++) cout<<head[i]<<' ';cout<<endl;
    return 0;
}

int treeDp(int v) {
    int i;
    dp[v][0] = 0;
    dp[v][1] = weight[v];
    if (head[v] == -1) return 0;
    for (i = head[v]; i != -1; i = edge[i].next) {
        int k;
        k = edge[i].to;
        treeDp(k);
        dp[v][0] += max(dp[k][0],dp[k][1]);
        dp[v][1] += dp[k][0];
    }
    return 0;
}


int main(){
    while (cin>>n) {
        input();
        treeDp(root);
        cout << max(dp[root][0], dp[root][1]) << endl;
    }
    return 0;
}
