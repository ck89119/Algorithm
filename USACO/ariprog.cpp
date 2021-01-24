/*
ID: ck891191
PROG: ariprog
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define dump(x) cout <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl;
int bigsquare[32000],bs[125005];
int n,m,bs_count;
struct ARIPROG
{
    int a,b;
}tmp;
ARIPROG ret[32000];
int ret_size;

int cmp(const ARIPROG &a,const ARIPROG &b)
{
    if (a.b<b.b) return 1;
    else if (a.b>b.b) return 0;
    else if (a.a<b.a) return 1;
    else return 0;
}

int init()
{
    int i,j;
    scanf("%d%d",&n,&m);
    //dump(n);dump(m);
    memset(bs,0,sizeof(bs));
    bs_count=0;
    for (i=0;i<=m;i++)
        for (j=i;j<=m;j++)
            bs[i*i+j*j]=1;
    for (i=0;i<=2*m*m;i++)
        if (bs[i]) bigsquare[bs_count++]=i;
    //dump(bs_count);
    sort(bigsquare,bigsquare+bs_count);
    ret_size=0;
    return 0;
}

//int dfs(int n,int d,int y)
//{
//    int i;
//    //cout<<n<<" "<<d<<" "<<y<<endl;
//    if (n==0)
//    {
//        ret[ret_size].a=tmp.a;
//        ret[ret_size].b=tmp.b;
//        ret_size++;
//        return 0;
//    }
//    if (y>=bs_count) return 0;
//    for (i=y+1;i<bs_count;i++)
//    {
//        //cout<<bigsquare[i]<<' '<<bigsquare[y]<<endl;
//        if (bigsquare[i]-bigsquare[y]>=d) break;
//    }
//
//    if (i>=bs_count||bigsquare[i]-bigsquare[y]>d) return 0;
//    else
//    {
//        dfs(n-1,d,i);
//    }
//    return 0;
//}

int solve()
{
    int i,j,k,flag;
    int d;
    for (i=0;i<bs_count;i++)
        for (j=i+1;j<bs_count;j++)
        {
            //path[0]=2;path[1]=i;path[2]=j;
            d=bigsquare[j]-bigsquare[i];
            //dump(d);
            tmp.a=bigsquare[i];tmp.b=d;
            flag=true;
            for (k=3;k<=n;k++)
                if ((tmp.a+(k-1)*d)>bigsquare[bs_count-1]||!bs[tmp.a+(k-1)*d])
                {
                    flag=false;
                    break;
                }
            if (flag)
            {
                ret[ret_size].a=tmp.a;
                ret[ret_size].b=tmp.b;
                ret_size++;
            }

        }
    //dump(ret_size);
    return 0;
}

int output()
{
    int i;
    if (ret_size==0)
    {
        printf("NONE\n");
        return 0;
    }
    sort(ret,ret+ret_size,cmp);
    for (i=0;i<ret_size;i++)
    {
        if (i!=0&&ret[i].a==ret[i-1].a&&ret[i].b==ret[i-1].b) continue;
        printf("%d %d\n",ret[i].a,ret[i].b);
    }
    return 0;
}

int main()
{
    freopen("ariprog.in","r",stdin);
    freopen("ariprog.out","w",stdout);
    init();
    solve();
    output();
    return 0;
}
