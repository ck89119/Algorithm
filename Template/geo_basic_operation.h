const double eps = 1e−8;
const double pi	= acos(-1.0);
struct CPoint{double x,y;};
struct Edge{CPoint p1,p2;};
double sqr(double x) {return x*x;}
int dcmp(double x) {if (x<-eps) return -1;else return (x>eps);}
//cross product
double cross(CPoint p0, CPoint p1, CPoint p2) {
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}

//dot product
double dot(CPoint p0, CPoint p1, CPoint p2) {
    return (p1.x-p0.x)*(p2.x-p0.x)+(p1.y-p0.y)*(p2.y-p0.y);
}

//distance square
double disSqr(CPoint p1, CPoint p2) {
    return sqr(p1.x-p2.x)+sqr(p1.y-p2.y);
}

//distance
double dis(CPoint p1, CPoint p2) {
    return sqrt(sqr(p1.x-p2.x)+sqr(p1.y-p2.y));
}

int PointEqual(const CPoint &p1, const CPoint &p2) {
    return (dcmp(p1.x−p2.x) == 0) && (dcmp(p1.y−p2.y) == 0);
}

//  Crossing  Angle  of  P0P1 −> P0P2 ,  range  in (−pi , pi ]
double angle(CPoint p0, CPoint p1, CPoint p2) {
    double cr=cross(p0, p1, p2);
    double dt=dot(p0, p1, p2);
    if(dcmp(cr)==0) cr=0.0;
	if(dcmp(dt)==0) dt=0.0;
    return  atan2(cr, dt);
}

int PointOnLine(CPoint p0, CPoint p1, CPoint p2) {
    return dcmp(cross(p0, p1, p2))==0;
}

int PointOnSegment(CPoint p0, CPoint p1, CPoint p2) {
    return PointOnLine(p0, p1, p2) && dcmp(dot(p0, p1, p2))<=0;
}

// 1 =  cross ;	0 = parallel ;	−1 = overlap
int	LineIntersection(CPoint p1, CPoint p2, CPoint p3, CPoint p4, CPoint &cp) {
    double u=cross(p1, p2, p3),v=cross(p2, p1, p4) ;
    if (dcmp(u+v)) {
        cp.x=(p3.x*v+p4.x*u)/(v+u);
        cp.y=(p3.y*v+p4.y*u)/(v+u);
        return 1;
    }
    if (dcmp(u)) return	0;	//  else  u=v=0;
    if (dcmp(cross(p3,p4,p1))) return 0;
    return -1;
}

// 1 =  cross ;	0 = not cross ;	−1 = overlap
int	SegmentIntersection(CPoint p1,CPoint p2,CPoint p3,CPoint p4,CPoint &cp) {
    int ret=LineIntersection(p1,p2,p3,p4,cp);
    if(ret==1)
        return PointOnSegment(cp,p1,p2)&&PointOnSegment(cp,p3,p4);
    if(ret==-1&&(PointOnSegment(p1,p3,p4)||PointOnSegment(p2,p3,p4)
       ||PointOnSegment(p3,p1,p2)||PointOnSegment(p4,p1,p2)))
        return -1;
    return 0;
}

// 1 =  cross ;	0 = not cross ;	−1 = overlap  首选
int	SegmentIntersecTest(CPoint p1,CPoint p2,CPoint p3,CPoint p4) {
    if (max(p1.x,p2.x)+eps<min(p3.x,p4.x)||max(p3.x,p4.x)+eps<min(p1.x,p2.x)||
        max(p1.y,p2.y)+eps<min(p3.y,p4.y)||max(p3.y,p4.y)+eps<min(p1.y,p2.y))
        return	0;
    int d1=dcmp(cross(p3,p4,p2));
    int d2=dcmp(cross(p3,p4,p1));
    int d3=dcmp(cross(p1,p2,p4));
    int d4=dcmp(cross(p1,p2,p3));
    if (d1*d2==1||d3*d4==1) return 0;
    if (d1==0&&d2==0&&d3==0&&d4==0) return -1;
    return 1;
}

 // 0 =  outside ;	1 = inside;	2 = boundary
int PointInPolygon(CPoint cp,CPoint p[],int n) {
    int i,k,d1,d2,wn=0;
    double sum=0;
    p[n]=p[0];
    for(i=0;i<n;i++) {
        if (PointOnSegment(cp,p[i],p[i+1])) return 2;
        k=dcmp(cross(p[i],p[i+1],cp));
        d1=dcmp(p[i+0].y-cp.y);
        d2=dcmp(p[i+1].y-cp.y);
        if(k>0&&d1<=0&&d2>0) wn++;
        if(k<0&&d2<=0&&d1>0) wn--;
    }
    return wn!=0;
}

//p0到p1,p2所在直线的距离,cp为垂足
double PointToLine(CPoint p0,CPoint p1,CPoint p2,CPoint &cp) {
    double d=dis(p1,p2);
    double s=cross(p1,p2,p0)/d;
    cp.x=p0.x+s*(p2.y-p1.y)/d;
    cp.y=p0.y-s*(p2.x-p1.x)/d;
    return s;
}

//cp为垂足
int PointProjLine(CPoint p0,CPoint p1,CPoint p2,CPoint &cp) {
    double t=dot(p1,p2,p0)/dot(p1,p2,p2);
    cp.x=p1.x+t*(p2.x-p1.x);
    cp.y=p1.y+t*(p2.y-p1.y);
    return 0;
}
