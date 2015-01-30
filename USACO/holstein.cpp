/*
ID: ck891191
PROG: holstein
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define dump(x) cout <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl;
int tar_v[30],v;
int feed[20][30],g;
int ret,ret_path[30],best_path[30];
int init(){
    int i,j;
    freopen("holstein.in","r",stdin);
    freopen("holstein.out","w",stdout);
    scanf("%d",&v);
    for (i=0;i<v;i++) scanf("%d",&tar_v[i]);
    scanf("%d",&g);
    for (i=0;i<g;i++)
        for (j=0;j<v;j++)
            scanf("%d",&feed[i][j]);
    //dump(v);dump(g);
    ret=g+1;
    //memset(cur_v,0,sizeof(cur_v));
    return 0;
}

int dfs(int cur_v[30],int dep,int best){
    int i,j,flag;
    //dump(dep);dump(best);dump(g);dump(ret);
    if (best>=ret) return 0;
    flag=1;

    for (i=0;i<v;i++)
    {
        //cout<<cur_v[i]<<' '<<tar_v[i]<<endl;
        if (cur_v[i]<tar_v[i]){
            flag=0;
            break;
        }
    }
    //dump(flag);
    if (flag){
        if (ret>best) ret=best;
        //dump(ret);
        for (i=0;i<ret;i++)
            ret_path[i]=best_path[i];
        return 0;
    }

    for (i=dep;i<g;i++){
        for (j=0;j<v;j++) cur_v[j]+=feed[i][j];
        best_path[best]=i;
        //dump(dep);dump(i);
        dfs(cur_v,i+1,best+1);
        for (j=0;j<v;j++) cur_v[j]-=feed[i][j];
    }
    return 0;
}

int solve(){
    int cur_v[30];
    memset(cur_v,0,sizeof(cur_v));
    dfs(cur_v,0,0);
    return 0;
}

int print(){
    int i;
    printf("%d",ret);
    for (i=0;i<ret;i++) printf(" %d",ret_path[i]+1);
    printf("\n");
    return 0;
}
int main(){
    init();
    solve();
    print();
    return 0;
}
