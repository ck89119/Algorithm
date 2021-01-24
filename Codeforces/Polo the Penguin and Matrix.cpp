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
int m,n,d;
int matrix[105][105];
int number[10005];

int divi(int x,int y){
    if (y*(x/y)==x) return 1;
    else return 0;
}

int main(){
    int i,j;
    int t,minx;
    int res;
    scanf("%d%d%d",&n,&m,&d);
    minx=INF;
    for (i=0;i<n;i++)
        for (j=0;j<m;j++){
            scanf("%d",&matrix[i][j]);
            minx=min(matrix[i][j],minx);
        }
    memset(number,0,sizeof(number));
    for (i=0;i<n;i++)
        for (j=0;j<m;j++){
            matrix[i][j]-=minx;
            if (!divi(matrix[i][j],d)){
                printf("-1\n");
                return 0;
            }
            number[++number[0]]=matrix[i][j]/d;
        }
    sort(number+1,number+number[0]+1);
    res=0;
    if (number[0]%2){
        for (i=1;i<=number[0]/2;i++)
            res+=(number[number[0]/2+1]-number[i]);
        for (i=number[0]/2+2;i<=number[0];i++)
            res+=(number[i]-number[number[0]/2+1]);
    }
    else{
        int res1,res2;
        res1=res2=0;
        for (i=1;i<=number[0];i++)
            res1+=abs(number[number[0]/2]-number[i]);
       for (i=1;i<=number[0];i++)
            res2+=abs(number[number[0]/2+1]-number[i]);
        res+=min(res1,res2);
    }
    printf("%d\n",res);
    return 0;
}
