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

int reverse(int n){
    int ret=0;
    while (n){
        ret=ret*10+n%10;
        n/=10;
    }
    return ret;
}

int main(){
    int N,a,b;
    int i;
    scanf("%d",&N);
    for (i=0;i<N;i++){
        scanf("%d %d",&a,&b);
        printf("%d\n",reverse(reverse(a)+reverse(b)));
    }
    return 0;
}
