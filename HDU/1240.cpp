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
const int dx[6]={0,-1,0,1,0,0};
const int dy[6]={-1,0,1,0,0,0};
const int dz[6]={0,0,0,0,-1,1};
int n;
int a,b,c,d,e,f;
int visited[10][10][10];

int inBoard(int x,int y,int z){
    if (x>=0&&x<n&&y>=0&&y<n&&z>=0&&z<n) return 1;
    else return 0;
}

int dfs(int x,int y,int z,int step){
    //dump(x)dump(y)dump(z)
    if (x==d&&y==e&&z==f) return 0;
    //if (step+abs(d-x)+abs(e-y)+abs(f-z)>=res) return 0;
    FR(k,0,6)
        if (inBoard(x+dx[k],y+dy[k],z+dz[k])&&visited[x+dx[k]][y+dy[k]][z+dz[k]]>step+1){
            visited[x+dx[k]][y+dy[k]][z+dz[k]]=step+1;
            dfs(x+dx[k],y+dy[k],z+dz[k],step+1);
        }
    return 0;
}

int main(){
    string s;
    while (cin>>s){
        cin>>n;
        FR(i,0,n)FR(j,0,n)FR(k,0,n) visited[i][j][k]=INF;
        FR(i,0,n)FR(j,0,n){
            cin>>s;
            FR(k,0,n)
                if (s[k]=='X') visited[j][k][i]=-1;
        }
        cin>>a>>b>>c>>d>>e>>f;
        cin>>s;//dump(a)dump(b)dump(c)
        visited[a][b][c]=0;
        dfs(a,b,c,0);
        if (visited[d][e][f]==INF) cout<<"NO ROUTE\n";
        else cout<<n<<' '<<visited[d][e][f]<<endl;
    }
    return 0;
}
