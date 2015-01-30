/*
ID: ck891191
PROG: fence
LANG: C++
*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;
#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl;
const int INF=9999999;
int F;
int path[505][505];
int minn,maxn,src;
int circuit[1050];
//stack<int> s;


int input(){
    int i,u,v;
    freopen("fence.in","r",stdin);
    freopen("fence.out","w",stdout);
    scanf("%d",&F);
    memset(path,0,sizeof(path));
    minn=INF;maxn=0;
    for (i=0;i<F;i++){
        scanf("%d%d",&u,&v);
        path[u][v]++;path[u][0]++;
        path[v][u]++;path[v][0]++;
        if (u<minn) minn=u;
        if (v<minn) minn=v;
        if (u>maxn) maxn=u;
        if (v>maxn) maxn=v;
    }
    //dump(minn);dump(maxn);
//    int j;
//    for (i=0;i<=maxn;i++){
//       for (j=0;j<=maxn;j++) printf("%d ",path[i][j]);
//       printf("\n");}
    circuit[0]=0;
    return 0;
}

int euler_circuit(int st){
    int loc,i;
    loc=st;
    if (!path[loc][0]){
        circuit[++circuit[0]]=loc;//dump(loc);
        //loc=s.top();s.pop();
        //euler_circuit(loc);
    }
    else{
        while (path[loc][0]){
            for (i=minn;i<=maxn;i++)
                if (path[loc][i]) break;
            path[loc][i]--;path[i][loc]--;
            path[loc][0]--;path[i][0]--;
            //s.push(loc);//dump(loc);
            euler_circuit(i);
        }
        circuit[++circuit[0]]=loc;//dump(loc);
    }
    return 0;
}

int solve(){
    int i;
    src=minn;
    for (i=minn;i<=maxn;i++)
        if(path[i][0]%2==1){
            src=i;break;
            }
   // dump(src);
    euler_circuit(src);
    for (i=circuit[0];i>=1;i--)
        printf("%d\n",circuit[i]);
    return 0;
}

int main(){
    input();
    solve();
    return 0;
}
