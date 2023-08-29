#include<iostream>
using namespace std;
int a[600],b[600],c[600],way[600][600];
int f[600][600];
int n,m,mi,mj,mm;



int doit()
{
    int i,j,k,max;
    for (i=0;i<=n;i++)
      for (j=0;j<=m;j++) {
          f[i][j]=0;
          way[i][j]=0;
          }
    mm=0;mi=0;mj=0;
    for (i=1;i<=n;i++)
      for (j=1;j<=m;j++)
      {
          f[i][j]=f[i-1][j];
          way[i][j]=way[i-1][j];
          if (a[i]==b[j])
          {
              max=0;
              for (k=1;k<j;k++) 
              if (b[k]<b[j]&&f[i][k]>f[i][max]) max=k; 
              if (f[i][j]<f[i][max]+1){
                   f[i][j]=f[i][max]+1;                   
                   if (max==0) way[i][j]=0;
                   else way[i][j]=i*n+max;
                   } 
              if (f[i][j]>mm) 
              {
                 mm=f[i][j];
                 mi=i;mj=j;     
              }
          }         
      } 
     cout<<mm<<endl;
     return 0;
}

int print(int i,int j)
{
    cout << i << " " << j << endl;
    if (way[i][j]>0) 
    {
       //cout<<way[i][j]/n<<way[i][j]%n<<endl;
       //cout<<way[1][2]<<endl;
       print(way[i][j]/n,way[i][j]%n);
       printf(" %d",b[j]);
    }
    else  printf("%d",b[j]);  
    return 0;
}

int init()
{     
    int i;
    scanf("%d",&n);  
    for (i=1;i<=n;i++) scanf("%d",&a[i]); 
    scanf("%d",&m);
    for (i=1;i<=m;i++) scanf("%d",&b[i]); 
    doit();
    if (mm>0){
       print(mi,mj);  
    }   
    printf("\n");
    return 0;
}

int main()
{
    init();
  
    //system("pause");
    return 0;
}
