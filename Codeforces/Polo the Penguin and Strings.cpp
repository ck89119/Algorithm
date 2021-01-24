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
int n,k;
char str[1000005];
int main(){
    int i;
    scanf("%d%d",&n,&k);
    if (k>n) printf("-1\n");
    else if (k==1&&n>1) printf("-1\n");
    else{
        for (i=0;i<n-k+2;i++)
            if (i%2) str[i]='b';
            else str[i]='a';
        for (i=n-k+2;i<n;i++)
            str[i]='a'+(i-n+k);
        str[n]='\0';
        printf("%s\n",str);
    }
    return 0;
}
