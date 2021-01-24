/*#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl;

int _ret[3],_dem[3],_ans;
int _n;

int dfs(int left,int k)
{
    int ans,i;
    if (k==2) 
    {
         ans=2*(_dem[0]*_dem[1]+_dem[1]*left+_dem[0]*left);
         if (ans<_ans)
         {
              _ans=ans;
              _ret[0]=_dem[0];
              _ret[2]=left;
              _ret[1]=_dem[1];
         }
    }
    else 
    {
         int tmp=(int)(exp(1.0/3*log(_n))+0.5); //dump(tmp);
         if (k==0) {for (i=1;i<=tmp;i++) 
             if (left%i==0)
             {
                  _dem[k++]=i;//dump(_dem[0]);dump(k);
                  left/=i;
                  dfs(left,k);
                  left*=i;
                  k--;
             }}
         else {for (i=_dem[k-1];i<=_n;i++) 
             if (left%i==0)
             {
                  _dem[k++]=i;//dump(_dem[k-1]);
                  left/=i;
                  dfs(left,k);
                  left*=i;
                  k--;       
             }  }                             
    }
    return 0;
}

int main()
{
    while (scanf("%d",&_n)!=EOF)
    {
          _ans=1<<30;
          dfs(_n,0);
          printf("%d %d %d\n",_ret[0],_ret[1],_ret[2]);
    }
    return 0;
}*/


#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl;

int main()
{
    int n,ret,d1,d2,d3;
    int i,j,k,t1,t2,tn,tnn;
    while (scanf("%d",&n)!=EOF)
    {
    t1=(int)(exp(1.0/3*log(n))+0.5);
    ret=1<<30;
    for (i=1;i<=t1;i++)
    {   
        tn=n;
        if (tn%i==0)
        {
             tn/=i; 
             t2=(int)(sqrt(tn)+0.5);
             for (j=i;j<=t2;j++)
                 if (tn%j==0)
                 {
                     tnn=tn/j;
                     if (ret>2*(i*j+i*tnn+j*tnn))
                     {
                          ret=2*(i*j+i*tnn+j*tnn);
                          d1=i;d2=j;d3=tnn;
                     }
                 }
        }
    }
    printf("%d %d %d\n",d1,d2,d3);
    
    
    }
    return 0;
}
