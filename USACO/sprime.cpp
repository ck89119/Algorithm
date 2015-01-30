/*
ID: ck891191
PROG: sprime
LANG: C++
*/

#include <iostream>
#include <cstdio>
using namespace std;
#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl;
int N;
//int _prime[10000000];
int q[100],head,tail;
int init()
{
    int i,j;
    freopen("sprime.in","r",stdin);
    freopen("sprime.out","w",stdout);
    scanf("%d",&N);
//    for (i=0;i<10000000;i++) _prime[i]=1;
//    _prime[0]=0;_prime[1]=0;
//    for (i=2;i<5000000;i++)
//        if (_prime[i])
//        {
//            j=i+i;
//            while (j<10000000)
//            {
//                _prime[j]=0;
//                j+=i;
//            }
//        }
    return 0;
}

int mul(int a,int n,int p)
{
    long long c=a%p,ret=1;
    while (n!=0)
    {
        if (n%2) ret=ret*c%p;
        c=c*c%p;
        n/=2;
    }
    return ret;
}

int prime(int n)
{
    if (n==1) return 0;
    if (n==2||n==3||n==5||n==7) return 1;
    if (mul(2,n-1,n)==1&&mul(3,n-1,n)==1&&mul(5,n-1,n)==1&&mul(7,n-1,n)==1) return 1;
    else return 0;
}

int solve()
{
    int m=1,i,l1,l2,t1,t2;
    head=0;tail=0;
    q[tail++]=2;q[tail++]=3;q[tail++]=5;q[tail++]=7;
    l1=head;l2=tail-1;
    while (head<tail)
    {
        int t=q[head++];
        for (i=1;i<=9;i+=2)
        {
//            if (m<=6&&_prime[t*10+i]) q[tail++]=t*10+i;
//            if (m==7&&prime(t*10+i)) q[tail++]=t*10+i;
            if (prime(t*10+i)) q[tail++]=t*10+i;
        }
        if (head>l2)
        {
            l1=head;
            l2=tail-1;
            m++;
            //dump(m);
            if (m>7) break;
        }
        //dump(head);
        //dump(tail);
        //dump(q[tail-1]);
    }
    //dump(tail);
    t1=1;
    for (i=1;i<N;i++) t1*=10;
    t2=t1*10;
    for (i=0;i<tail;i++)
    {
        if (q[i]>t2) break;
        if (q[i]>t1&&q[i]<t2) printf("%d\n",q[i]);
    }
    return 0;
}
int main()
{
    init();
    solve();
    return 0;
}
