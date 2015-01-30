/*
ID: ck89119
PROG:
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
using namespace std;
#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl;
#define FR(i,a,b) for(int i=(a);i<(b);++i)//[a,b)
#define CL(a,x) memset(a,x,sizeof(a))
#define MP(A,B) make_pair(A,B)
#define two(X) (1<<(X))
#define towL(X) (((int64)(1))<<(x))
#define contain(S,X) ((S&two(X))>0)
#define containL(S,X) ((S&twoL(X))>0)
#define lowbit(x) ((x)&(-(x)))
//freopen("","r",stdin);
//freopen("","w",stdout);

const int INF=(1<<30);
const double PI=acos(-1.0);
const double EPS=1e-11;
const int  MAXN = 100 + 5;
int p[MAXN];
int map[MAXN][MAXN];
int n,nc,np,m;

int EK_bfs(int src, int sink) {
    int i, flag;
    queue<int> q;
    int inque[MAXN];
    CL(inque, 0); CL(p, -1);
    while (!q.empty()) q.pop();
    q.push(src);
    inque[src] = 1;
    flag = 0;
    while (!q.empty()) {
        int t;
        t = q.front(); q.pop();
        if (t == sink) {
            flag = 1;
            break;
        }
  //      for (i = 0; i <= n+1; i ++)
            if (map[t][i] && !inque[i]) {
                q.push(i);
                inque[i] = 1;
                p[i] = t;
            }
    }
    return flag;
}

int EK_Max_Flow(int src, int sink) {
    int max_flow;
    max_flow = 0;
    while (EK_bfs(src, sink)) {
        int flow;
        int i;
        flow = INF;
        for (i = sink; i != src; i = p[i]) {
            flow = min(flow, map[p[i]][i]);
        }
        max_flow += flow;
        for (i = sink; i != src; i = p[i]) {
            map[p[i]][i] -= flow;
            map[i][p[i]] += flow;
        }
    }
    return max_flow;
}

int trans(char s[50], int &a, int &b, int &c) {
    int i = 1;
    a = b = c = 0;
    while (s[i] != ',') {
        a = a*10 + s[i] - '0';
        i ++;
    }
    i ++;
    while (s[i] != ')') {
        b = b*10 + s[i] - '0';
        i ++;
    }
    i ++;
    while (s[i] != '\0') {
        c = c*10 + s[i] - '0';
        i ++;
    }
    return 0;
}

int trans1(char s[50], int &a, int &b) {
    int i = 1;
    a = b = 0;
    while (s[i] != ')') {
        a = a * 10 + s[i] - '0';
        i ++;
    }
    i ++;
    while (s[i] != '\0') {
        b = b * 10 + s[i] - '0';
        i ++;
    }
    return 0;
}

int main(){
    while (scanf("%d%d%d%d", &n, &np, &nc, &m) != EOF) {
        char s[50];
        int i, a, b, c;
        CL(map, 0);
        for (i = 0; i < m; i ++) {
            scanf("%s", s);
            trans(s, a, b, c);
            map[a][b] = c;
        }
        for (i = 0; i < np; i++) {
            scanf("%s", s);
            trans1(s, a, b);
            map[n][a] = b;
        }
        for (i = 0; i < nc; i++) {
            scanf("%s", s);
            trans1(s, a, b);
            map[a][n+1] = b;
        }
        printf("%d\n",EK_Max_Flow(n, n+1));

    }
    return 0;
}
