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

string wind;
int t,sx,sy,ex,ey;

int main(){
    int dx,dy;
    int n1,n2;
    int i;
    cin>>t>>sx>>sy>>ex>>ey;
    cin>>wind;
    dx=ex-sx;dy=ey-sy;
    n1=0;n2=0;
    for (i=0;i<t;i++){
        if (dx<n1&&wind[i]=='W') n1--;
        if (dx>n1&&wind[i]=='E') n1++;
        if (dy<n2&&wind[i]=='S') n2--;
        if (dy>n2&&wind[i]=='N') n2++;
        if (n1==dx&&n2==dy) break;
    }
    if (i!=t) cout<<i+1<<endl;
    else cout<<-1<<endl;
   return 0;
}
