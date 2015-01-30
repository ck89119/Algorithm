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
const double pi	= acos(-1.0);
const double eps=1e-10;
struct CPoint{double x,y,z;};
double sqr(double x){return x*x;}
int dcmp(double x){if (x<-eps) return -1;else return (x>eps);}
//distance square
double dissqr(CPoint p1, CPoint p2){
    return sqr(p1.x-p2.x)+sqr(p1.y-p2.y)+sqr(p1.z-p2.z);
}
CPoint s[105];
CPoint O;
double l[105];
double r;
int k,m;
int sum;

int input(){
    int i,j;
    CPoint tmp;
    r=20000.0/pi;
    O.x=O.y=O.z=0.0;
    while (scanf("%d%d",&k,&m),k+m){
        sum=0;
        for (i=0;i<k;i++){
            scanf("%lf%lf%lf",&s[i].x,&s[i].y,&s[i].z);
            l[i]=dissqr(s[i],O)-sqr(r);
        }
        for (i=0;i<m;i++){
            scanf("%lf%lf%lf",&tmp.x,&tmp.y,&tmp.z);
            for (j=0;j<k;j++)
                if (dcmp(l[j]-dissqr(tmp,s[j])>=0)){
                    sum++;break;
                }
        }
        printf("%d\n",sum);
    }



    return 0;
}

int main(){
    input();
    return 0;
}
