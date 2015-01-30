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

int f[200];
int first[7][7];
int main(){
    int a,b,n;
    int i;
    while (scanf("%d%d%d",&a,&b,&n),a|b|n){
        if (n==1||n==2){
            printf("%d\n",1);
            continue;
        }
        memset(first,0,sizeof(first));
        memset(f,0,sizeof(f));
        f[1]=1;f[2]=1;
        first[1][1]=2;
        i=3;
        while (i<=n){
            f[i]=(a*f[i-1]+b*f[i-2])%7;//dump(f[i]);
            if (first[f[i-1]][f[i]]) break;
            first[f[i-1]][f[i]]=i;
            i++;
        }
        if (i>n) printf("%d\n",f[n]);
        else {
            int st=first[f[i-1]][f[i]];
            int mod=i-st;
            printf("%d\n",f[st+(n-st)%mod]);
        }
    }
    return 0;
}
