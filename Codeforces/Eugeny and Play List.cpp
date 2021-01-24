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
const int MAXN = 9999;
const int INF=(1<<30);
const double PI=acos(-1.0);
const double EPS=1e-11;

int n,m;
int end[100000+5];

int main() {
    int i;
    scanf("%d%d", &n,&m);
    end[0]=0;
    for (i=0;i<n;i++) {
        int c,t;
        scanf("%d%d", &c,&t);
        end[i+1]=end[i]+c*t;
    }
    for (i=0;i<m;i++) {
        int v,l,r,mid;
        scanf("%d", &v);
        l=0;r=n;
        while (l<r) {
            mid=(l+r)>>1;
            if (end[mid]>=v) r=mid;
            else l=mid+1;
        }
        printf("%d\n",r);
    }
    return 0;
}
