/*#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl;
struct zb
{
    int x,y;
};

bool cmp(const zb& a,const zb& b)
{
    return a.x<b.x;
}

int main()
{
    int n,d;
    int i,cases=0;
    vector<zb> island;
    
    while (scanf("%d%d",&n,&d),n!=0)
    {
          double min;
          int total=0;
          for (i=0;i<n;i++) 
          {
              zb t;
              scanf("%d%d",&t.x,&t.y);
              if (t.y>d) return -1;
              island.push_back(t);
          }
          sort(island.begin(),island.end(),cmp);
          min=(double)island[0].x+sqrt(d*d-(double)island[0].y*island[0].y);dump(min);
          total++;
          for (i=1;i<n;i++)
          {
              double tmp;
              tmp=(double)island[i].x-sqrt(d*d-(double)island[i].y*island[i].y);
              if (tmp<min) continue;
              else 
              {
                   total++;
                   tmp=(double)island[i].x+sqrt(d*d-(double)island[i].y*island[i].y);
                   min=tmp;
              } 
          }
          printf("Case %d: %d\n",++cases,total);
    }
    return 0;
}*/




#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl;
struct pos
{
    int x,y;
    double l,r;
};

int cmp(const pos& a,const pos& b)
{
    return a.l<b.l;
}

int main()
{
    int n,d,cases=1;        
    while (scanf("%d%d",&n,&d),n||d)
    {
          pos tmp;
          bool f=true;
          vector<pos> xy;
          double right;
          int i,ret;   
          for (i=0;i<n;i++) {
              scanf("%d%d",&tmp.x,&tmp.y);
              if (d>=tmp.y&&d>0)
              {
                 tmp.l=tmp.x-sqrt(d*d-tmp.y*tmp.y);//dump(tmp.l);
                 tmp.r=tmp.x+sqrt(d*d-tmp.y*tmp.y);//dump(tmp.r);   
                 xy.push_back(tmp);
              }
              else 
              {                
                 f=false;
              }
          }
          if (!f) { printf("Case %d: -1\n",cases++);continue;}
         
          sort(xy.begin(),xy.end(),cmp);
          ret=1;right=xy[0].r;
          
          for (i=1;i<xy.size();i++)
              if (xy[i].l>right) 
              {
                   ret++;
                   right=xy[i].r;
              }
              else if (xy[i].r<right) 
                      right=xy[i].r;
          printf("Case %d: %d\n",cases++,ret);    
                           
    }
    
    return 0;  
}
