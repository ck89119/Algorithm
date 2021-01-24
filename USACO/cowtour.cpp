/*
ID: ck891191
PROG: cowtour
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
#define dump(x) cout <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl;
const double maxdis=999999999999.0;
int n,x[155],y[155];
double dis[155][155],ret,disn[155],rn[155];

double dist(int i,int j){
    double tmp=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
    return sqrt(tmp);
}

double max2(double a,double b){
    if (a>b) return a;
    else return b;
}

double max3(double a,double b,double c){
    return max2(max2(a,b),c);
}

int init(){
    int i,j;
    char t;
    freopen("cowtour.in","r",stdin);
    freopen("cowtour.out","w",stdout);
    scanf("%d",&n);
    for (i=0;i<n;i++)
        scanf("%d%d",&x[i],&y[i]);
    for (i=0;i<n;i++)
        for (j=0;j<n;j++)
            dis[i][j]=maxdis;
    getchar();
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            scanf("%c",&t);
            if (t=='1') dis[i][j]=dist(i,j);
        }
        getchar();
    }
    for (i=0;i<n;i++) dis[i][i]=0;
    ret=maxdis;
    return 0;
}

int solve(){
    int i,j,k;
    for (k=0;k<n;k++)
        for (i=0;i<n;i++)
            for (j=0;j<n;j++)
                if (dis[i][j]>dis[i][k]+dis[k][j])
                    dis[i][j]=dis[i][k]+dis[k][j];

    for (i=0;i<n;i++){
        disn[i]=0;
        for (j=0;j<n;j++)
            if (dis[i][j]!=maxdis&&dis[i][j]>disn[i])
                disn[i]=dis[i][j];
    }

    for (i=0;i<n;i++){
        rn[i]=disn[i];
        for (j=0;j<n;j++)
            if (dis[i][j]!=maxdis&&disn[j]>rn[i])
                rn[i]=disn[j];
    }

    for (i=0;i<n;i++)
        for (j=i+1;j<n;j++)
            if (dis[i][j]==maxdis)
                if (ret>max3(rn[i],rn[j],disn[i]+disn[j]+dist(i,j))){
                    ret=max3(rn[i],rn[j],disn[i]+disn[j]+dist(i,j));
                }
    return 0;
}

int print(){
    printf("%.6lf\n",ret);
}

int main(){
    init();
    solve();
    print();
    return 0;
}
