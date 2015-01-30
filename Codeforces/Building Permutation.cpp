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
int n,a[300005];
long long sum;

int input(){
    int i;
    int tmp;
    scanf("%d",&n);
   // memset(visited,0,sizeof(visited));
    memset(a,0,sizeof(a));
    sum=0;
    for (i=0;i<n;i++){
        scanf("%d",&tmp);
        if (tmp>=1&&tmp<=n) a[tmp]++;
        if (tmp<1){
            a[1]++;
            sum+=(1-tmp);
        }
        if (tmp>n){
            a[n]++;
            sum+=(tmp-n);
        }
    }
    return 0;
}

int solve(){
    int i,min_i;
    for (i=1;i<=n;i++)
        if (!a[i]){min_i=i;break;}
    for (i=1;i<=n;i++)
        while (a[i]>1){
            sum+=abs(i-min_i);
            a[i]--;
            a[min_i]++;
            while (a[min_i]) min_i++;
        }
    printf("%I64d\n",sum);
    return 0;
}

int main(){
    input();
    solve();
    return 0;
}
