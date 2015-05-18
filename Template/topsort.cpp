/*
ID: ck891191
PROG:
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
#define dump(x) cerr<<__LINE__<<"  "<<#x<<"  :  "<<(x)<<endl;
#define two(X) (1<<(X))
#define towL(X) (((int64)(1))<<(x))
#define contain(S,X) ((S&two(X))>0)
#define containL(S,X) ((S&twoL(X))>0)
#define FR(i,a,b) for(int i=(a);i<(b);++i)//[a,b)
#define FOR(i,n) FR(i,0,n)//[0,n)
#define RF(i,a,b) for(int i=(a)-1;i>=(b);--i)//(a,b]
#define ROF(i,n) RF(i,n,0)//[0,n)
#define CL(a,x) memset(a,x,sizeof(a))

const int INF=(1<<30);
const double PI=acos(-1.0);
const double EPS=1e-11;

int head[MAXN];

struct Edge{
    int to;
    int w;
    int next;
}edge[MAXE];
int in[MAXN];//indegree
int que[MAXN];//res

int topsort(){
    int tail=0;
    int i;
    for (i=0;i<n;i++)
        if (in[i]==0) que[tail++]=i;
    for (i=0;i<tail;i++){
        int k=que[i];
        for (j=head[k];j!=-1;j=edge[k].next){
            in[edge[k].to]--;
            if (in[edge[k].to]==0)
                que[tail++]=edge[k].to;
        }
    }
    return 0;
}

int main(){

    return 0;
}
