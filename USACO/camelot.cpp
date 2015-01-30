/*
ID: ck891191
PROG: camelot
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
#define dump(x) cerr<<__LINE__<<"  "<<#x<<"  :  "<<(x)<<endl;

const int INF=99999999;
const int move[8][2]={{-1,-2},{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2}};
struct POSITION{
    int x,y;
};

int R,C;
POSITION pos[800];
int pos_size;
int dis[31][27][31][27];

int inBoard(int x,int y){
    if (x>=0&&x<R&&y>=0&&y<C) return 1;
    else return 0;
}

int input(){
    char ch[3200];
    int i;
    freopen("camelot.in","r",stdin);
    freopen("camelot.out","w",stdout);
    scanf("%d%d",&R,&C);getchar();
    pos_size=0;
    while (gets(ch)){
        for (i=0;i<strlen(ch);i++){
            if (ch[i]>'Z'||ch[i]<'A') continue;
            else{
                int x,y;
                x=ch[i]-'A'+1;//dump(ch[i]);
                while (i<strlen(ch)&&(ch[i]>'9'||ch[i]<'0')) i++;
                y=0;
                while (i<strlen(ch)&&ch[i]<='9'&&ch[i]>='0'){
                    y=y*10+ch[i]-'0';//dump(ch[i]);
                    i++;
                }
                //dump(ch);
                //dump(x);dump(y);dump(pos_size);
                pos[pos_size].x=y-1;
                pos[pos_size].y=x-1;
                pos_size++;
            }
        }
    }
   // dump(pos_size);
    return 0;
}

int bfs(int src_x,int src_y){
    queue<POSITION> q;
    POSITION tmp;
    int i;
    int visited[31][27];
    memset(visited,0,sizeof(visited));
    tmp.x=src_x;tmp.y=src_y;
    q.push(tmp);
    dis[src_x][src_y][src_x][src_y]=0;
    visited[src_x][src_y]=1;
    while (!q.empty()){
        POSITION head;
        head=q.front();
        q.pop();
        for (i=0;i<8;i++)
            if (inBoard(head.x+move[i][0],head.y+move[i][1])&&
                !visited[head.x+move[i][0]][head.y+move[i][1]]){
                    dis[src_x][src_y][head.x+move[i][0]][head.y+move[i][1]]=dis[src_x][src_y][head.x][head.y]+1;
                    visited[head.x+move[i][0]][head.y+move[i][1]]=1;
                    tmp.x=head.x+move[i][0];
                    tmp.y=head.y+move[i][1];
                    q.push(tmp);
            }
    }
    return 0;
}

int solve(){
    int i,j,ii,jj,kn,t,x,y,res,sum1,sum2,p;
    for (i=0;i<R;i++)
        for (j=0;j<C;j++)
            for (ii=0;ii<R;ii++)
                for (jj=0;jj<C;jj++)
                    dis[i][j][ii][jj]=INF;
    for (i=0;i<R;i++)
        for (j=0;j<C;j++)
            bfs(i,j);

//    for (i=0;i<R;i++)
//        for (j=0;j<C;j++){
//            for (ii=0;ii<R;ii++)
//                for (jj=0;jj<C;jj++) printf("%d ",dis[i][j][ii][jj]);
//            printf("\n");
//        }

    res=INF;
    for (i=0;i<R;i++)
        for (j=0;j<C;j++){
        sum1=0;
        for (kn=1;kn<pos_size;kn++)
            sum1+=dis[pos[kn].x][pos[kn].y][i][j];
        sum2=sum1+max(abs(pos[0].x-i),abs(pos[0].y-j));
        for (kn=1;kn<pos_size;kn++)
            for (x=-2;x<=2;x++)
                for (y=-2;y<=2;y++){
                    if (!inBoard(pos[0].x+x,pos[0].y+y)) continue;
                    sum2=min(sum2,sum1-dis[pos[kn].x][pos[kn].y][i][j]+dis[pos[kn].x][pos[kn].y][pos[0].x+x][pos[0].y+y]
                             +dis[pos[0].x+x][pos[0].y+y][i][j]+max(abs(x),abs(y)));
                }
        //dump(sum2);
        res=min(res,sum2);
        }
    printf("%d\n",res);
    return 0;
}

int main(){
    input();
    solve();
    return 0;
}
