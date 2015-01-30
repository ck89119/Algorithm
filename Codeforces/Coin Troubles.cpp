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
const int MAXN=300;
const int MAXT=100000;
//int head[MAXN+5];
//struct Edge{
//    int to;
//    int w;
//    int next;
//}edge[MAXE+5];
//int edge_size;
//int in[MAXN+5];//indegree
//int que[MAXN+5];//res
int n,q,t;
int a[MAXN+5];
int res;
//int cost[MAXN+5];
int pre[MAXN+5],next[MAXN+5];
int f[MAXT+5];


//int topsort(){
//    int tail=0;
//    int i;
//    for (i=0;i<n;i++)
//        if (in[i]==0) que[tail++]=i;
//    for (i=0;i<tail;i++){
//        int k=que[i];
//        for (j=head[k];j!=-1;j=edge[k].next){
//            in[edge[k].to]--;
//            if (in[edge[k].to]==0)
//                que[tail++]=edge[k].to;
//        }
//    }
//    if (tail<n) return 0;
//    else return 1;
//}

int input(){
    int i;
    int b,c;
    scanf("%d%d%d",&n,&q,&t);
    for (i=1;i<=n;i++) scanf("%d",&a[i]);
    CL(pre,-1);CL(next,-1);
    for (i=0;i<q;i++){
        scanf("%d%d",&b,&c);
        pre[c]=b;
        next[b]=c;
//        if (ingra[b]==0) {gra_size++;ingra[b]=1;}
//        if (ingra[c]==0) {gra_size++;ingra[c]=1;}
//        edge[edge_size].to=c;
//        edge[edge_size].next=head[b];
//        in[c]++;
//        head[b]=edge_size++;
    }
    //dump(t);
    int visited[MAXN+5];
    CL(visited,0);
    for (i=1;i<=n;i++)
        if (pre[i]==-1){
            int k=next[i];
            visited[i]=1;
            while (k!=-1){
                visited[k]=1;
                a[k]+=a[pre[k]];
                k=next[k];
            }
        }
    for (i=1;i<=n;i++)
        if (next[i]!=-1){
            t-=a[i];
            if (t<0) {res=-1;return 0;}
        }
    //dump(t);
    for (i=1;i<=n;i++)
        if (!visited[i]){
            res=-1;
            break;
        }
    return 0;
}

int sum(int a,int b){
    return a+b;
}

int CompletePack(int cost){
    int i;
    for (i=cost;i<=t;i++)
        f[i]=sum(f[i],f[i-cost])%1000000007;
    return 0;
}

int output(int x){
    cout<<x<<endl;
    return 0;
}

int solve(){
    int i;
    if (res==-1) {output(0);return 0;}
    CL(f,0);
    f[0]=1;
    for (i=1;i<=n;i++)
        CompletePack(a[i]);
    output(f[t]);
    return 0;
}

int main(){
    input();
    solve();
    return 0;
}
