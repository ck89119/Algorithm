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

int n, m;
int start[105], end[105];
int v[105];

int dfs(int cur, int target) {
    int i;
    v[cur] = 1;
    if (cur == target) return 1;
    for (i = 0; i < m; i++){
        if (v[i]) continue;
        if (start[i] < start[cur] && end[i] > start[cur]) {
            if (dfs(i, target)) return 1;
        }
        else if (start[i] < end[cur] && end[i] > end[cur]) {
            if (dfs(i, target)) return 1;
        }
    }
    return 0;
}

int main(){
    int i, k;
    cin>>n;
    m = 0;
    for (k = 0; k < n; k++) {
        int type, x, y;
        cin>>type>>x>>y;
        if (type == 1) {
            start[m] = x;
            end[m] = y;
            m++;
        }
        else {
            CL(v, 0);
            if (dfs(x-1, y-1)) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}
