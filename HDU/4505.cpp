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
int c,n,a[105];
int max_a;

int main(){
    int tmp,sum;
    int i;
    scanf("%d",&c);
    while (c--){
        scanf("%d",&n);
        max_a=-1;
        memset(a,0,sizeof(a));
        for (i=0;i<n;i++){
            scanf("%d",&tmp);
            a[tmp]++;
            if (tmp>max_a) max_a=tmp;
        }
        sum=10*max_a;
        for (i=0;i<=max_a;i++)
            if (a[i]) sum+=(a[i]+5);
        printf("%d\n",sum);
    }
    return 0;
}
