/*
ID: ck891191
PROG: fence6
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define dump(x) cerr<<__LINE__<<"  "<<#x<<"  :  "<<(x)<<endl;
#define two(X) (1<<(X))
#define towL(X) (((int64)(1))<<(x))
#define contain(S,X) ((S&two(X))>0)
#define containL(S,X) ((S&twoL(X))>0)
#define FR(i,a,b) for(int i=(a);i<(b);++i)//[a,b)
#define FOR(i,n) FR(i,0,n)//[0,n)
#define RF(i,a,b) for(int i=(a)-1;i>=(b);--i)//(a,b]
#define ROF(i,n) RF(i,n,0)//[0,n)
#define CL(a,x) memset(a,x,sizeof(a))

const int INF=99999999;
const double PI=acos(-1.0);
const double EPS=1e-11;

struct Edge{
    int w;
    int pre[105];
    int next[105];
};

int visited[105];
int res;
int n;
int st;
Edge edge[105];
//int dis[105][105];

int input(){
    int s;
    int i,j;
    freopen("fence6.in","r",stdin);
    freopen("fence6.out","w",stdout);
    scanf("%d",&n);
    for (i=0;i<n;i++){
        scanf("%d",&s);
        scanf("%d%d%d",&edge[s].w,&edge[s].pre[0],&edge[s].next[0]);
        for (j=1;j<=edge[s].pre[0];j++)
            scanf("%d",&edge[s].pre[j]);
        for (j=1;j<=edge[s].next[0];j++)
            scanf("%d",&edge[s].next[j]);
    }
//    for (i=1;i<=n;i++)
//        for (j=1;j<=n;j++)
//            if (map[i][j]) dis[i][j]=len[i]+len[j];
//            else dis[i][j]=INF;
    return 0;
}

int inArr(int x,int arr[105]){
    int i;
    for (i=1;i<=arr[0];i++)
        if (x==arr[i]) break;
    if (i<=arr[0]) return 1;
    else return 0;
}

int dfs(int e,int pre,int sum){
    int i,k;
    if (!inArr(pre,edge[e].pre)){
        for (i=1;i<=edge[e].pre[0];i++){
            k=edge[e].pre[i];
            if (k==st){
                res=min(res,sum);
                return 0;
            }
            if (!visited[k]){
                visited[k]=1;
                dfs(k,e,sum+edge[k].w);
                visited[k]=0;
            }
        }
    }
    if (!inArr(pre,edge[e].next)){
        for (i=1;i<=edge[e].next[0];i++){
            k=edge[e].next[i];
            if (k==st){
                res=min(res,sum);
                return 0;
            }
            if (!visited[k]){
                visited[k]=1;
                dfs(k,e,sum+edge[k].w);
                visited[k]=0;
            }
        }
    }
    return 0;
}
//int relax(int &a,int b){
//    if (b<a) a=b;
//    return 0;
//}
//
//int min_cir(){
//    int i,j,k;
//    for (k=1;k<=n;k++){
//        for (i=1;i<=n;i++)
//            for (j=1;j<=n;j++)
//                if (i!=j&&dis[i][j]!=INF&&dis[i][k]!=INF&&dis[k][j]!=INF)
//                    relax(res,dis[i][j]+dis[i][k]+dis[k][j]-dis[i][i]-dis[j][j]-dis[k][k]);
//        for (i=1;i<=n;i++)
//            for (j=1;j<=n;j++)
//                relax(dis[i][j],dis[i][k]+dis[k][j]-dis[k][k]);
//    }
//    return 0;
//}

int solve(){
    int i;
    res=INF;
    for (i=1;i<=n;i++){
        memset(visited,0,sizeof(visited));
        visited[i]=1;
        st=i;
        dfs(i,-1,edge[i].w);
    }
    return 0;
}

int output(){
    printf("%d\n",res);
    return 0;
}

int main(){
    input();
    solve();
    output();
    return 0;
}
