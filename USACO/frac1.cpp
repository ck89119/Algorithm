/*
ID: ck891191
PROG: frac1
LANG: C++
*/

#include <iostream>
#include <cstdio>
using namespace std;
struct FRAC{
    int n,d;
};
int n,size_f[165];
FRAC f[2][8000];

int input(){
    int i,j;
    freopen("frac1.in","r",stdin);
    freopen("frac1.out","w",stdout);
    scanf("%d",&n);
    for (i=0;i<=1;i++)
        for (j=0;j<8000;j++) {
            f[i][j].d=0;f[i][j].n=0;
        }
    for (i=0;i<=n;i++) size_f[i]=0;
    return 0;
}

int solve(){
    int i,j,tmp;
    f[0][0].n=0;f[0][0].d=1;
    f[0][1].n=1;f[0][1].d=1;
    size_f[1]=2;
    for (i=2;i<=n;i++){
        f[1][0].n=0;f[1][0].d=1;tmp=1;
        for (j=1;j<size_f[i-1];j++){
            if (f[0][j-1].d+f[0][j].d==i){
                f[1][tmp].d=i;
                f[1][tmp].n=f[0][j-1].n+f[0][j].n;
                tmp++;
            }
            f[1][tmp].d=f[0][j].d;
            f[1][tmp].n=f[0][j].n;
            tmp++;
        }
        size_f[i]=tmp;
        for (j=0;j<size_f[i];j++){
            f[0][j].n=f[1][j].n;
            f[0][j].d=f[1][j].d;
        }
    }
    return 0;
}

int output(){
    int i;
    for (i=0;i<size_f[n];i++) printf("%d/%d\n",f[0][i].n,f[0][i].d);
    //cout<<size_f[n]<<endl;
    return 0;
}

int main(){
    input();
    solve();
    output();
    return 0;
}
