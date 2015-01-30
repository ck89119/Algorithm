/*
ID: ck891191
PROG:
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define dump(x) cerr<<__LINE__<<"  "<<#x<<"  :  "<<(x)<<endl;
#define two(X) (1<<(X))
#define towL(X) (((int64)(1))<<(x))
#define contain(S,X) ((S&two(X))>0)
#define containL(S,X) ((S&twoL(X))>0)
#define FR(i,a,b) for(int i=(a);i<(b);++i)//[a,b)
#define FOR(i,n) FR(i,0,n)//[0,n)
#define RF(i,a,b) for(int i=(a)-1;i>=(b);--i)//(a,b]
#define ROF(i,n) RF(i,n,0)//[0,n)
#define CL(a,x) memset(a,x,sizeof(a))

const int INF=(1<<30);
const double PI=acos(-1.0);
const double EPS=1e-11;


int main(){
    int n,e,t,i;
    double l1,l2;
    scanf("%d%d",&n,&e);
    l1=l2=0.0;
    for (i=1;i<n;i++){scanf("%d",&t);l1+=t;}
    for (i=1;i<e;i++){scanf("%d",&t);l2+=t;}
    //dump(l1)dump(l2)
    printf("%d\n",(int)ceil(sqrt(l1*l1+l2*l2)));
    //printf("%d\n",(int)ceil(1.0));
    return 0;
}
