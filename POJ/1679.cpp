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
const int MAXN=100;
const int MAXE=MAXN*MAXN/2;
int t,n,m;
struct Edge{
    int a,b;
    int w;
    int select;
}edge[MAXE+5];
int head[MAXN+5];
int end[MAXN+5];
struct Link{
    //int to;
    int next;
}link[MAXN+5];
int father[MAXN+5];
int len[MAXN+5][MAXN+5];
int find(int x){
    if (father[x]==x) return x;
    else return father[x]=find(father[x]);
}
int merge(int x, int y){
    father[find(x)]=father[find(y)];
    return 0;
}

int input(){
    int a,b,w;
    scanf("%d%d",&n,&m);
    FR(i,0,m){
        scanf("%d%d%d",&a,&b,&w);
        edge[i].a=a;
        edge[i].b=b;
        edge[i].w=w;
        edge[i].select=0;
    }
    return  0;
}

int cmp(const Edge &a, const Edge &b){
    if (a.w!=b.w) return a.w<b.w;
    if (a.a!=b.a) return a.a<b.a;
    return a.b<b.b;
}

int kruskal(){
    int i,k;
    for (i=1;i<=n;i++) father[i]=i;
    sort(edge,edge+m,cmp);
    CL(len,0);
    for (i=1;i<=n;i++){
        //link[i].to=i;
        link[i].next=-1;
        head[i]=i;
        end[i]=i;
    }
    k=0;
    for (i=0;i<m;i++){
        int x,y;
        if (k==n-1) break;
        x=find(edge[i].a);
        y=find(edge[i].b);
        //dump(x);dump(y);FR(j,1,n+1) cout<<father[j]<<' ';cout<<endl;
        if (x!=y){
            for (int w=head[x];w!=-1;w=link[w].next)
                for (int v=head[y];v!=-1;v=link[v].next){
                    len[w][v]=edge[i].w;
                    len[v][w]=edge[i].w;
                }
            link[end[y]].next=head[x];
            end[y]=end[x];
            merge(x,y);
            edge[i].select=1;
            k++;
        }
//        for (int w=1;w<=n;w++){
//            for (int v=1;v<=n;v++)
//                cout<<len[w][v]<<' ';
//            cout<<endl;}
    }
    return 0;
}

int main(){
    scanf("%d",&t);
    while (t--){
        int m1,m2;
        int s1,s2;
        input();
        kruskal();
        s1=0;
        FR(i,0,m)
            if (edge[i].select) s1+=edge[i].w;
        //dump(s1);
        s2=INF;
        FR(i,0,m){//dump(edge[i].a);dump(edge[i].b);dump(edge[i].w);dump(len[edge[i].a][edge[i].b]);
            if (!edge[i].select)
                s2=min(s2,s1-len[edge[i].a][edge[i].b]+edge[i].w);
        }
        if (s1==s2) cout<<"Not Unique!\n";
        else cout<<s1<<endl;
    }
    return 0;
}
