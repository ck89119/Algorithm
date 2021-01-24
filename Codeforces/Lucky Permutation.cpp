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
int n;
int p[100005];

int rec(int l,int r){
    if (l>r) return 1;
    if (r==l) {p[l]=l;return 1;}
    if (r==l+1) return 0;
    if (r==l+2) return 0;
    p[l]=l+1;p[l+1]=r;
    p[r]=r-1;p[r-1]=l;
    return rec(l+2,r-2);
}

int main(){
    int i;
    scanf("%d",&n);
    if (rec(1,n)){
        for (i=1;i<=n;i++)
            printf("%d ",p[i]);
        printf("\n");
    }
    else printf("-1\n");
    return 0;
}
