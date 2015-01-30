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

int n,a,b,c;
/*
int dfs(int left,int la,int lb,int lc)
{
    int i,j,k;
    if (left==0) {dp[left][la][lb][lc]++;return dp[left][la][lb][lc];}
    for (i=0;i<=min(lc,left/4);i++) 
      for (j=0;j<=min(lb,(left-4*i)/2);j++)
        for (k=0;k<=min(la,left-4*i-2*j);k++)
            if (dp[left][la][lb][lc]>0) return dp[left][la][lb][lc];
            else return dp[left][la][lb][lc]=dfs(left-4*i-2*j-k,la-k,lb-j,lc-i);
}*/


int main()
{   
    int i,j,k;
    int ans=0;
    scanf("%d%d%d%d",&n,&a,&b,&c);
    for (k=0;k<=c;k++)
      for (j=0;j<=b;j++)
      {
          i=2*n-4*k-2*j;
          if (i>=0&&i<=a) ans++;
      }
      
      
      
    //memset(dp,0,sizeof(dp));
    //dfs(2*n,a,b,c);
    printf("%d\n",ans);//PAU
    return 0;
}
