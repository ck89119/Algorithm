#include<iostream>
using namespace std;
#define PAU system("pause");
#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl;
int main()
{
    int c,r,x1,x2,y1,y2;
    int cell[110][110],t[110][110];
    int i,j,jj,k;
    freopen("C-small-attempt2.in","r",stdin);
    freopen("C-small-attempt2.out","w",stdout);
    scanf("%d",&c);//dump(c);
    for (i=0;i<c;i++)
    {
        int s=0,step=0;//maxx,maxy;
        scanf("%d",&r);  //dump(r);
        for (j=0;j<110;j++)
          for (k=0;k<110;k++) cell[j][k]=0,t[j][k]=0;
        for (jj=0;jj<r;jj++) {
            scanf("%d%d%d%d",&y1,&x1,&y2,&x2);
        if (x1>x2) swap(x1,x2);
        if (y1>y2) swap(y1,y2);
        //dump(x1);dump(y1);dump(x2);dump(y2);
        for (j=x1;j<=x2;j++)
           for (k=y1;k<=y2;k++) 
           {
               cell[j][k]=1;
               s++;
           }
        }
        while (s)
        {
             /* for (j=0;j<40;j++){
                 for (k=0;k<40;k++) printf("%d",cell[j][k]);
                 cout<<endl;
                 }
                  cout<<endl;*/
              s=0;
              for (j=0;j<110;j++)
                 for (k=0;k<110;k++) t[j][k]=cell[j][k],s+=t[j][k]; 
              for (j=1;j<110;j++)
                 for (k=109;k>0;k--)
                    if (cell[j][k]) 
                    {
                         cell[j][k]=t[j-1][k]||t[j][k-1];
                         s+=cell[j][k];
                         s--;
                    }
                    else
                    {
                         cell[j][k]=t[j-1][k]&&t[j][k-1];
                         s+=cell[j][k];
                    }
              step++;
        }
        printf("Case #%d: %d\n",i+1,step);
        
    }
    //PAU;
    return 0;
}
