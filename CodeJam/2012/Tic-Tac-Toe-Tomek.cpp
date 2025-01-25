/*
ID: ck891191
PROG:
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <fstream>
#include <iomanip>
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
#define lowbit(x) ((x)&(-(x)))
//freopen("","r",stdin);
//freopen("","w",stdout);
const long long MAXN=(1LL<<62);
const int INF=(1<<30);
const double PI=acos(-1.0);
const double EPS=1e-11;

int t;
char board[5][5];

char sol1(int x){
    char ch;
    int flag;
    int i;
    ch=board[x][0];
    if (ch=='T') ch=board[x][1];
    if (ch=='.') return 'W';
    flag=1;
    for (i=1;i<4;i++)
        if (board[x][i]!='T'&&board[x][i]!=ch) {
            flag=0;
            break;
        }
    if (flag) return ch;
    else return 'W';
}

char sol2(int y){
    char ch;
    int flag;
    int i;
    ch=board[0][y];
    if (ch=='T') ch=board[1][y];
    if (ch=='.') return 'W';;
    flag=1;
    for (i=1;i<4;i++)
        if (board[i][y]!='T'&&board[i][y]!=ch) {
            flag=0;
            break;
        }
    if (flag) return ch;
    else return 'W';
}

char sol3(){
    char ch;
    int flag;
    int i;
    ch=board[0][0];
    if (ch=='T') ch=board[1][1];
    if (ch=='.') return 'W';
    flag=1;
    for (i=1;i<4;i++)
        if (board[i][i]!='T'&&board[i][i]!=ch) {
            flag=0;
            break;
        }
    if (flag) return ch;
    else return 'W';
}

char sol4(){
    char ch;
    int flag;
    int i;
    ch=board[0][3];
    if (ch=='T') ch=board[1][2];
    if (ch=='.') return 'W';
    flag=1;
    for (i=1;i<4;i++)
        if (board[i][3-i]!='T'&&board[i][3-i]!=ch) {
            flag=0;
            break;
        }
    if (flag) return ch;
    else return 'W';
}

int main(){
    int i,j,k;
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    scanf("%d",&t);
    for (k=1;k<=t;k++){
        char win;
        int flag;
        for (i=0;i<4;i++) scanf("%s",board[i]);
        //for (i=0;i<4;i++) printf("%s\n",board[i]);
        flag=0;
        for (i=0;i<4;i++){
            win=sol1(i);
            if (win!='W'){
                flag=1;
                break;
            }
        }
        if (flag) {printf("Case #%d: %c won\n",k,win);continue;}

        for (j=0;j<4;j++){
            win=sol2(j);
            if (win!='W'){
                flag=1;
                break;
            }
        }
        if (flag) {printf("Case #%d: %c won\n",k,win);continue;}

        win=sol3();
        if (win!='W') flag=1;
        if (flag) {printf("Case #%d: %c won\n",k,win);continue;}

        win=sol4();
        if (win!='W') flag=1;
        if (flag) {printf("Case #%d: %c won\n",k,win);continue;}

        if (!flag){
            int ff;
            ff=0;
            for (i=0;i<4;i++)
                for (j=0;j<4;j++)
                    if (board[i][j]=='.'){
                        ff=1;
                        break;
                    }
            if (ff) printf("Case #%d: Game has not completed\n",k);
            else printf("Case #%d: Draw\n",k);
        }

    }

    return 0;
}
