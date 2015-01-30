/*
ID: ck891191
PROG: zerosum
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n,path[15],ret_size;
char ret[1000][20],intstr[10][2]={"0","1","2","3","4","5","6","7","8","9"};
int init(){
    freopen("zerosum.in","r",stdin);
    freopen("zerosum.out","w",stdout);
    scanf("%d",&n);
    memset(path,0,sizeof(path));
    path[0]=1;
    ret_size=0;
    return 0;
}

int sum(){
    int s=0,i,j,t;
    for (i=0;i<n;){
        t=i+1;j=i+1;
        while (j<n&&path[j]==3){
            j++;
            t=t*10+j;
        }
        if (path[i]==1) s+=t;
        if (path[i]==2) s-=t;
        i=j;
    }
    if (s==0) return 1;
    else return 0;
}

int dfs(int dep){
    int i;
    if (dep>=n){
        if (sum()){
            strcat(ret[ret_size],"1");
            for (i=1;i<n;i++){
                if (path[i]==1){
                    strcat(ret[ret_size],"+");
                    strcat(ret[ret_size],intstr[i+1]);
                }
                if (path[i]==2){
                    strcat(ret[ret_size],"-");
                    strcat(ret[ret_size],intstr[i+1]);
                }
                if (path[i]==3){
                    strcat(ret[ret_size]," ");
                    strcat(ret[ret_size],intstr[i+1]);
                }
            }
            ret_size++;
        }
        return 0;
    }
    path[dep]=3;dfs(dep+1);
    path[dep]=1;dfs(dep+1);
    path[dep]=2;dfs(dep+1);

    return 0;
}

int solve(){
    dfs(1);
    return 0;
}

int print(){
    int i;
    for (i=0;i<ret_size;i++)
        printf("%s\n",ret[i]);
    return 0;
}

int main(){
    init();
    solve();
    print();
    return 0;
}
