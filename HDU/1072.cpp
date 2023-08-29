/*
ID: ck891191
PROG:
LANG: C++
*/
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
using namespace std;
#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl;
#define FR(i,a,b) for(int i=(a);i<(b);++i)//[a,b)
#define CL(a,x) memset(a,x,sizeof(a))
#define MP(A,B) make_pair(A,B)
#define two(X) (1<<(X))
#define towL(X) (((int64)(1))<<(x))
#define contain(S,X) ((S&two(X))>0)
#define containL(S,X) ((S&twoL(X))>0)
//freopen("","r",stdin);
//freopen("","w",stdout);
const long long MAXN=(1LL<<62);
const int INF=(1<<30);
const double PI=acos(-1.0);
const double EPS=1e-11;
const int dx[4]={0,-1,0,1};
const int dy[4]={-1,0,1,0};
int t,m,n;
int maze[10][10];
int visited[10][10][7];
int sx,sy;
struct State{
    int x,y;
    int t;
    int bomb;
};
queue<State> q;

int inBoard(int x,int y){
    if (x>=0&&x<n&&y>=0&&y<m) return 1;
    else return 0;
}

int input(){
    scanf("%d%d",&n,&m);
    FR(i,0,n)FR(j,0,m){
        scanf("%d",&maze[i][j]);
        if (maze[i][j]==2) {sx=i;sy=j;}
    }
    return 0;
}

int solve(){
    State s;
    int res=-1;
    CL(visited,0);
    while (!q.empty()) q.pop();
    s.x=sx;s.y=sy;s.t=0;s.bomb=6;
    visited[sx][sy][6]=1;
    q.push(s);
    while (!q.empty()){
        State tmp;
        tmp=q.front();q.pop();
        if (maze[tmp.x][tmp.y]==3) {res=tmp.t;break;}
        if (maze[tmp.x][tmp.y]==4) {tmp.bomb=6;visited[tmp.x][tmp.y][6]=1;}
        FR(k,0,4){
            int xx=tmp.x+dx[k];
            int yy=tmp.y+dy[k];
            if (inBoard(xx,yy)&&maze[xx][yy]&&tmp.bomb>1&&!visited[xx][yy][tmp.bomb-1]){
                visited[xx][yy][tmp.bomb-1]=1;
                s.x=xx;s.y=yy;s.t=tmp.t+1;s.bomb=tmp.bomb-1;
                q.push(s);
            }
        }
    }
    printf("%d\n",res);
    return 0;
}

int main(){
    scanf("%d",&t);
    while (t--){
        input();
        solve();
    }
    return 0;
}
