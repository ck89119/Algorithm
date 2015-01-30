/*
ID: ck891191
PROG: humble
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=(1<<31)-1;
int p[105],prime[100005],k,n,pindex[105];
int input(){
    int i;
    freopen("humble.in","r",stdin);
    scanf("%d%d",&k,&n);
    for (i=0;i<k;i++) scanf("%d",&p[i]);
    return 0;
}

int solve(){
    int count=1,i,j;
    prime[0]=1;
    memset(pindex,0,sizeof(pindex));
    while (count<=n){
        prime[count]=maxn;
        for (i=0;i<k;i++){
            for (j=pindex[i];;j++)
                if (prime[j]*p[i]>prime[count-1]) break;
            pindex[i]=j;
            if (prime[j]*p[i]<prime[count]) prime[count]=prime[j]*p[i];
        }
        count++;
    }
    return 0;
}

int output(){
    freopen("humble.out","w",stdout);
    printf("%d\n",prime[n]);
    return 0;
}

int main(){
    input();
    solve();
    output();
    return 0;
}
