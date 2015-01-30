/*
ID: ck891191
PROG: preface
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define dump(x) cout <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl;
char mapping[5][10][5]={"","I","II","III","IV","V","VI","VII","VIII","IX",
                        "","X","XX","XXX","XL","L","LX","LXX","LXXX","XC",
                        "","C","CC","CCC","CD","D","DC","DCC","DCCC","CM",
                        "","M","MM","MMM"};
int sum[7];
int n;
int init(){
    freopen("preface.in","r",stdin);
    freopen("preface.out","w",stdout);
    scanf("%d",&n);
    memset(sum,0,sizeof(sum));
    return 0;
}

int solve(){
    int i,ii,j,k;
    for (i=1;i<=n;i++){
        k=0;ii=i;
        while (ii!=0){
            int tmp;
            tmp=ii%10;
            //dump(tmp);
            //dump(mapping[k][tmp]);
            for (j=0;mapping[k][tmp][j];j++)
                if (mapping[k][tmp][j]=='I') sum[0]++;
                else if (mapping[k][tmp][j]=='V') sum[1]++;
                else if (mapping[k][tmp][j]=='X') sum[2]++;
                else if (mapping[k][tmp][j]=='L') sum[3]++;
                else if (mapping[k][tmp][j]=='C') sum[4]++;
                else if (mapping[k][tmp][j]=='D') sum[5]++;
                else if (mapping[k][tmp][j]=='M') sum[6]++;
            ii/=10;k++;
        }
    }
    return 0;
}

int print(){
    if (sum[0]) printf("I %d\n",sum[0]);
    if (sum[1]) printf("V %d\n",sum[1]);
    if (sum[2]) printf("X %d\n",sum[2]);
    if (sum[3]) printf("L %d\n",sum[3]);
    if (sum[4]) printf("C %d\n",sum[4]);
    if (sum[5]) printf("D %d\n",sum[5]);
    if (sum[6]) printf("M %d\n",sum[6]);
    return 0;
}
int main(){
    init();
    solve();
    print();
    return 0;
}
