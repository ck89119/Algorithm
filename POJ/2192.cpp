#include <iostream>
#include <string>
using namespace std;
int main()
{
    int t,k;
    string a,b,s;
    scanf("%d",&t);
    for (k=0;k<t;k++)
    {
        bool dp[205][205];
        int i,j;
        cin>>a>>b>>s;
        for (i=0;i<=a.size();i++)
           for (j=0;j<=b.size();j++)
              dp[i][j]=false;
        dp[0][0]=true;
        for (i=0;i<=a.size();i++)
           for (j=0;j<=b.size();j++)
           {
               if (j-1>=0&&dp[i][j-1]&&s[i+j-1]==b[j-1]) dp[i][j]=true;
               if (i-1>=0&&dp[i-1][j]&&s[i+j-1]==a[i-1]) dp[i][j]=true;
           }
        if (dp[a.size()][b.size()])  printf("Data set %d: yes\n",k+1);
        else printf("Data set %d: no\n",k+1);
    }
    return 0;
}
