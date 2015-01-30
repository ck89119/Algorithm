/*
ID: ck891191
PROG: POJ1401
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

int main(){
    int t,n,ret;
    scanf("%d",&t);
    while (t--){
        int s=1;
        ret=0;
        scanf("%d",&n);
        while (n>s){
            s*=5;
            ret+=(n/s);
        }
        printf("%d\n",ret);
    }

    return 0;
}
