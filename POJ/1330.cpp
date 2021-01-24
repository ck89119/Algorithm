/*
ID: ck89119
PROG: POJ1330
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
const int maxn=10005
int tree[maxn];
int anc[][];
int init(){
    int i;
    for (i=0;i<=maxn;i++) tree[i]=i;
    return 0;
}
int main(){
    int t,n;
    scanf("%d",&t);
    while (t--){
        int i,a,b;
        init();
        scanf("%d",&n);
        for (i=1;i<n;i++){
            scanf("%d%d",&a,&b);
            tree[b]=a;
        }
    }
    return 0;
}
