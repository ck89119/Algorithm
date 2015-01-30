/*
ID: ck891191
PROG: POJ1799
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
double pi=acos(-1.0);

int main(){
    int n,t,i;
    double R,r;
    scanf("%d",&t);
    for (i=1;i<=t;i++){
        scanf("%lf%d",&R,&n);
        r=R*sin(pi/n);
        r=r/(1+sin(pi/n));
        printf("Scenario #%d:\n",i);
        printf("%.3f\n\n",r);
    }
    return 0;
}
