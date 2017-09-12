#include <bits/stdc++.h>
using namespace std;

#define dump(x) cout <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0xc0
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define lowbit(x) x & (-x)
typedef long long ll;
typedef pair<int, int> pii;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 100000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
const double eps=1e-10;  

int dcmp(double x)  
{  
    if(fabs(x)<eps) return 0;  
    return x<0?-1:1;  
}  
struct Point  
{  
    double x,y;  
    Point(){}  
    Point(double x,double y):x(x),y(y){}  
    bool operator==(const Point& rhs)const  
    {  
        return dcmp(x-rhs.x)==0 && dcmp(y-rhs.y)==0;  
    }  
    bool operator<(const Point& rhs)const  
    {  
        return dcmp(x-rhs.x)<0 || (dcmp(x-rhs.x)==0 && dcmp(y-rhs.y)<0);  
    }  
};  
typedef Point Vector;  
Vector operator-(Point A,Point B)  
{  
    return Vector(A.x-B.x,A.y-B.y);  
}  
double Cross(Vector A,Vector B)  
{  
    return A.x*B.y-A.y*B.x;  
}  
int ConvexHull(Point *p,int n,Point *ch)//ÇóÍ¹°ü  
{  
    sort(p,p+n);  
    n=unique(p,p+n)-p;  
    int m=0;  
    for(int i=0;i<n;i++)  
    {  
        while(m>1 && Cross(ch[m-1]-ch[m-2], p[i]-ch[m-2])<0) m--;  
        ch[m++]=p[i];  
    }  
    int k=m;  
    for(int i=n-2;i>=0;i--)  
    {  
        while(m>k && Cross(ch[m-1]-ch[m-2], p[i]-ch[m-2])<0) m--;  
        ch[m++]=p[i];  
    }  
    if(n>1) m--;  
    return m;  
}  
  
const int maxn=100000+10;  
Point p[maxn],ch[maxn];  
int main()  
{  
    int T; scanf("%d",&T);  
    while(T--)  
    {  
        int n;  
        scanf("%d",&n);  
        for(int i=0;i<n;i++)  
            scanf("%lf%lf %*c",&p[i].x,&p[i].y);  
        int m=ConvexHull(p,n,ch);  
        printf("%d\n",m);  
        for(int i=0;i<m;i++)  
            printf("%.0lf %.0lf\n",ch[i].x,ch[i].y);  
    }  
    return 0;  
}  
