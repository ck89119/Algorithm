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
const int MAXN=99999;
const int INF=(1<<30);
const double PI=acos(-1.0);
const double EPS=1e-11;

int n, ans[MAXN+5];
vector<int> edge[MAXN+5];
int have[MAXN+5][26];

int input() {
    int i;
    cin>>n;
    for (i = 0; i <= n; i++) edge[i].clear();
    for (i = 0; i < n-1; i++) {
        int a, b;
        cin>>a>>b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
//    for (i = 1; i <= n; i++)
//        for (int j = 0; j < edge[i].size(); j++)
//            cout<<edge[i][j]<<(j == edge[i].size()-1 ? '\n' : ' ');
    return 0;
}

int dfs(int cur, int from) {
    int i, j;
    //dump(cur)
    for (i = 0; i < edge[cur].size(); i++)
        if (edge[cur][i] != from){
            //dump(edge[cur][i])
            dfs(edge[cur][i], cur);
            for (j = 0; j < 26; j++)
                have[cur][j] += have[edge[cur][i]][j];
            }

    int maxTwo = 0;
    for (i = 0; i < 26; i++)
        if (have[cur][i] >= 2) maxTwo = max(maxTwo, i);
    while (have[cur][maxTwo] >= 1)
        maxTwo++;
    for (i = 0; i < maxTwo; i++)
        have[cur][i] = 0;
    have[cur][maxTwo] = 1;
    ans[cur] = maxTwo;
    //dump(ans[cur])
    return 0;
}

int solve() {
    int i;
    CL(have, 0);
    dfs(1, -1);
    for (i = 1; i <= n; i++)
        cout<<char('Z'-ans[i])<<(i == n ? '\n' : ' ');
    return 0;
}

int main(){
    input();
    solve();
    return 0;
}
