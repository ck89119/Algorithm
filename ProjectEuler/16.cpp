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
    int a[320],i,j,ans;
    memset(a,0,sizeof(a));
    a[0]=1;a[1]=1;
    for (i=1;i<=1000;i++){
        for (j=1;j<=a[0];j++)
            a[j]*=2;
        for (j=1;j<=a[0];j++){
            a[j+1]+=a[j]/10;
            a[j]%=10;
        }
        if (a[a[0]+1]!=0) a[0]++;
    }
    ans=0;
    for (i=1;i<=a[0];i++) ans+=a[i];
    printf("%d\n",ans);
    return 0;
}
