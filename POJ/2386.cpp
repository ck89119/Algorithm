#include <vector>
#include <list>
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

char map[105][105];
bool visited[105][105];
int dir[8][2]={-1,-1,-1,0,-1,1,0,-1,0,1,1,-1,1,0,1,1};


int dfs(int i,int j)
{
    int k;
    visited[i][j]=true;
    for (k=0;k<8;k++)
       if (map[i+dir[k][0]][j+dir[k][1]]=='W'&&!visited[i+dir[k][0]][j+dir[k][1]]) 
           dfs(i+dir[k][0],j+dir[k][1]);    
    return 0;
}

int main()
{
    int n,m;
    int i,j,ans=0;
    scanf("%d%d",&n,&m);getchar();
    for (i=0;i<=n+1;i++) {map[i][0]='.';map[i][m+1]='.';}
    for (j=0;j<=m+1;j++) {map[0][j]='.';map[n+1][j]='.';}
    for (i=1;i<=n;i++)
    {
       for (j=1;j<=m;j++) {scanf("%c",&map[i][j]);visited[i][j]=false;}
       getchar(); 
    }
    for (i=1;i<=n;i++)
       for (j=1;j<=m;j++)
           if (map[i][j]=='W'&&!visited[i][j])
           {
               dfs(i,j);
               ans++;
           }
       
    printf("%d\n",ans);PAU
    
    return 0;
}
