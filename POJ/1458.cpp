#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <string>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl;
#define PAU system("pause");

int dp[300][300];
int main()
{
    
    string a,b;
    int i,j,ans;
    while (cin>>a>>b)
    {
          for (i=0;i<=a.size();i++)
             for (j=0;j<=b.size();j++) dp[i][j]=0;
          for (i=0;i<a.size();i++)
             for (j=0;j<b.size();j++)
             {
                 if (a[i]==b[j]) dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j])+1;
                 else dp[i+1][j+1]=max(dp[i+1][j],dp[i][j+1]);
             }
         // for (i=0;i<=a.size();i++){
         //    for (j=0;j<=b.size();j++) printf("%d ",dp[i][j]);
         //    cout<<endl;}
          ans=0;
          for (i=1;i<=a.size();i++)
             for (j=1;j<=b.size();j++) 
                if (dp[i][j]>ans) ans=dp[i][j];
          printf("%d\n",ans);
          
          
    }
    
    
    
    return 0;
}
