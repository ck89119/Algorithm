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
int m,n;
int t[205][205];
int ax,ay,fx,fy;

struct XY{
    int x,y;
    int t;
};

int inBoard(int x,int y){
    if (x>=0&&x<n&&y>=0&&y<m) return 1;
    else return 0;
}

int main(){
    while (scanf("%d%d",&n,&m)!=EOF){
        vector<string> s;
        FR(i,0,n){
            string tmp;
            cin>>tmp;
            s.push_back(tmp);
            FR(j,0,m)
                if (s[i][j]=='a') {ax=i;ay=j;}
                else if (s[i][j]=='r') {fx=i;fy=j;}
        }
        FR(i,0,n)FR(j,0,m) t[i][j]=INF;
        XY a;
        a.x=ax;a.y=ay;a.t=0;
        t[ax][ay]=0;
        queue<XY> q;
        q.push(a);
        while (!q.empty()){
            XY tmp;
            tmp=q.front();q.pop();
            if (tmp.x==fx&&tmp.y==fy) continue;
            FR(k,0,4){
                int xx=tmp.x+dx[k];
                int yy=tmp.y+dy[k];
                if (inBoard(xx,yy)&&s[xx][yy]!='#'){
                    a.x=xx;a.y=yy;a.t=tmp.t+1;
                    if (s[a.x][a.y]=='x') a.t++;
                    if (a.t<t[xx][yy]){
                        t[xx][yy]=a.t;
                        if (a.t<t[fx][fy]) q.push(a);
                    }
                }
            }
        }
        if (t[fx][fy]==INF) cout<<"Poor ANGEL has to stay in the prison all his life.\n";
        else cout<<t[fx][fy]<<endl;
    }
    return 0;
}
