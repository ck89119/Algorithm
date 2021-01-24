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
const int dx[8]={-1,-1,-1,0,1,1,1,0};
const int dy[8]={-1,0,1,1,1,0,-1,-1};
int m,n;
int grid[105][105],oil[105][105];
int k;

int inBoard(int x,int y){
    if (x>=0&&x<m&&y>=0&&y<n) return 1;
    else return 0;
}

int dfs(int x,int y){
    FR(i,0,8){
        int xx=x+dx[i];
        int yy=y+dy[i];
        if (inBoard(xx,yy)&&grid[xx][yy]&&!oil[xx][yy]){
            oil[xx][yy]=k;
            dfs(xx,yy);
        }
    }
    return 0;
}

int main(){
    string s;
    while (scanf("%d%d",&m,&n),m){
        CL(grid,0);
        FR(i,0,m){
            cin>>s;
            FR(j,0,n)
                if (s[j]=='@') grid[i][j]=1;
        }
        CL(oil,0);k=0;
        FR(i,0,m)FR(j,0,n)
            if (grid[i][j]&&!oil[i][j]){
                k++;
                oil[i][j]=k;
                dfs(i,j);
            }
        cout<<k<<endl;
    }
    return 0;
}
