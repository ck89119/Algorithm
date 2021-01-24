#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int i,j;
    int x[105],d[105],n;
    scanf("%d",&n);
    for (i=0;i<n;i++) scanf("%d %d",&x[i],&d[i]);
    for (i=0;i<n;i++)
       for (j=i+1;j<n;j++)
           if (d[i]+d[j]==0)
           {
                 if (x[i]+d[i]==x[j]) {printf("YES\n");return 0;}
           }
    printf("NO\n");
    return 0;
}
