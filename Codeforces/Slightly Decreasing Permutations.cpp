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
int n,k;

int main(){
    int i;
    scanf("%d%d",&n,&k);
    for (i=1;i<=n-k-1;i++)
        printf("%d ",i);
    for (i=n;i>=n-k;i--)
        printf("%d ",i);
    printf("\n");
    return 0;
}
