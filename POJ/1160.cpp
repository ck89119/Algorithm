#include <iostream>
#include <cstdio>
using namespace std;


#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl;
#define PAU system("pause");
int main()
{
    int dp[35][305],cost[305][305],a[305];
    int p,v;
    int i,j,k;
    scanf("%d%d",&v,&p);
    for (i=1;i<=v;i++)
    {
        scanf("%d",&a[i]);
    }
    for (i=0;i<=v;i++)
       for (j=0;j<=v;j++) 
           cost[i][j]=0;
    for (i=1;i<v;i++)
      for (j=i+1;j<=v;j++)
      {
          int mid=(i+j)>>1;
          for (k=mid;k<=j;k++) cost[i][j]+=a[k]-a[mid];
          for (k=i;k<mid;k++) cost[i][j]+=a[mid]-a[k];
      }   
                       
    for (i=0;i<=p;i++)
       for (j=0;j<=v;j++)
           dp[i][j]=1<<30;
    for (i=0;i<=v;i++) dp[1][i]=cost[1][i];
    for (i=0;i<=p;i++) dp[i][1]=0;
    
    
    for (i=2;i<=p;i++)
       for (j=1;j<=v;j++)
          for (k=i-1;k<j;k++)
              if (dp[i][j]>dp[i-1][k]+cost[k+1][j]) dp[i][j]=dp[i-1][k]+cost[k+1][j];
          
    printf("%d\n",dp[p][v]);   
    
  //  system("pause");
    return 0;
}
