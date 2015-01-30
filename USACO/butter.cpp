/*
ID: ck891191
PROG: butter
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
const int INF=99999999;
int n,p,c;
int cow[505];
int s[805];
int b[805][805];
int len[805][805];
int dis[805];
int inque[805];

class queue{
    private:
        int begin,end;
        int ele[805];
        int N;
    public:
        int init(){begin=end=0;}
        queue(int size):N(size){init();}
        int push(int a){
            ele[end]=a;
            end=(end+1)%N;
            return 0;
        }
        int pop(){
            int a;
            a=ele[begin];
            begin=(begin+1)%N;
            return a;
        }
        int empty(){
            return (begin==end);
        }
};

int init(){
    int i,u,v,w;
    freopen("butter.in","r",stdin);
    freopen("butter.out","w",stdout);
    scanf("%d%d%d",&n,&p,&c);
    for (i=0;i<n;i++){
        scanf("%d",&cow[i]);
        cow[i]--;
        }
    memset(s,0,sizeof(s));
    for (i=0;i<c;i++){
        scanf("%d%d%d",&u,&v,&w);
        u--;v--;
        b[u][s[u]]=v;
        len[u][s[u]]=w;
        s[u]++;
        b[v][s[v]]=u;
        len[v][s[v]]=w;
        s[v]++;
    }
    return 0;
}

int relax(int &a,const int &b){
    if (a>b) {a=b;return 1;}
    else return 0;
}

int spfa(int src){
    int i;
    queue q(p+1);
    for (i=0;i<p;i++) dis[i]=INF;
    memset(inque,0,sizeof(inque));
    dis[src]=0;
    q.init();
    q.push(src);
    inque[src]=1;
    while (!q.empty()){
        int u=q.pop();
        inque[u]=0;
        for (i=0;i<s[u];i++){
            int next=b[u][i];
            if (relax(dis[next],dis[u]+len[u][i])&&!inque[next]){
                q.push(next);
                inque[next]=1;
            }
        }
    }
    return 0;
}

int solve(){
    int i,j,res=INF,sum;
    for (i=0;i<p;i++){
        spfa(i);
        sum=0;
       // for (j=0;j<p;j++) printf("%d ",dis[j]);
        //printf("\n");
        for (j=0;j<n;j++)
            sum+=dis[cow[j]];
        //printf("%d\n",sum);
        if (sum<res) res=sum;
    }
    printf("%d\n",res);
    return 0;
}

int main(){
    init();
    solve();
    return 0;
}
