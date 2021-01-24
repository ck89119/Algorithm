/*
ID: ck891191
PROG: game1
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
int N,board[205];
int sum[205][205];
int dp[205][205];

int input(){
    int i,j;
    freopen("game1.in","r",stdin);
    freopen("game1.out","w",stdout);
    scanf("%d",&N);
    memset(sum,0,sizeof(sum));
    for (i=0;i<N;i++){
        scanf("%d",&board[i]);
        sum[i][i]=board[i];
    }
    for (i=0;i<N;i++)
        for (j=i+1;j<N;j++)
            sum[i][j]=sum[i][j-1]+board[j];
    return 0;
}

int solve(){
    int i,j;
    for (i=0;i<N;i++)
        dp[i][i]=sum[i][i];
    for (i=N-2;i>=0;i--)
        for (j=i+1;j<N;j++)
            dp[i][j]=sum[i][j]-min(dp[i][j-1],dp[i+1][j]);
    printf("%d %d\n",dp[0][N-1],sum[0][N-1]-dp[0][N-1]);
    return 0;
}

//
//int solve(){
//    int i;
//    int sum_o,sum_e;
//    if (N%2){
//        int sum1=0,sum2=0;
//        sum_e=0;sum_o=0;
//        sum1+=board[0];
//        for (i=1;i<N;i+=2)
//            sum_o+=board[i];
//        for (i=2;i<N;i+=2)
//            sum_e+=board[i];
//        sum1+=min(sum_e,sum_o);
//
//        sum_e=0;sum_o=0;
//        sum2+=board[N-1];
//        for (i=1;i<N-1;i+=2)
//            sum_o+=board[i];
//        for (i=0;i<N-1;i+=2)
//            sum_e+=board[i];
//        sum2+=min(sum_e,sum_o);
//
//        printf("%d %d\n",max(sum1,sum2),sum-max(sum1,sum2));
//
//    }
//    else{
//        sum_e=0;sum_o=0;
//        for (i=0;i<N;i+=2)
//            sum_e+=board[i];
//        for (i=1;i<N;i+=2)
//            sum_o+=board[i];
//        printf("%d %d\n",max(sum_e,sum_o),min(sum_e,sum_o));
//    }
//    return 0;
//}

int main(){
    input();
    solve();
    return 0;
}
