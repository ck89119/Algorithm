/*
ID: ck891191
PROG: nocows
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define dump(x) cout <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl;
int f[205][105],n,k;
int init(){
    freopen("nocows.in","r",stdin);
    freopen("nocows.out","w",stdout);
    scanf("%d%d",&n,&k);
    memset(f,0,sizeof(f));
    return 0;
}

int output(){
    int i,j;
    for (i=1;i<=n;i+=2){
        for (j=1;j<=k;j++) cout<<f[i][j]<<' ';
        cout<<endl;
    }
    cout<<endl;
    return 0;
}
int solve(){
    int i,j,l;
    for (i=1;i<=n;i++) f[1][i]=1;
    for (i=3;i<=n;i+=2)
        for (j=1;j<=k;j++)
            for (l=1;l<i;l+=2){
                f[i][j]+=(f[l][j-1]*f[i-l-1][j-1]);
                f[i][j]%=9901;
                //output();
            }
    return 0;
}
//int maxh(int n){
//    return (n+1)/2;
//}
//
//int minh(int n){
//    int ret=1;
//    while (n+1>(1<<ret)) ret++;
//    return ret;
//}
//
//int maxn(int h){
//    return ((1<<h)-1);
//}
//
//int minn(int h){
//    return 2*h-1;
//}
//
//int solve(){
//    int i,j,ii,jj,sum1,sum2,sum3;
//    for (i=3;i<=n;i+=2){
//       // dump(i);dump(minh(i));dump(maxh(i));
//        for (j=minh(i);j<=maxh(i);j++){
//            sum1=0;sum2=0;
//            //dump(j);dump(minn(j-1));dump(maxn(j-1));
//            for (ii=minn(j-1);ii<=i-2;ii+=2){
//                sum3=0;
//                for (jj=1;jj<=j-1;jj++) sum3+=f[i-ii-1][jj];
//                //dump(sum3);
//                sum1+=((f[ii][j-1]%9901)*(sum3%9901))%9901;
//            }
//            sum2=(f[(i-1)/2][j-1]%9901)*(f[(i-1)/2][j-1]%9901)%9901;
//            //dump(sum1);dump(sum2);
//            f[i][j]=(sum1*2-sum2)%9901;
//        }
//    }
//    for (i=1;i<=n;i+=2){
//        for (j=1;j<=k;j++) cout<<f[i][j]<<' ';
//        cout<<endl;
//    }
//
//    return 0;
//}
//int solve(){
//    int i,j,ii,jj,sum1,sum2,sum3;
//    for (i=3;i<=n;i+=2){
//       // dump(i);dump(minh(i));dump(maxh(i));
//        for (j=1;j<=k;j++){
//            sum1=0;sum2=0;
//           // dump(j);dump(minn(j-1));dump(maxn(j-1));
//            for (ii=1;ii<=i-2;ii+=2){
//                sum3=0;
//                for (jj=1;jj<=j-1;jj++) sum3+=f[i-ii-1][jj];
//                //dump(sum3);
//                sum1+=f[ii][j-1]*sum3;
//            }
//            sum2=f[(i-1)/2][j-1]*f[(i-1)/2][j-1];
//           // dump(sum1);dump(sum2);
//            f[i][j]=(sum1*2-sum2)%9901;
//        }
//    }
//    for (i=1;i<=n;i+=2){
//        for (j=1;j<=k;j++) cout<<f[i][j]<<' ';
//        cout<<endl;
//    }
//
//    return 0;
//}
int print(){
    printf("%d\n",(f[n][k]-f[n][k-1]+9901)%9901);
}

int main(){
    init();
    solve();
    print();
    return 0;
}
