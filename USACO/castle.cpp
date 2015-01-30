/*
ID: ck891191
PROG: castle
LANG: C++
*/

#include <iostream>
#include <cstdio>
using namespace std;
#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl;
const int dir[4][2]={0,-1,-1,0,0,1,1,0};
int m,n;
int visited[55][55],walls[55][55],r_space[2505];

inline bool linked(int x,int y,int k){
    return !(walls[x][y]&(1<<k));
}

int flood_fill(int x,int y,int c){
    int k;
    visited[x][y]=c;
    for (k=0;k<4;k++)
        if(x+dir[k][0]>=0&&x+dir[k][0]<m&&y+dir[k][1]>=0&&y+dir[k][1]<n
           &&linked(x,y,k)&&!visited[x+dir[k][0]][y+dir[k][1]]){
            flood_fill(x+dir[k][0],y+dir[k][1],c);
        }
    return 0;
}

int init(){
    int i,j;
    freopen("castle.in","r",stdin);
    freopen("castle.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (i=0;i<m;i++)
        for (j=0;j<n;j++){
            scanf("%d",&walls[i][j]);
            visited[i][j]=0;
        }
    return 0;
}

int solve(){
    int i,j,c,max_space,w,x,y;
    c=0;
    for (i=0;i<m;i++)
        for (j=0;j<n;j++)
            if (!visited[i][j]) flood_fill(i,j,++c);

//    for (i=0;i<m;i++){
//        for (j=0;j<n;j++) printf("%.2d",visited[i][j]);
//        cout<<endl;
//    }


    for (i=0;i<m;i++)
        for (j=0;j<n;j++)
            r_space[visited[i][j]]++;
    max_space=r_space[1];
    for (i=1;i<=c;i++)
        if (max_space<r_space[i]) max_space=r_space[i];
    printf("%d\n%d\n",c,max_space);

    max_space=0;
    for (j=0;j<n;j++)
        for (i=m-1;i>=0;i--)
        {
            if (!linked(i,j,1)&&visited[i][j]!=visited[i+dir[1][0]][j+dir[1][1]]
                &&r_space[visited[i][j]]+r_space[visited[i+dir[1][0]][j+dir[1][1]]]>max_space){
                    max_space=r_space[visited[i][j]]+r_space[visited[i+dir[1][0]][j+dir[1][1]]];
                    w=1;x=i;y=j;
                   // dump(max_space);dump(x);dump(y);
            }
            if (!linked(i,j,2)&&visited[i][j]!=visited[i+dir[2][0]][j+dir[2][1]]
                &&r_space[visited[i][j]]+r_space[visited[i+dir[2][0]][j+dir[2][1]]]>max_space){
                    max_space=r_space[visited[i][j]]+r_space[visited[i+dir[2][0]][j+dir[2][1]]];
                    w=2;x=i;y=j;
                  //  dump(max_space);dump(x);dump(y);
            }
        }
    printf("%d\n",max_space);
    printf("%d %d ",x+1,y+1);
    if (w==1) printf("N\n");
    else printf("E\n");

    return 0;
}

int main(){
    init();
    solve();
    return 0;
}
