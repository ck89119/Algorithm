#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=1000;
int nx,ny,matchx[maxn],matchy[maxn],g[maxn][maxn],visity[maxn];

int input(){
    int i,j;
    freopen("test.in","r",stdin);
    scanf("%d %d",&nx,&ny);
    for (i=1;i<=nx;i++)
        for (j=1;j<=ny;j++)
            scanf("%d",&g[i][j]);
    return 0;
}

int crosspath(int x){
    int y;
    for (y=1;y<=ny;y++){
        if (g[x][y]&&!visity[y]){
            visity[y]=1;
            if (!matchy[y]||crosspath(matchy[y])){
                matchy[y]=x;matchx[x]=y;
                return 1;
            }
        }
    }
    return 0;
}

int hungary(){
    int i,cnt;
    cnt=0;
    memset(matchx,0,sizeof(matchx));
    memset(matchy,0,sizeof(matchy));
    for (i=1;i<=nx;i++)
        if (!matchx[i]){
            memset(visity,0,sizeof(visity));
            cnt+=crosspath(i);
        }
    return cnt;
}

int output(){
    freopen("test.out","w",stdout);
    printf("%d\n",hungary());
    return 0;
}

int main(){
    input();
    output();
    return 0;
}
