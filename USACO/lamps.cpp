/*
ID: ck891191
PROG: lamps
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define dump(x) cout <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl;
typedef int LAMP[105];
LAMP ret[10000];
int lamp[105],n,c,tar[105],ret_size;
int op1(){
    int i;
    for (i=1;i<=n;i++) lamp[i]=1-lamp[i];
    return 0;
}

int op2(){
    int i;
    for (i=1;i<=n;i+=2) lamp[i]=1-lamp[i];
    return 0;
}

int op3(){
    int i;
    for (i=2;i<=n;i+=2) lamp[i]=1-lamp[i];
    return 0;
}

int op4(){
    int i;
    for (i=1;i<=n;i+=3) lamp[i]=1-lamp[i];
    return 0;
}

int init(){
    int tmp,i;
    freopen("lamps.in","r",stdin);
    freopen("lamps.out","w",stdout);
    scanf("%d%d",&n,&c);//dump(n);dump(c);
    memset(tar,-1,sizeof(tar));
    while (scanf("%d",&tmp),tmp!=-1) tar[tmp]=1;
    while (scanf("%d",&tmp),tmp!=-1) tar[tmp]=0;
    //for (i=0;i<=n;i++) cout<<tar[i];cout<<endl;
    for (i=0;i<=n;i++) lamp[i]=1;
    ret_size=0;
    return 0;
}

int dfs(int c1){
    int i,flag;
   // dump(c1);
    if (c1==0){
        flag=1;

        for (i=1;i<=n;i++){
            if (tar[i]==-1) continue;
            if (tar[i]!=-1&&lamp[i]==tar[i]) continue;
            flag=0;break;
        }
        if (flag){
            for (i=1;i<=n;i++) ret[ret_size][i]=lamp[i];
            ret_size++;
        }

      //  for (i=1;i<=n;i++) cout<<lamp[i];cout<<endl;dump(ret_size);
        return 0;
    }

    op1();
    dfs(c1-1);
    op1();

    op2();
    dfs(c1-1);
    op2();

    op3();
    dfs(c1-1);
    op3();

    op4();
    dfs(c1-1);
    op4();

    return 0;
}

int solve(){
    int c1;
    if (c%2==0) c1=0;
    else c1=1;
    while (c1<=4&&c1<=c){
        dfs(c1);
        c1+=2;
    }
    return 0;
}

int cmp(const LAMP a,const LAMP b){
    int i;
    for (i=1;i<=n;i++){
        if (a[i]<b[i]) return 1;
        if (a[i]>b[i]) return 0;
    }
    return 0;
}

int ssort(){
    int i,j,k,tmp;
    for (i=0;i<ret_size;i++)
        for (j=i+1;j<ret_size;j++)
            if (!cmp(ret[i],ret[j]))
                for (k=0;k<=n;k++){
                    tmp=ret[i][k];
                    ret[i][k]=ret[j][k];
                    ret[j][k]=tmp;
                }
    return 0;
}
int print(){
    int i,j,flag;
    if (ret_size==0) {
        printf("IMPOSSIBLE\n");
        return 0;
    }
    ssort();
    for (j=1;j<=n;j++) printf("%d",ret[0][j]);
    printf("\n");
    for (i=1;i<ret_size;i++){
        flag=1;
        for (j=1;j<=n;j++)
            if (ret[i][j]!=ret[i-1][j]){
                flag=0;
                break;
            }
        if (flag==0){
            for (j=1;j<=n;j++) printf("%d",ret[i][j]);
            printf("\n");
        }
    }
    return 0;
}

int main(){
    init();
    solve();
    print();
    return 0;
}
