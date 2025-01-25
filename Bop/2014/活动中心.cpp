#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<iostream>
using namespace std; 
const double eps = 1e-8;
const double Max = 1e10;

const int N = 50005;
struct Point{
    double x, y;     
}p[N];
int n;
int sgn(double x){
 return x<-eps?-1:x>eps; 
}
double Fabs(double x){
 //return x<-eps?-x:x;
 return (sgn(x)<0)?-x: (x>eps?x:0); 
}
double dist( Point a, Point b ){ 
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double func(double x){
    Point a; a.x = x; a.y = 0;
    double res = 0;
    for(int i = 0; i < n; i++){
        double tmp = dist( a, p[i] );
        res += tmp;   
    } 
    return res;
}
int main(){ 
    int t; scanf("%d",&t);
    for(int ncase = 1; ncase <= t; ncase++){
        scanf("%d",&n);
        double l = -1000005., r = 1000005.;
        for(int i = 0; i < n; i++){
            scanf("%lf%lf",&p[i].x,&p[i].y); 
        }     
        double m, tm;
        while( (r-l)>eps ){
            m = (l+r)/2.;
            tm = (m+r)/2.;
            if( func(m) < func(tm) )
                r = tm;
            else l = m;
            //cout << "###: " << l << endl;
            //cout << "###: " << r << endl;
        } 
        //double ans = func(m); 
        printf("Case %d: %.6f\n",ncase, m);
    }    
    return 0;
}
