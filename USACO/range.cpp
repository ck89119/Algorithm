/*
ID: ck891191
PROG: range
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
int N;
int field[255][255];
int res[255];
int init(){
    int i,j;
    char s[255];
    freopen("range.in","r",stdin);
    scanf("%d",&N);
    for (i=0;i<N;i++){
        scanf("%s",s);
        for (j=0;j<N;j++)
            field[i][j]=s[j]-'0';
    }
    return 0;
}

//int check(int size,int x,int y){
//    int i,j;
//    int f=1;
//    if ((x+size-1>=N)||(y+size-1>=N)) return 0;
//    for (i=x;i<x+size-1;i++)
//        for (j=y;j<y+size-1;j++)
//           if (!field[i][j]) {f=0;return f;}
//   // printf("%d %d %d\n",size,x,y);
//    return f;
//}

//int solve(){
//    int ff[255][255];
//    int size,i,j,ii,jj;
//    memset(res,0,sizeof(res));
//    for (size=2;size<=N;size++){
//        //dump(size);
//        for (i=0;i<N;i++)
//            for (j=0;j<N;j++){
//                ff[i][j]=field[i][j];
//                if (!ff[i][j])
//                    for (ii=i;ii>=0&&ii>i-size;ii--)
//                        for (jj=j;jj>=0&&jj>j-size;jj--)
//                            ff[ii][jj]=0;
//            }
//        for (i=0;i<N;i++)
//            for (j=0;j<N;j++)
//                if (ff[i][j])
//                    if (check(size,i,j)) res[size]++;
//    }
//    return 0;
//}

int solve(){
    int i,j;
    for (i=1;i<N;i++)
        for (j=1;j<N;j++)
            if (field[i][j]){
                if (field[i-1][j]>=field[i-1][j-1]&&
                    field[i][j-1]>=field[i-1][j-1])
                    field[i][j]=field[i-1][j-1]+1;
                else field[i][j]=min(field[i-1][j],field[i][j-1])+1;
            }
    return 0;
}

int output(){
    int i,j;
    freopen("range.out","w",stdout);
    for (i=0;i<N;i++){
        for (j=0;j<N;j++){
            //printf("%d",field[i][j]);
            res[field[i][j]]++;
        }
       // printf("\n");

    }

    for (i=2;i<=N;i++){
        for (j=i+1;j<=N;j++) res[i]+=res[j];
        if (res[i]) printf("%d %d\n",i,res[i]);
    }

    return 0;
}

int main(){
    init();
    solve();
    output();
    return 0;
}
