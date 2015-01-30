#include <iostream>
#include <cstdio>
using namespace std;

int w[21][21][21];
 
 
int dp()
{
    int i,j,k;
    
    for (i=0;i<=20;i++) 
       for (j=0;j<=20;j++)
       {
           w[i][j][0]=1;
           w[i][0][j]=1;
           w[0][i][j]=1;
       }
    
    for (i=1;i<=20;i++)
       for (j=1;j<=20;j++)
          for (k=1;k<=20;k++)
          {
              if (i<j&&j<k) w[i][j][k]=w[i][j][k-1]+w[i][j-1][k-1]-w[i][j-1][k]; 
              else w[i][j][k]=w[i-1][j][k]+w[i-1][j-1][k]+w[i-1][j][k-1]-w[i-1][j-1][k-1];                          
          }
    
    return 0;
}


int main()
{
    int a,b,c;
    dp();
    while (1)
    {
          scanf("%d%d%d",&a,&b,&c);
          if (a==-1&&b==-1&&c==-1) return 0;
          if (a<=0||b<=0||c<=0) printf("w(%d, %d, %d) = 1\n",a,b,c);
          else 
          {
               if (a>20||b>20||c>20) printf("w(%d, %d, %d) = %d\n",a,b,c,w[20][20][20]);
               else  printf("w(%d, %d, %d) = %d\n",a,b,c,w[a][b][c]);         
          }
    }
    return 0;
}
