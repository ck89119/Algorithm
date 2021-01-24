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
int visited[100005];
int n,s,t;
int p[100005];

int input(){
    int i;
    scanf("%d%d%d",&n,&s,&t);
    for (i=1;i<=n;i++)
        scanf("%d",&p[i]);
    return 0;
}

int solve(){
    int i;
    int res;
    memset(visited,0,sizeof(visited));
    i=s;res=0;
    while (i!=t){
        if (!visited[i]) visited[i]=1;
        else break;
        i=p[i];
        res++;
    }
    if (i!=t) res=-1;
    printf("%d\n",res);
}

int main(){
    input();
    solve();
    return 0;
}
