/*
ID: ck891191
PROG: checker
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define dump(x) cout <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl;
int n,total,path[15];
int ch[15];
int init()
{
    freopen("checker.in","r",stdin);
    freopen("checker.out","w",stdout);
    scanf("%d",&n);
    memset(ch,0,sizeof(ch));
    total=0;
    return 0;
}

int dfs(int level)
{
    int i,j,flag;
    int t;
    if (level==n){
        total++;
       // if (total<=3){
            for (i=0;i<n-1;i++) printf("%d ",path[i]+1);
            printf("%d\n",path[n-1]+1);
      // }
    }
    if (n!=6&&level==0&&n%2==0) t=n/2;
    else t=n;
    for (i=0;i<t;i++){
        if (!ch[i]){
            flag=true;
            for (j=0;j<level;j++)
                if ((path[j]-j)==(i-level)||(path[j]+j)==(i+level)) {
                    flag=false;
                    break;
                }
            if (flag) {
                ch[i]=1;
                path[level]=i;
                //dump(level);
                //for (j=0;j<=level;j++) printf("%d ",path[j]);cout<<endl;
                dfs(level+1);
                ch[i]=0;
            }
        }
    }
    return 0;
}

int solve()
{
    int i,j,k;
    dfs(0);
    if (n!=6&&n%2==0) total*=2;
    printf("%d\n",total);
    return 0;
}

int main()
{
    init();
    solve();
    return 0;
}
