/*
ID: ck891191
PROG: maze1
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
int w,h,dir[4][2]={-1,0,0,1,1,0,0,-1},ret,steps[205][80];
char maze[205][80];
FILE *fin=fopen("maze1.in","r");
FILE *fout=fopen("maze1.out","w");
int init(){
    int i,j;
    char c;
    fscanf(fin,"%d%d",&w,&h);
    c=fgetc(fin);
    for (i=0;i<2*h+1;i++)
        fgets(maze[i],2*w+3,fin);
    for (i=0;i<205;i++)
        for (j=0;j<80;j++)
            steps[i][j]=9999999;
    return 0;
}

//int out(int x,int y){
//    int k;
//    for (k=0;k<4;k++)
//        if ((x+dir[k][0]==0||x+dir[k][0]==2*h
//            ||y+dir[k][1]==0||y+dir[k][1]==2*w)
//            &&maze[x+dir[k][0]][y+dir[k][1]]==' ')
//            return 1;
//    return 0;
//}
//
//int dfs(int x,int y){
//    int k;
//    if (out(x,y)){
//        if (steps<mmin) mmin=steps;
//        return 0;
//    }
//    if (steps>=mmin) return 0;
//
//    for (k=0;k<4;k++)
//        if (maze[x+dir[k][0]][y+dir[k][1]]==' '
//            &&!visited[x+dir[k][0]*2][y+dir[k][1]*2]){
//                steps++;
//                visited[x+dir[k][0]*2][y+dir[k][1]*2]=1;
//                dfs(x+dir[k][0]*2,y+dir[k][1]*2);
//                steps--;
//                visited[x+dir[k][0]*2][y+dir[k][1]*2]=0;
//        }
//    return 0;
//}
//
//int solve(){
//    int i,j;
//    ret=0;
//    for (i=0;i<h;i++)
//        for (j=0;j<w;j++){
//            memset(visited,0,sizeof(visited));
//            steps=0;mmin=99999999;
//            visited[2*i+1][2*j+1]=1;
//            dfs(2*i+1,2*j+1);
//            if (mmin>ret) ret=mmin;
//        }
//    return 0;
//}

int search(int x,int y){
    int k;
    for (k=0;k<4;k++)
        if (maze[x+dir[k][0]][y+dir[k][1]]==' '
            &&steps[x][y]+1<steps[x+dir[k][0]*2][y+dir[k][1]*2]){
                steps[x+dir[k][0]*2][y+dir[k][1]*2]=steps[x][y]+1;
                search(x+dir[k][0]*2,y+dir[k][1]*2);
            }
    return 0;
}

int solve(){
    int i;
    for (i=0;i<w;i++)
        if (maze[0][2*i+1]==' '){
            steps[1][2*i+1]=1;
            search(1,2*i+1);
        }
    for (i=0;i<w;i++)
        if (maze[2*h][2*i+1]==' '){
            steps[2*h-1][2*i+1]=1;
            search(2*h-1,2*i+1);
        }
    for (i=0;i<h;i++)
        if (maze[2*i+1][0]==' '){
            steps[2*i+1][1]=1;
            search(2*i+1,1);
        }
    for (i=0;i<h;i++)
        if (maze[2*i+1][2*w]==' '){
            steps[2*i+1][2*w-1]=1;
            search(2*i+1,2*w-1);
        }
    return 0;
}

int print(){
    int i,j;
    ret=0;
    for (i=0;i<h;i++){
        for (j=0;j<w;j++){
            //fprintf(fout,"%d ",steps[2*i+1][2*j+1]);
            if (steps[2*i+1][2*j+1]>ret)
                ret=steps[2*i+1][2*j+1];
        }
       // fprintf(fout,"\n");
    }
    fprintf(fout,"%d\n",ret);
    return 0;
}

int main(){

//    freopen("maze1.in","r",stdin);
//    freopen("maze1.out","w",stdout);
    init();
    solve();
    print();
    return 0;
}
