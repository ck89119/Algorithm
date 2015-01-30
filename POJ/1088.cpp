#include <iostream>
#include <cstdio>
using namespace std;

int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
int mat[110][110],c,r;
int ret[110][110]={0};


int dp(int i,int j)
{
    int max=0,k;
    if (ret[i][j]) return ret[i][j]; 
    for (k=0;k<4;k++)
        if (i+dx[k]>=0&&i+dx[k]<r&&j+dy[k]>=0&&j+dy[k]<c&&mat[i][j]<mat[i+dx[k]][j+dy[k]]&&
            dp(i+dx[k],j+dy[k])>max) max=dp(i+dx[k],j+dy[k]);
    return ret[i][j]=max+1;                  
}

int main()
{
    int i,j,ans=0;
    scanf("%d%d",&r,&c);
    for (i=0;i<r;i++)
       for (j=0;j<c;j++)
          scanf("%d",&mat[i][j]);
    for (i=0;i<r;i++)
       for (j=0;j<c;j++)
          dp(i,j);
    
    for (i=0;i<r;i++)
       for (j=0;j<c;j++) 
          if (ans<ret[i][j]) ans=ret[i][j];
    
    printf("%d\n",ans);
    system("pause");
    
    return 0;
}
