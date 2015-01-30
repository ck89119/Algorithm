/*
ID: ck891191
PROG: POJ1922
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
//const double esp=1e-11;
int main(){
    int N;
    int i,vi,ti,p;

    while (scanf("%d",&N),N){
        double ret=999999999.0;
        for (i=0;i<N;i++){
            double tmp;
            scanf("%d%d",&vi,&ti);
            tmp=4.5*3600*1.0/vi+ti*1.0;
            if (ti>=0&&ret>tmp) ret=tmp;
        }
        p=ret;
        if (ret-p==0) printf("%d\n",p);
        else printf("%.f\n",ret+0.5);
    }
    return 0;
}
