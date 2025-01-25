/*
ID: ck891191
PROG:
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
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
const long long MAXN=(1LL<<62);
const int INF=(1<<30);
const double PI=acos(-1.0);
const double EPS=1e-11;

int t;
long long a,b;
int sq[10000000+5];

int pal(int x){
    int num[15];
    int l,r;
    num[0]=0;
    while (x!=0){
        ++num[0];
        num[num[0]]=x%10;
        x/=10;
    }
    l=1;r=num[0];
    while (l<r){
        if (num[l]==num[r]){l++;r--;}
        else break;
    }
    if (l<r) return 0;
    else return 1;
}

int llpal(long long x){
    int num[20];
    int l,r;
    num[0]=0;
    while (x!=0){
        ++num[0];
        num[num[0]]=x%10;
        x/=10;
    }
    l=1;r=num[0];
    while (l<r){
        if (num[l]==num[r]){l++;r--;}
        else break;
    }
    if (l<r) return 0;
    else return 1;
}

int main(){
    int k,i;
    freopen("C-large-1.in","r",stdin);
    freopen("C-large-1.out","w",stdout);
    scanf("%d",&t);
    for (k=1;k<=t;k++){
        int l,r;
        int res;
        scanf("%lld%lld",&a,&b);
        l=(int)sqrt(a)-1;r=(int)sqrt(b)+1;
        res=0;
        for (i=l;i<=r;i++){
            long long tmp;
            tmp=i*i;
            if (tmp<a||tmp>b) continue;
            if (pal(i)&&llpal(tmp)) res++;
        }
        printf("Case #%d: %d\n",k,res);
    }
    return 0;
}
