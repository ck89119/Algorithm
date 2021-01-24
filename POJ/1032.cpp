#include<iostream>
using namespace std;
#define PAU system("pause");
int main()
{
    int n,ans[50];
    int i,s,left;
    scanf("%d",&n);
    left=n;
    for (i=2;left>=i;i++)
    {
        ans[i-2]=i;
        left-=i;
    }
    i=i-1;s=i;
    while (i>=2&&left>0) {ans[i-2]++;i--;left--;}
    if (left) ans[s-2]++;
    for (i=0;i<s-2;i++) printf("%d ",ans[i]);
    printf("%d\n",ans[s-2]);//PAU;
    return 0;
}
