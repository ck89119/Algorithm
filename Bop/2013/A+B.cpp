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
    char stra[105],strb[105];
    int a[105],b[105],c[105];
    int i;
    scanf("%s%s",stra,strb);
    CL(a,0);CL(b,0);CL(c,0);
    a[0]=strlen(stra);
    b[0]=strlen(strb);
    for (i=1;i<=a[0];i++) a[i]=stra[a[0]-i]-'0';
    for (i=1;i<=b[0];i++) b[i]=strb[b[0]-i]-'0';
    c[0]=max(a[0],b[0]);
    for (i=1;i<=c[0];i++) c[i]=a[i]+b[i];
    for (i=1;i<=c[0];i++){
        c[i+1]+=c[i]/10;
        c[i]%=10;
    }
    if (c[c[0]+1]) c[0]++;
    for (i=c[0];i>=1;i--)
        printf("%d",c[i]);
    printf("\n");
    return 0;
}

