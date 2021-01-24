/*
ID: ck891191
PROG: fence4
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
const double eps=1e-11;
const double pi	= acos(-1.0);
const double INF=1e10;
struct CPoint{int x,y;};
struct Edge{CPoint p1,p2;double r1,r2;int num;};
int dcmp(double x){if (x<-eps) return -1;else return (x>eps);}
//cross product
int cross(CPoint p0, CPoint p1, CPoint p2){
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}

int	PointsBetweenLine(CPoint p1, CPoint p2, CPoint p3, CPoint p4){//line:p1-p2,points:p3,p4;
    int u=cross(p1,p2,p3),v=cross(p1,p2,p4);
    if (u*v<0) return 1;
    else return 0;
}

int	SegmentIntersection(CPoint p1,CPoint p2,CPoint p3,CPoint p4){
    int u,v;
    u=PointsBetweenLine(p1,p2,p3,p4);
    v=PointsBetweenLine(p3,p4,p1,p2);
    if (u==1&&v==1) return 1;
    else return 0;
}

double _arctan(int x,int y){
    double res;
    if (x==0){
        if (y>0) res=pi/2;
        if (y==0) res=0;
        if (y<0) res=-pi/2;
    }
    if (x>0) res=atan(1.0*y/x);
    if (x<0) res=pi+atan(1.0*y/x);
    if (dcmp(res)<0) res+=2*pi;
    return res;
}

int N;
CPoint s;
CPoint points[200];
Edge edges[200];
int res[200],res_sum;
double left1,right1;

int cmp1(const Edge &a,const Edge &b){
    if (dcmp(a.r1-b.r1)<=0) return 1;
    else return 0;
}

int cmp2(const int &a,const int &b){
    int i,j,ii,jj;
    i=min(edges[a].num,(edges[a].num+1)%N);
    ii=max(edges[a].num,(edges[a].num+1)%N);
    j=min(edges[b].num,(edges[b].num+1)%N);
    jj=max(edges[b].num,(edges[b].num+1)%N);
    if (ii<jj) return 1;
    else if (ii>jj) return 0;
    else return i<j;
}

int input(){
    int i;
    CPoint zero;
    freopen("fence4.in","r",stdin);
    freopen("fence4.out","w",stdout);
    scanf("%d",&N);
    scanf("%d%d",&s.x,&s.y);
    for (i=0;i<N;i++)
        scanf("%d%d",&points[i].x,&points[i].y);
    zero.x=zero.y=0;
    for (i=0;i<N;i++){
        edges[i].num=i;
        edges[i].p1.x=points[i].x-s.x;
        edges[i].p1.y=points[i].y-s.y;
        edges[i].p2.x=points[(i+1)%N].x-s.x;
        edges[i].p2.y=points[(i+1)%N].y-s.y;
        edges[i].r1=_arctan(edges[i].p1.x,edges[i].p1.y);
        edges[i].r2=_arctan(edges[i].p2.x,edges[i].p2.y);
        if (cross(zero,edges[i].p1,edges[i].p2)<0){
            CPoint t;
            t=edges[i].p1;
            edges[i].p1=edges[i].p2;
            edges[i].p2=t;
            double tmp=edges[i].r1;
            edges[i].r1=edges[i].r2;
            edges[i].r2=tmp;
        }
        if (dcmp(edges[i].r1-2*pi)==0) edges[i].r1=0;
        if (dcmp(edges[i].r2)==0) edges[i].r2=2*pi;
        if (dcmp(edges[i].r2-edges[i].r1-2*pi)==0) edges[i].r2=0;
    }
    return 0;
}

double dis(double r,int i){
    int dx,dy;
    double kk,bb,k;
    k=tan(r);
    dx=edges[i].p1.x-edges[i].p2.x;
    dy=edges[i].p1.y-edges[i].p2.y;
    if (dx==0) return sqrt(edges[i].p1.x*edges[i].p1.x*(1+k*k));
    kk=1.0*dy/dx;
    bb=edges[i].p1.y-kk*edges[i].p1.x;
    return sqrt(bb*bb*(1+k*k)/((k-kk)*(k-kk)));
}


int cut(int i,int j,double l,double r){
    double mid=(l+r)/2;
    if (dcmp(r-l)<=0) return 0;
    if (dcmp(mid-pi/2)==0||dcmp(mid-3*pi/2)==0)
        mid=(mid+r)/2;
    if (dcmp(dis(mid,i)-dis(mid,j))>=0){
        if (l==left1) left1=r;
        if (r==right1) right1=l;
    }
    return 0;
}

int check(int i){
    int j;
    double l,r;
    left1=edges[i].r1;
    right1=edges[i].r2;
    if (dcmp(left1-right1)==0) return 0;
    if (dcmp(left1-right1)>0) right1+=2*pi;
   // if (dcmp(left1-right1)>0) right1+=2*pi;
    for (j=0;j<N;j++)
        if (i!=j){
            l=max(left1,edges[j].r1);
            r=min(right1,edges[j].r2);
            if (dcmp(l-r)>=0) continue;
            cut(i,j,l,r);
            cut(i,j,l,r+2*pi);
            if (dcmp(left1-right1)>=0) return 0;
        }
    return 1;
}

int solve(){
    int i,j;
    res_sum=0;
    for (i=0;i<N;i++)
        for (j=0;j<i;j++){
            if (SegmentIntersection(edges[i].p1,edges[i].p2,edges[j].p1,edges[j].p2)==1){
                printf("NOFENCE\n");
                return 0;
            }
        }
    sort(edges,edges+N,cmp1);
    for (i=0;i<N;i++)
        if(check(i)){
            res[res_sum]=i;
            res_sum++;
        }
    sort(res,res+res_sum,cmp2);
    printf("%d\n",res_sum);
    for (i=0;i<res_sum;i++){
        int m1,m2,t;
        m1=edges[res[i]].num;
        m2=(edges[res[i]].num+1)%N;
        if (m1>m2){
            t=m1;
            m1=m2;
            m2=t;
        }
        printf("%d %d %d %d\n",points[m1].x,points[m1].y,points[m2].x,points[m2].y);
    }

    return 0;
}


int main(){
    input();
    solve();
    return 0;
}
