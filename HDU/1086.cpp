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
const double eps=1e-8;
struct CPoint{double x,y;};
struct Edge{CPoint p1,p2;};
double cross(CPoint p0, CPoint p1, CPoint p2){
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
   // return (p1.x−p0.x)*(p2.y−p0.y)−(p2.x−p0.x)*(p1.y−p0.y);
}

double dot(CPoint p0, CPoint p1, CPoint p2){
    return (p1.x-p0.x)*(p2.x-p0.x)+(p1.y-p0.y)*(p2.y-p0.y);
   // return (p1.x−p0.x)*(p2.x−p0.x)+(p1.y−p0.y)*(p2.y−p0.y) ;
}
int dcmp(double x){if (x<-eps) return -1;else return (x>eps);}
//int dcmp(double x){if (x<−eps) return −1; else return (x>eps);}
int PointEqual(const CPoint &p1, const CPoint &p2){
    return dcmp(p1.x-p2.x)==0&&dcmp(p1.y-p2.y)==0;
    //return dcmp(p1.x−p2.x)==0&&dcmp(p1.y−p2.y)==0;
}
int PointOnSegment(CPoint p0, CPoint p1, CPoint p2){
    return dcmp(cross(p0, p1, p2))==0&&dcmp(dot(p0, p1, p2))<=0;
}
// 1 =  cross ;	0 = parallel ;	−1 = overlap
int	LineIntersection(CPoint p1, CPoint p2, CPoint p3, CPoint p4, CPoint &cp){
    double u=cross(p1, p2, p3),v=cross(p2, p1, p4) ;
    if (dcmp(u+v)){
        cp.x=(p3.x*v+p4.x*u)/(v+u) ;
        cp.y=(p3.y*v+p4.y*u)/(v+u) ;
        return	1;
    }
    if (dcmp(u)) return	0;	//  else  u=v=0;
    if (dcmp(cross(p3,p4,p1))) return 0;
    return -1;
}
int	SegmentIntersection(CPoint p1,CPoint p2,CPoint p3,CPoint p4,CPoint &cp){
    int ret=LineIntersection(p1,p2,p3,p4,cp);
    //dump(ret);dump(cp.x);dump(cp.y);
    if(ret==1)
        return PointOnSegment(cp,p1,p2)&&PointOnSegment(cp,p3,p4);
    if(ret==-1&&(PointOnSegment(p1,p3,p4)||PointOnSegment(p2,p3,p4)
       ||PointOnSegment(p3,p1,p2)||PointOnSegment(p4,p1,p2)))
        return 1;
    return 0;
}

int main(){
    int N;
    Edge e[105];
    int i,j,sum;
    CPoint cp;
    while (scanf("%d",&N),N){
        for(i=0;i<N;i++)
            scanf("%lf%lf%lf%lf",&e[i].p1.x,&e[i].p1.y,&e[i].p2.x,&e[i].p2.y);
        sum=0;
        for (i=0;i<N;i++)
            for (j=i+1;j<N;j++)
                    sum+=SegmentIntersection(e[i].p1,e[i].p2,e[j].p1,e[j].p2,cp);
        printf("%d\n",sum);
    }



    return 0;
}
