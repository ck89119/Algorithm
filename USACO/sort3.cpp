/*
ID: ck891191
PROG: sort3
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,s1[1005],s2[1005],sorted[1005],ret;
int init(){
    int i;
    freopen("sort3.in","r",stdin);
    freopen("sort3.out","w",stdout);
    scanf("%d",&n);
    for (i=0;i<n;i++){
        scanf("%d",&s1[i]);
        s2[i]=s1[i];
    }
    sort(s2,s2+n);
    memset(sorted,0,sizeof(sorted));
    return 0;
}

int solve(){
    int i,j,tmp;
    ret=0;
    for (i=0;i<n;i++)
        if (s1[i]==s2[i]) sorted[i]=1;
    for (i=0;i<n;i++)
        for (j=0;j<n;j++)
            if (!sorted[i]&&!sorted[j]&&s1[i]==s2[j]&&s1[j]==s2[i]){
                sorted[i]=1;sorted[j]=1;
                ret++;
            }
    tmp=0;
    for (i=0;i<n;i++)
        if (sorted[i]) tmp++;
    printf("%d\n",ret+2*(n-tmp)/3);

    return 0;
}

int main(){
    init();
    solve();
    return 0;
}
