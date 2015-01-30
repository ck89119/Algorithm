/*
ID: ck891191
PROG: ratios
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
    int a[3],b[3],c[3],t[3];
    int i,j,k,l;
    int flag;
    freopen("ratios.in","r",stdin);
    freopen("ratios.out","w",stdout);
    scanf("%d%d%d",&t[0],&t[1],&t[2]);
    scanf("%d%d%d",&a[0],&a[1],&a[2]);
    scanf("%d%d%d",&b[0],&b[1],&b[2]);
    scanf("%d%d%d",&c[0],&c[1],&c[2]);
    flag=1;
    for (i=0;i<100&&flag;i++)
        for (j=0;j<100&&flag;j++)
            for (k=0;k<100&&flag;k++)
                for (l=1;l<100&&flag;l++)
                    if ((i*a[0]+j*b[0]+k*c[0]==l*t[0])&&
                        (i*a[1]+j*b[1]+k*c[1]==l*t[1])&&
                        (i*a[2]+j*b[2]+k*c[2]==l*t[2])){
                            printf("%d %d %d %d\n",i,j,k,l);
                            flag=0;
                    }
    if (flag)
        printf("NONE\n");
    return 0;
}
