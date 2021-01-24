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
double sumx,sumy,sum_area;
int T;
int N;
struct CPoint{double x,y;};
double cross(CPoint p0, CPoint p1, CPoint p2){
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}

int main(){
    scanf("%d",&T);
    while (T--){
        CPoint p1,p2,p3;
        int i,tx,ty;
        double area;
        sumx=sumy=sum_area=0.0;
        scanf("%d",&N);
        scanf("%lf%lf%lf%lf",&p1.x,&p1.y,&p2.x,&p2.y);
        for (i=3;i<=N;i++){
            scanf("%lf%lf",&p3.x,&p3.y);
            area=cross(p1,p2,p3);
            sumx+=area*(p1.x+p2.x+p3.x);
            sumy+=area*(p1.y+p2.y+p3.y);
            sum_area+=area;
            p2=p3;
        }
        printf("%.2lf %.2lf\n",sumx/(3.0*sum_area),sumy/(3.0*sum_area));



    }
    return 0;
}
