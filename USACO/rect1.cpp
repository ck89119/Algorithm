/*
ID: ck891191
PROG: rect1
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
struct RECT{
    int px,py,qx,qy;
    int c;
}rect[1005];
int a,b,n,c_num[2505];

int input(){
    int i;
    freopen("rect1.in","r",stdin);
    scanf("%d%d%d",&a,&b,&n);
    rect[0].px=0;rect[0].py=0;
    rect[0].qx=a;rect[0].qy=b;
    rect[0].c=1;
    for (i=1;i<=n;i++)
        scanf("%d%d%d%d%d",&rect[i].px,&rect[i].py,&rect[i].qx,&rect[i].qy,&rect[i].c);
    return 0;
}

int cal(int i,int px,int py,int qx,int qy){
    int j=i+1,ret=0;
    while (j<=n&&
           (rect[j].px>=qx||rect[j].qx<=px||
            rect[j].py>=qy||rect[j].qy<=py)) j++;
    if (j>n) ret=(qx-px)*(qy-py);
    else {
        if (rect[j].px>px) ret+=cal(i,px,py,rect[j].px,qy);
        if (rect[j].qx<qx) ret+=cal(i,rect[j].qx,py,qx,qy);
        if (rect[j].py>py) ret+=cal(i,Max(rect[j].px,px),py,Min(rect[j].qx,qx),rect[j].py);
        if (rect[j].qy<qy) ret+=cal(i,Max(px,rect[j].px),rect[j].qy,Min(qx,rect[j].qx),qy);
    }
    return ret;
}

int solve(){
    int i;
    freopen("rect1.out","w",stdout);
    memset(c_num,0,sizeof(c_num));
    for (i=n;i>=0;i--){
        c_num[rect[i].c]+=cal(i,rect[i].px,rect[i].py,rect[i].qx,rect[i].qy);
    }
    return 0;
}

int output(){
    int i;
    for (i=1;i<=2500;i++)
        if (c_num[i]) printf("%d %d\n",i,c_num[i]);
    return 0;
}

int main(){
    input();
    solve();
    output();
    return 0;
}
