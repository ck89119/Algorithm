#include<iostream>
using namespace std;
int main()
{
    int R,k,N,g[1010],next[1010],t[1010],cas;
    __int64 sum;
    freopen("C-large.in","r",stdin);
    freopen("C-large.out","w",stdout);
    scanf("%d",&cas);
    for (int c=0;c<cas;c++)
    {
        scanf("%d%d%d",&R,&k,&N);
        for (int i=0;i<N;i++) scanf("%d",&g[i]);
        for (int i=0;i<N;i++)
        {
            int total=0,j=i;
            while (total+g[j]<=k) {total+=g[j];j=(j+1)%N;if (j==i) break;}
            t[i]=total;next[i]=j;
        }
        int i=0;
        sum=0;
        for (int r=0;r<R;r++) 
        {
            sum+=t[i];
            i=next[i];            
        }
        printf("Case #%d: %I64d\n",c+1,sum);
    }
    return 0;
}
