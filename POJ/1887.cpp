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

int main()
{
    int dp[10000],h[10000];
    int t=0;
    while (scanf("%d",&h[0]),h[0]!=-1)
    {
          int i,j,sz,ans;
          i=1;
          while (scanf("%d",&h[i]),h[i]!=-1) i++;
          sz=i;
          for (i=0;i<sz;i++) dp[i]=1;
          for (i=0;i<sz;i++)
             for (j=0;j<i;j++)
                if (h[j]>=h[i]) dp[i]=max(dp[j]+1,dp[i]);
          ans=0;
          //for (i=0;i<sz;i++) printf("%d ",dp[i]);
          for (i=0;i<sz;i++) if (dp[i]>ans) ans=dp[i];
          if (t) printf("\n");
          printf("Test #%d:\n",++t);
          printf("  maximum possible interceptions: %d\n",ans);               
    } 
    
    return 0;
}
