/*
ID: ck891191
PROG: shopping
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
const int INF=9999999;
int s,b;
struct REDUCE{
    int code[5],index[5],num[5];
    int price;
    int n;
};
REDUCE reduce[100];
struct PRODUCT{
    int code;
    int num;
    int price;
};
PRODUCT product[5];
int dp[6][6][6][6][6];
int code[1000];

int input(){
    int i,j,n,c,k,p;
    freopen("shopping.in","r",stdin);
    scanf("%d",&s);
    for (i=0;i<s;i++){
        reduce[i].n=0;
        reduce[i].price=0;
        for (j=0;j<5;j++){
            reduce[i].code[j]=0;
            reduce[i].index[j]=0;
            reduce[i].num[j]=0;
        }
    }
    for (i=0;i<s;i++){
        scanf("%d",&n);
        reduce[i].n=n;
        for (j=0;j<n;j++){
            scanf("%d%d",&c,&k);
            reduce[i].code[j]=c;
            reduce[i].num[j]=k;
        }
        scanf("%d",&reduce[i].price);
    }
    scanf("%d",&b);
    for (i=0;i<5;i++){
        product[i].code=0;
        product[i].num=0;
        product[i].price=0;
    }
    for (i=0;i<b;i++){
        scanf("%d%d%d",&c,&k,&p);
        product[i].code=c;
        code[c]=i;
        product[i].num=k;
        product[i].price=p;
    }
    for (i=0;i<s;i++)
        for (j=0;j<reduce[i].n;j++)
            reduce[i].index[code[reduce[i].code[j]]]=reduce[i].num[j];
    return 0;
}

int solve(){
    int i,k1,k2,k3,k4,k5;
    for (k1=0;k1<=5;k1++)
        for (k2=0;k2<=5;k2++)
            for (k3=0;k3<=5;k3++)
                for (k4=0;k4<=5;k4++)
                    for (k5=0;k5<=5;k5++)
                        dp[k1][k2][k3][k4][k5]=k1*product[0].price+k2*product[1].price+k3*product[2].price+
                                               k4*product[3].price+k5*product[4].price;
    //dp[0][0][0][0][0]=0;
    for (i=0;i<s;i++){
        int u1,u2,u3,u4,u5;
        u1=reduce[i].index[0];
        u2=reduce[i].index[1];
        u3=reduce[i].index[2];
        u4=reduce[i].index[3];
        u5=reduce[i].index[4];
        for (k1=u1;k1<=5;k1++)
            for (k2=u2;k2<=5;k2++)
                for (k3=u3;k3<=5;k3++)
                    for (k4=u4;k4<=5;k4++)
                        for (k5=u5;k5<=5;k5++)
                            dp[k1][k2][k3][k4][k5]=min(dp[k1][k2][k3][k4][k5],
                            dp[k1-u1][k2-u2][k3-u3][k4-u4][k5-u5]+reduce[i].price);
    }
    return 0;
}

int output(){
    freopen("shopping.out","w",stdout);
    printf("%d\n",dp[product[0].num][product[1].num][product[2].num][product[3].num][product[4].num]);
    return 0;
}
int main(){
    input();
    solve();
    output();
    return 0;
}
