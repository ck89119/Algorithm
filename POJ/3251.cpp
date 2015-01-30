/*
ID: ck891191
PROG: POJ3251
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
struct point{
    int x,y;
};

int inBoard(int x,int y){
    if (x>=0&&x<n&&y>=0&&y<n) return 1;
    else return 0;
}

int l(int x1,int y1,int x2,int y2){
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

int main(){
    int i,j,board[105][105],cow_size,max_area;
    point cow[10005];
    double tx,ty,dx,dy;
    scanf("%d",&n);getchar();
    cow_size=0;
    for (i=0;i<n;i++){
        char ch;
        for (j=0;j<n;j++) {
            scanf("%c",&ch);
            if (ch=='J') {board[i][j]=1;cow[cow_size].x=i;cow[cow_size].y=j;cow_size++;}
            if (ch=='B') board[i][j]=-1;
            if (ch=='*') board[i][j]=0;
        }
        getchar();
    }
    max_area=0;
    for (i=0;i<cow_size;i++)
        for (j=i+1;j<cow_size;j++){
            if (l(cow[i].x,cow[i].y,cow[j].x,cow[j].y)<=max_area) continue;
            int a,b,c,d;
            tx=(cow[i].x+cow[j].x)/2.0;
            ty=(cow[i].y+cow[j].y)/2.0;
            dx=(cow[i].x-cow[j].x)/2.0;
            dy=(cow[i].y-cow[j].y)/2.0;
            a=(int)(tx-dy);b=(int)(ty+dx);
            if (tx-dy-a==0&&ty+dx-b==0&&inBoard(a,b)&&board[a][b]!=-1){
                    c=(int)(tx+dy);d=(int)(ty-dx);
                    if (tx+dy-c==0&&ty-dx-d==0&&inBoard(c,d)&&board[c][d]!=-1
                        &&board[a][b]+board[c][d]>=1)
                        max_area=l(cow[i].x,cow[i].y,cow[j].x,cow[j].y);
                }

        }

//                if ((cow[i].y-cow[j].y)*(cow[i].y-cow[k].y)+(cow[i].x-cow[j].x)*(cow[i].x-cow[k].x)==0
//                     &&l(cow[i].x,cow[i].y,cow[j].x,cow[j].y)==l(cow[i].x,cow[i].y,cow[k].x,cow[k].y)
//                     &&l(cow[i].x,cow[i].y,cow[j].x,cow[j].y)>max_area){
//                        if (inBoard(-cow[i].x+cow[j].x+cow[k].x,-cow[i].y+cow[j].y+cow[k].y)
//                            &&(board[-cow[i].x+cow[j].x+cow[k].x][-cow[i].y+cow[j].y+cow[k].y]!=-1))
//                            max_area=l(cow[i].x,cow[i].y,cow[j].x,cow[j].y);

    printf("%d\n",max_area/2);
    return 0;
}
