/*
ID: ck891191
PROG: POJ2242
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
const double PI=3.141592653589793;

double len(double x1,double y1,double x2,double y2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main(){
    double x1,y1,x2,y2,x3,y3;
    double a,b,c,p,s,d;
    while (scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3)!=EOF){
        a=len(x2,y2,x3,y3);
        b=len(x1,y1,x3,y3);
        c=len(x1,y1,x2,y2);
        p=(a+b+c)/2;
        s=sqrt(p*(p-a)*(p-b)*(p-c));
        d=a*b*c/2/s;
        printf("%.2lf\n",PI*d);
    }
    return 0;
}
