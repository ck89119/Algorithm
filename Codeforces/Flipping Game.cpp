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

int n;
int a[105];

int main(){
    int i, j, one;
    int m,cnt;
    scanf("%d", &n);
    one = 0;
    for (i=0;i<n;i++) {scanf("%d", &a[i]); if (a[i]==1) one++;}
    m=0;cnt=0;
    for (i=0;i<n;i++){
        if (a[i]==0) cnt++;
        else {
            if (cnt>0) cnt--;
            else cnt=0;
        }
        if (cnt>m) m=cnt;
    }
    if (one == n) printf("%d\n",one-1);
    else printf("%d\n", one+m);

    return 0;
}
