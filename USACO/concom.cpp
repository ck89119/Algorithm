/*
ID: ck891191
PROG: concom
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl
int n,ctrl[105][105],control[105][105],visited[105],tmp[105];
int init(){
    int i,x,y,z;
    freopen("concom.in","r",stdin);
    freopen("concom.out","w",stdout);
    scanf("%d",&n);
    memset(ctrl,0,sizeof(ctrl));
    memset(control,0,sizeof(control));
    for (i=0;i<n;i++){
        scanf("%d%d%d",&x,&y,&z);
        ctrl[x][y]=z;
        ctrl[x][0]=1;ctrl[y][0]=1;
    }
    return 0;
}

int dfs(int x){
    int i;
    for (i=1;i<105;i++)
        if (!visited[i]){
            tmp[i]+=ctrl[x][i];
            if (tmp[i]>50){
                visited[i]=1;
                dfs(i);
            }
        }
    return 0;
}

int solve(){
    int i,j;
    for (i=1;i<105;i++)
        if (ctrl[i][0]){
            memset(visited,0,sizeof(visited));
            memset(tmp,0,sizeof(tmp));
            visited[i]=1;
            dfs(i);
            for (j=1;j<105;j++)
                if (tmp[j]>50) control[i][j]=1;
        }
    return 0;
}

int print(){
    int i,j;
    for (i=1;i<105;i++)
        for (j=1;j<105;j++)
            if (i!=j&&control[i][j])
                printf("%d %d\n",i,j);
    return 0;
}

int main(){
    init();
    solve();
    print();
    return 0;
}
