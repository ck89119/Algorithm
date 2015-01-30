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
#include <cmath>
#include <cstring>
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

int n,m,t;
int visited[10][10];
int sx,sy,fx,fy;
int input(){
    string s;
    CL(visited,0);
    FR(i,0,n){
        cin>>s;
        FR(j,0,m)
            if (s[j]=='X') visited[i][j]=2;
            else if (s[j]=='S'){sx=i;sy=j;}
            else if (s[j]=='D'){fx=i;fy=j;}
    }
    return 0;
}

int inMaze(int x,int y){
    if (x>=0&&x<n&&y>=0&&y<m) return 1;
    else return 0;
}

int dfs(int x,int y,int left){
    int ans;
    ans=0;
    if (x==fx&&y==fy&&left==0) return 1;
    FR(k,0,4)
        if (inMaze(x+dx[k],y+dy[k])&&!visited[x+dx[k]][y+dy[k]]){
            visited[x+dx[k]][y+dy[k]]=1;
            ans=dfs(x+dx[k],y+dy[k],left-1);
            visited[x+dx[k]][y+dy[k]]=0;
            if (ans) return ans;
        }
    return ans;
}

int solve(){
    visited[sx][sy]=1;
    if ((abs(fx-sx)+abs(fy-sy))%2!=t%2) cout<<"NO\n";
    else if (dfs(sx,sy,t)) cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
}

int main(){
    while (scanf("%d%d%d",&n,&m,&t),n+m+t){
        input();
        solve();
    }
    return 0;
}
