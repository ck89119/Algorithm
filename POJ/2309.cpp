/*
ID: ck89119
PROG: POJ2309
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

//int main(){
//    int N;
//    int x,b[33],t[33],i,j,tmp;
//    scanf("%d",&N);
//    while (N--){
//        scanf("%d",&x);
//        b[0]=0;
//        while (x!=0){
//            b[++b[0]]=x%2;
//            x/=2;
//        }
//
//        for (i=0;i<=b[0];i++) t[i]=b[i];
//        i=1;
//        while (!t[i]) i++;
//        tmp=t[i];t[i]=t[1];t[1]=tmp;
//        x=0;
//        for (i=t[0];i>0;i--)
//            x=x*2+t[i];
//        printf("%d ",x);
//
//        for (i=0;i<=b[0];i++) t[i]=b[i];
//        i=1;
//        while (!t[i]) i++;
//        for (j=1;j<i;j++) t[j]=1;
//        x=0;
//        for (i=t[0];i>0;i--)
//            x=x*2+t[i];
//        printf("%d\n",x);
//    }
//    return 0;
//}

int lowbit(int x){return x^(x-1)&x;}

int main(){
    int N;
    int x;
    scanf("%d",&N);
    while (N--){
        scanf("%d",&x);
        printf("%d %d\n",x-lowbit(x)+1,x+lowbit(x)-1);
    }
}
