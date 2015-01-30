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
long long n,k;

int main(){
    long long i;
    int sum;
    scanf("%I64d%I64d",&n,&k);
    n--;sum=0;
    if (k*(k-1)/2<n) {printf("-1\n");return 0;}
    for (i=k-1;i>=1&&n>0;i--){
        n-=i;
        sum++;
    }
    if (n<=0) printf("%d\n",sum);
    else printf("-1\n");
    return 0;
}
