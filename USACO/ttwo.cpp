/*
ID: ck891191
PROG: ttwo
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char mapp[12][12];
int fx,fy,cx,cy,visited[12][12][12][12][4][4],df,dc,steps;
int dir[4][2]={-1,0,0,1,1,0,0,-1};

int init(){
    int i,j;
    freopen("ttwo.in","r",stdin);
    freopen("ttwo.out","w",stdout);
    for (i=0;i<10;i++)
        scanf("%s",mapp[i]);
    for (i=0;i<10;i++)
        for (j=0;j<10;j++)
            if (mapp[i][j]=='F'){
                fx=i;fy=j;
            }
            else if (mapp[i][j]=='C'){
                cx=i;cy=j;
            }
    memset(visited,0,sizeof(visited));
    df=0;dc=0;steps=0;
    return 0;
}

int meet(){
    if (fx==cx&&fy==cy) return 1;
    else return 0;
}

int mv(int x,int y,int k){
    if (x+dir[k][0]>=0&&x+dir[k][0]<10
        &&y+dir[k][1]>=0&&y+dir[k][1]<10
        &&mapp[x+dir[k][0]][y+dir[k][1]]!='*')
            return 1;
    else return 0;
}

int solve(){
    visited[fx][fy][cx][cy][df][dc]=1;
    while (!meet()){
        if (mv(fx,fy,df)){
            fx+=dir[df][0];
            fy+=dir[df][1];
        }
        else df=(df+1)%4;;
        if (mv(cx,cy,dc)){
            cx+=dir[dc][0];
            cy+=dir[dc][1];
        }
        else dc=(dc+1)%4;

        if (visited[fx][fy][cx][cy][df][dc]){
            steps=0;
            break;
        }
        visited[fx][fy][cx][cy][df][dc]=1;
        steps++;
    }
    return 0;
}

int print(){
    printf("%d\n",steps);
}

int main(){
    init();
    solve();
    print();
    return 0;
}
