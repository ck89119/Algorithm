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
#include <cstdlib>
using namespace std;
#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl;
#define FR(i,a,b) for(int i=(a);i<(b);++i)//[a,b)
#define CL(a,x) memset(a,x,sizeof(a))
#define two(X) (1<<(X))
#define towL(X) (((int64)(1))<<(x))
#define contain(S,X) ((S&two(X))>0)
#define containL(S,X) ((S&twoL(X))>0)
//freopen("","r",stdin);
//freopen("","w",stdout);
const long long MAXN=(1LL<<62);
const int INF=(1<<30);
const double PI=acos(-1.0);
const double EPS=1e-11;

struct Interval{
    int a,b;
};
Interval inv[50005];
int n;

int cmp(const Interval &a,const Interval &b){
    if (a.a!=b.a) return a.a<b.a;
    else return a.b<b.b;
}

int main(){
    int k;
    scanf("%d",&n);
    FR(i,0,n)
        scanf("%d%d",&inv[i].a,&inv[i].b);
    sort(inv,inv+n,cmp);
    k=0;

    while (k<n){
        int r=inv[k].b;
        printf("%d ",inv[k].a);
        while (r>=inv[k+1].a&&k<n) {
            r=max(r,inv[k+1].b);
            k++;
        }
        printf("%d\n",r);
        k++;
    }


    return 0;
}
