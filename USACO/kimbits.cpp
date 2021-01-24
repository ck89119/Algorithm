/*
ID: ck891191
PROG: kimbits
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl;
int n,l,i;
int input(){
    freopen("kimbits.in","r",stdin);
    scanf("%d%d%d",&n,&l,&i);
    return 0;
}

int lowbit(int x){
    return x&(x^(x-1));
}

int num_of_one(int x){
    int ret=0;
    while (x!=0){
        x-=lowbit(x);
        ret++;
    }
    return ret;
}
int solve(){
    unsigned int k;
    int count=0;
    for (k=0;count<i;k++){
        if (num_of_one(k)<=l) count++;
        //dump(k);dump(num_of_one(k));
    }
    return k-1;
}

int output(){
    int str[40],k;
    int t;
    freopen("kimbits.out","w",stdout);
    t=solve();
    memset(str,0,sizeof(str));
    while (t){
        str[0]++;
        str[str[0]]=t%2;
        t/=2;
    }
    for (k=n;k>=1;k--) printf("%d",str[k]);
    printf("\n");
    return 0;
}

int main(){
    input();
    output();
    return 0;
}
