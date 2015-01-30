/*
ID: ck891191
PROG: transform
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl;
int eq(const int a[15][15],const int b[15][15],int n)
{
    int i,j,flag=1;
    for (i=0;i<n;i++)
        for (j=0;j<n;j++)
        {
             if (a[i][j]!=b[i][j]) flag=0;
        }
    return flag;
}

int func1(int pat[15][15],int n)
{
    int tmp[15][15],i,j;
    for (i=0;i<n;i++)
        for(j=0;j<n;j++)
            tmp[j][n-i-1]=pat[i][j];
    for (i=0;i<n;i++)
        for(j=0;j<n;j++) pat[i][j]=tmp[i][j];
    return 0;
}

int func2(int pat[15][15],int n)
{
    int tmp[15][15],i,j;
    for (i=0;i<n;i++)
        for(j=0;j<n;j++)
            tmp[n-i-1][n-j-1]=pat[i][j];
    for (i=0;i<n;i++)
        for(j=0;j<n;j++) pat[i][j]=tmp[i][j];
    return 0;
}

int func3(int pat[15][15],int n)
{
    int tmp[15][15],i,j;
    for (i=0;i<n;i++)
        for(j=0;j<n;j++)
            tmp[n-j-1][i]=pat[i][j];
    for (i=0;i<n;i++)
        for(j=0;j<n;j++) pat[i][j]=tmp[i][j];
    return 0;
}

int func4(int pat[15][15],int n)
{
    int tmp[15][15],i,j;
    for (i=0;i<n;i++)
        for (j=0;j<n;j++)
            tmp[i][n-1-j]=pat[i][j];
    for (i=0;i<n;i++)
        for(j=0;j<n;j++) pat[i][j]=tmp[i][j];
    return 0;
}

int main()
{
    int bef[15][15],aft[15][15],tpat[15][15];
    char tmp[15];
    int n;
    int i,j;
    freopen("transform.in","r",stdin);
    freopen("transform.out","w",stdout);
    scanf("%d",&n);
    memset(bef,0,sizeof(bef));
    memset(aft,0,sizeof(aft));
    for (i=0;i<n;i++)
    {
        scanf("%s",tmp);
        for (j=0;j<n;j++)
            if (tmp[j]=='@') bef[i][j]=1;
            else bef[i][j]=0;
    }
    for (i=0;i<n;i++)
    {
        scanf("%s",tmp);
        for (j=0;j<n;j++)
            if (tmp[j]=='@') aft[i][j]=1;
            else aft[i][j]=0;
    }
//    for (i=0;i<n;i++){
//        for (j=0;j<n;j++) cout<<bef[i][j];
//        cout<<endl;
//    }
//    for (i=0;i<n;i++){
//        for (j=0;j<n;j++) cout<<aft[i][j];
//        cout<<endl;
//    }
    //1
    for (i=0;i<n;i++)
        for (j=0;j<n;j++)
            tpat[i][j]=bef[i][j];
//    for (i=0;i<n;i++){
//        for (j=0;j<n;j++) cout<<tpat[i][j];
//        cout<<endl;
//    }
    func1(tpat,n);
//    for (i=0;i<n;i++){
//        for (j=0;j<n;j++) cout<<tpat[i][j];
//        cout<<endl;
//    }
    if (eq(tpat,aft,n))
    {
        printf("1\n");
        return 0;
    }
    //2
    for (i=0;i<n;i++)
        for (j=0;j<n;j++)
            tpat[i][j]=bef[i][j];
    func2(tpat,n);
    if (eq(tpat,aft,n))
    {
        printf("2\n");
        return 0;
    }
    //3
    for (i=0;i<n;i++)
        for (j=0;j<n;j++)
            tpat[i][j]=bef[i][j];
    func3(tpat,n);
    if (eq(tpat,aft,n))
    {
        printf("3\n");
        return 0;
    }
    //4
    for (i=0;i<n;i++)
        for (j=0;j<n;j++)
            tpat[i][j]=bef[i][j];
    func4(tpat,n);
    if (eq(tpat,aft,n))
    {
        printf("4\n");
        return 0;
    }
    //5.1
    for (i=0;i<n;i++)
        for (j=0;j<n;j++)
            tpat[i][j]=bef[i][j];
    func4(tpat,n);
    func1(tpat,n);
    if (eq(tpat,aft,n))
    {
        printf("5\n");
        return 0;
    }
    //5.2
    for (i=0;i<n;i++)
        for (j=0;j<n;j++)
            tpat[i][j]=bef[i][j];
    func4(tpat,n);
    func2(tpat,n);
    if (eq(tpat,aft,n))
    {
        printf("5\n");
        return 0;
    }
    //5.3
    for (i=0;i<n;i++)
        for (j=0;j<n;j++)
            tpat[i][j]=bef[i][j];
    func4(tpat,n);
    func3(tpat,n);
    if (eq(tpat,aft,n))
    {
        printf("5\n");
        return 0;
    }
    //6
    if (eq(bef,aft,n))
    {
        printf("6\n");
        return 0;
    }
    printf("7\n");
    return 0;
}
