/*
ID: ck891191
PROG: msquare
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
int queue[50000][9],head,tail,pre[50000],len;
char path[50000],ret[50000];
bool v[40320];

int trans_a(int a[9]){
    int i,b[9];
    for (i=1;i<=8;i++) b[i]=a[i];
    for (i=1;i<=8;i++) a[i]=b[9-i];
    return 0;
}

int trans_b(int a[9]){
    int i,b[9];
    for (i=1;i<=8;i++) b[i]=a[i];
    a[1]=b[4];a[2]=b[1];a[3]=b[2];a[4]=b[3];
    a[8]=b[5];a[7]=b[8];a[6]=b[7];a[5]=b[6];
    return 0;
}

int trans_c(int a[9]){
    int i,b[9];
    for (i=1;i<=8;i++) b[i]=a[i];
    a[1]=b[1];a[2]=b[7];a[3]=b[2];a[4]=b[4];
    a[8]=b[8];a[7]=b[6];a[6]=b[3];a[5]=b[5];
    return 0;
}

int rank(int a[9]){
    int i,j,t,ans;
    int fac[9]={1,1,2,6,24,120,720,5040,40320};
    ans=0;
    for (i=1;i<=8;i++){
        t=0;
        for (j=i+1;j<=8;j++)
            if (a[j]<a[i]) t++;
        ans+=fac[8-i]*t;
    }
    return ans;
}

int add(int a[9]){
    int i;
    for (i=1;i<=8;i++)
        queue[head][i]=a[i];
    head++;
    return 0;
}

int get(int a[9]){
    int i;
    for (i=1;i<=8;i++)
        a[i]=queue[tail][i];
        tail++;
    return 0;
}

int print(int a){
    if (pre[a]==0){
        ret[len]=path[a];
        len++;
    }
    else{
        print(pre[a]);
        ret[len]=path[a];
        len++;
    }
    return 0;
}

int main(){
    int i,tar[9];
    freopen("msquare.in","r",stdin);
    freopen("msquare.out","w",stdout);
    for (i=1;i<=8;i++)
        scanf("%d",&tar[i]);
    memset(v,0,sizeof(v));
    head=1;tail=0;v[0]=1;
    for (i=1;i<=8;i++)
        queue[0][i]=i;
    if (rank(queue[0])==rank(tar)){
        printf("0\n\n");
        return 0;
    }
    while (head>tail){
        int t1[9],t2[9];
        get(t1);
        //A
        for (i=1;i<=8;i++)
            t2[i]=t1[i];
        trans_a(t2);
        if (rank(t2)==rank(tar)){
            pre[head]=tail-1;
            path[head]='A';
            add(t2);
            break;
        }
        if (v[rank(t2)]==0){
            pre[head]=tail-1;
            path[head]='A';
            add(t2);
            v[rank(t2)]++;
        }
        //B
        for (i=1;i<=8;i++)
            t2[i]=t1[i];
        trans_b(t2);
        if (rank(t2)==rank(tar)){
            pre[head]=tail-1;
            path[head]='B';
            add(t2);
            break;
        }
        if (v[rank(t2)]==0){
            pre[head]=tail-1;
            path[head]='B';
            add(t2);
            v[rank(t2)]++;
        }
        //C
        for (i=1;i<=8;i++)
            t2[i]=t1[i];
        trans_c(t2);
        if (rank(t2)==rank(tar)){
            pre[head]=tail-1;
            path[head]='C';
            add(t2);
            break;
        }
        if (v[rank(t2)]==0){
            pre[head]=tail-1;
            path[head]='C';
            add(t2);
            v[rank(t2)]++;
        }
    }
    len=0;
    print(head-1);
    printf("%d\n",len);
    for (i=0;i<len;i++){
        printf("%c",ret[i]);
        if ((i+1)%60==0) printf("\n");
    }
    if (len%60!=0) printf("\n");
    return 0;
}
