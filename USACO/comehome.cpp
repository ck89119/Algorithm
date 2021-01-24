/*
ID: ck891191
PROG: comehome
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl;
const int maxdis=999999999;
int p,dis[60][60],cow[60],dist[60],n,count[60];

int up(char a){
    if (a>='A'&&a<='Z') return a-'A';
    else return -1;
}

int down(char a){
    if (a>='a'&&a<='z') return a-'a';
    else return -1;
}

int init(){
    int i,j,ia,ib,d;
    char a,b;
    freopen("comehome.in","r",stdin);
    freopen("comehome.out","w",stdout);
    scanf("%d",&p);
    for (i=0;i<60;i++)
        for (j=0;j<60;j++)
            if (i==j) dis[i][j]=0;
            else dis[i][j]=maxdis;
    memset(cow,0,sizeof(cow));
    memset(count,0,sizeof(count));
    for (i=0;i<p;i++){
        getchar();
        scanf("%c %c %d",&a,&b,&d);
        //dump(a);   dump(b);   dump(d);

        if (up(a)>=0) {ia=up(a);cow[ia]=1;}
        else ia=26+down(a);
        if (up(b)>=0) {ib=up(b);cow[ib]=1;}
        else ib=26+down(b);
        count[ia]=1;count[ib]=1;
        if (dis[ia][ib]>d){
            dis[ia][ib]=d;
            dis[ib][ia]=d;
        }
    }
    n=0;
    for (i=0;i<60;i++) n+=count[i];
   // dump("%%%%%%%%%%%");
    return 0;
}

int dijskra(int src){
    int i,j,k,shdis;
    int visited[60];
    memset(visited,0,sizeof(visited));
    for (i=0;i<60;i++) dist[i]=dis[i][src];
    visited[src]=1;

    for (i=0;i<n-1;i++){
        shdis=maxdis;k=-1;
        for (j=0;j<60;j++)
            if (!visited[j]&&dist[j]<shdis){
                shdis=dist[j];
                k=j;
            }
        if (k==-1) break;
        visited[k]=1;
        for (j=0;j<60;j++)
            if (!visited[j]&&dist[j]>dist[k]+dis[k][j])
                dist[j]=dist[k]+dis[k][j];
    }
    return 0;
}

int solve(){
    dijskra(25);
    return 0;
}

int print(){
    int i,ret=maxdis,k=-1;
    for (i=0;i<25;i++)
        if (cow[i]&&dist[i]<ret) {
            ret=dist[i];
            k=i;
        }
    printf("%c %d\n",'A'+k,ret);
}

int main(){
    init();
    solve();
    print();
    return 0;
}
