/*
ID: ck891191
PROG: fracdec
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n,d,deci[100000],visited[100000],ret_len;
char ret[100000];
int init(){
    freopen("fracdec.in","r",stdin);
    freopen("fracdec.out","w",stdout);
    scanf("%d%d",&n,&d);
    return 0;
}

int solve(){
    int a,i,t_len;
    char tmp[10];
    a=n/d;n=n%d;
    t_len=0;
    if (a==0){
        t_len=1;
        tmp[t_len-1]='0';
    }
    else {
        while (a!=0){
            tmp[t_len++]=a%10+'0';
            a/=10;
        }
    }
    ret_len=t_len+1;
    for (i=0;i<t_len;i++)
        ret[i]=tmp[t_len-1-i];
    ret[ret_len-1]='.';
    if (n==0){
        ret[ret_len++]='0';
        return 0;
    }

    deci[0]=0;
    memset(visited,0,sizeof(visited));
    while (n!=0&&!visited[n]){
        deci[++deci[0]]=n*10/d;
        visited[n]=deci[0];
        n=n*10%d;
    }

    if (n==0)
        for (i=1;i<=deci[0];i++) ret[ret_len++]='0'+deci[i];
    else{
        for (i=1;i<visited[n];i++) ret[ret_len++]='0'+deci[i];
        ret[ret_len++]='(';
        for (i=visited[n];i<=deci[0];i++) ret[ret_len++]='0'+deci[i];
        ret[ret_len++]=')';
    }
    return 0;
}

int print(){
    int i,sum=0;
    for (i=0;i<ret_len;i++){
        printf("%c",ret[i]);
        sum++;
        if (sum==76) {printf("\n");sum=0;}
    }
    if (sum) printf("\n");
    return 0;
}

int main(){
    init();
    solve();
    print();
    return 0;
}
