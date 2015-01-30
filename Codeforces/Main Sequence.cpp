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
#define FR(i,a,b) for(int i=(a);i<(b);++i)//[a,b)
#define FOR(i,n) FR(i,0,n)//[0,n)
#define CL(a,x) memset(a,x,sizeof(a))
int n,t;
int p[1000005],q[1000005];
int stack[1000005];

int input(){
    int x;
    scanf("%d",&n);
    FR(i,1,n+1) scanf("%d",&p[i]);
    scanf("%d",&t);
    CL(q,0);
    FR(i,0,t){
        scanf("%d",&x);
        q[x]=1;
    }
    return 0;
}

int solve(){
    int top=0;
    for (int i=n;i>=1;i--){
        if (top>0&&!q[i]&&p[i]==p[stack[top-1]]){
            p[stack[top-1]]*=-1;
            top--;
        }
        else stack[top++]=i;
    }
    if (top>0) printf("NO\n");
    else{
        printf("YES\n");
        FR(i,1,n+1) printf("%d ",p[i]);
        printf("\n");
    }
    return 0;
}

int main(){
    input();
    solve();
    return 0;
}


//int input(){
//    int i,k;
//    scanf("%d",&n);
//    for (i=1;i<=n;i++)
//        scanf("%d",&p[i]);
//    scanf("%d",&t);
//    for (i=1;i<=t;i++){
//        scanf("%d",&k);
//        p[k]*=-1;
//    }
//    return 0;
//}
//
//int rec(int l,int r){
//    int t,i;
//
//    if (l>r) return 1;
//    if ((r-l)%2==0) return 0;
//
//    if (p[l]>0&&p[l]*-1==p[r]) return rec(l+1,r-1);
//
//    if (p[l]>0&&p[l]==p[r]) t=rec(l+1,r-1);
//    if (t) {p[r]*=-1;return 1;}
//
//    for (i=l+1;i<r;i+=2){
//        int t1,t2;
//        t1=rec(l,i);
//        if (!t1) continue;
//        t2=rec(i+1,r);
//        if (t1&&t2) return 1;
//    }
//
//    return 0;
//}
//
//int output(int res){
//    int i;
//    if (res==0) printf("NO\n");
//    else{
//        printf("YES\n");
//        for (i=1;i<=n;i++)
//            printf("%d ",p[i]);
//        printf("\n");
//    }
//    return 0;
//}
//
//int main(){
//    input();
//    output(rec(1,n));
//    return 0;
//}
