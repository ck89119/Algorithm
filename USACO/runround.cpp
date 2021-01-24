/*
ID: ck891191
PROG: runround
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int m,digit[15],d_size;
int init(){
    freopen("runround.in","r",stdin);
    freopen("runround.out","w",stdout);
    scanf("%d",&m);
    return 0;
}

int is_runround(int n){
    int b,i,k,tmp[15],visit[10];
    memset(visit,0,sizeof(visit));
    for (i=0;n;i++){
        tmp[i]=n%10;
        if (tmp[i]==0) return 0;
        if (visit[tmp[i]]) return 0;
        visit[tmp[i]]=1;
        n/=10;

    }
    d_size=i;
    digit[0]=tmp[0];
    for (i=1;i<d_size;i++)
        digit[i]=tmp[d_size-i];
    memset(visit,0,sizeof(visit));
    b=1;i=1;
    while (1){
        for (k=0;k<d_size;k++)
            if (!visit[digit[k]]) break;
        if (k>=d_size) break;
        i=(i+digit[i])%d_size;
        if (!visit[digit[i]]) visit[digit[i]]=1;
        else {b=0;break;}

    }
    if (b&&i==1) return 1;
    else return 0;
}

int solve(){
    int i;
    i=m+1;
    while (!is_runround(i)) i++;
    printf("%d\n",i);
}

int main(){
    init();
    solve();
    return 0;
}
