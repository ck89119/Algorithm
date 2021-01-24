/*
ID: ck891191
PROG: fact4
LANG: C++
*/

#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    int n,i,t;
    freopen("fact4.in","r",stdin);
    freopen("fact4.out","w",stdout);
    scanf("%d",&n);
    t=1;
    for (i=1;i<=n;i++){
        t*=i;
        while (t%10==0) t/=10;
        t=t%10000;
    }
    printf("%d\n",t%10);
    return 0;
}
