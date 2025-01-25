/*
ID: ck891191
PROG: POJ1806
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

int iabs(int x){
    if (x>0) return x;
    else return -x;
}

int main(){
    int n,u;
    int i,j,k,s,st;
    scanf("%d",&n);
    for (k=1;k<=n;k++){
        scanf("%d",&u);
        printf("Scenario #%d:\n",k);
        for (s=1;s<=2*u+1;s++){
            printf("slice #%d:\n",s);
            st=iabs(u+1-s);
            for (i=0;i<=2*u;i++){
                for (j=0;j<=2*u;j++)
                    if (st+iabs(u-i)+iabs(u-j)<=u) printf("%d",st+iabs(u-i)+iabs(u-j));
                    else printf(".");
                printf("\n");
            }
        }
        printf("\n");
    }
    return 0;
}
