/*
ID: ck89119
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

int main(){
    int a[105][105],dp[105][105];
    int i,j,ans=0;
    for (i=0;i<100;i++)
        for (j=0;j<=i;j++)
            scanf("%d",&a[i][j]);
    memset(dp,0,sizeof(dp));
    for (i=99;i>=0;i--)
        for (j=0;j<=i;j++){
            dp[i][j]=a[i][j]+max(dp[i+1][j],dp[i+1][j+1]);
        }
    printf("%d\n",dp[0][0]);
    return 0;
}
