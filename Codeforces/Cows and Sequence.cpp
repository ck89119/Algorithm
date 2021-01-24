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
int n;
int num[200005],size;
int x[200005],y[200005],s;
double sum;

int main(){
    int i,j;
    int type,a,b;
    scanf("%d",&n);
    sum=0.0;size=1;s=0;
    memset(num,0,sizeof(num));
    for (i=0;i<n;i++){
        scanf("%d",&type);
        if (type==1){
            scanf("%d%d",&a,&b);
            //for (j=0;j<a;j++) num[j]+=b;
            sum+=a*b;
            x[s]=a;y[s]=b;s++;
            printf("%.6lf\n",1.0*sum/size);
        }
        else if (type==2){
            scanf("%d",&a);
            num[size++]=a;
            sum+=a;
            printf("%.6lf\n",1.0*sum/size);
        }
        else{
            size--;
            sum-=num[size];
            for (j=0;j<s;j++)
                if (x[j]-1==size) {
                    sum-=y[j];
                    x[j]--;
                    }
            printf("%.6lf\n",1.0*sum/size);
        }
    }

    return 0;
}
