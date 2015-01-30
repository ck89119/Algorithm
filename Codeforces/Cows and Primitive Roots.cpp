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

int p;

int cal(int x,int n){
    if (n==1) return x%p;
    else if (n%2==0) return cal(x,n/2)*cal(x,n/2)%p;
    else return cal(x,n/2)%p*cal(x,n/2)%p*x%p;
}

int main(){
    int i,j,sum;
    scanf("%d",&p);
    sum=0;
    for (i=1;i<p;i++){
        if ((cal(i,p-1)-1)%p!=0) continue;
        for (j=1;j<=p-2;j++)
            if ((cal(i,j)-1)%p==0) break;
        if (j<=p-2) continue;
        sum++;
    }
    printf("%d\n",sum);
    return 0;
}
