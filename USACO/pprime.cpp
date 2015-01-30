/*
ID: ck891191
PROG: pprime
LANG: C++
*/
#include <iostream>
#include <cstdio>
using namespace std;
int a,b;
int init()
{
    freopen("pprime.in","r",stdin);
    freopen("pprime.out","w",stdout);
    scanf("%d%d",&a,&b);
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
    int d1,d2,d3,d4,palindrome;
    int ret[1000];
    int i;
    ret[0]=0;
    for (d1 = 1; d1 <= 9; d1+=2) {
        palindrome = d1;
        if (prime(palindrome)) {ret[0]++;ret[ret[0]]=palindrome;}
    }

    for (d1 = 1; d1 <= 9; d1+=2) {
        palindrome = d1*10+d1;
        if (prime(palindrome)) {ret[0]++;ret[ret[0]]=palindrome;}
    }

    for (d1 = 1; d1 <= 9; d1+=2) {
        for (d2 = 0; d2 <= 9; d2++) {
            palindrome = 100*d1 + 10*d2 + d1;
            if (prime(palindrome)) {ret[0]++;ret[ret[0]]=palindrome;}
        }
    }

    for (d1 = 1; d1 <= 9; d1+=2) {
        for (d2 = 0; d2 <= 9; d2++) {
            palindrome = 1000*d1 + 100*d2 + 10*d2 + d1;
            if (prime(palindrome)) {ret[0]++;ret[ret[0]]=palindrome;}
        }
    }

    for (d1 = 1; d1 <= 9; d1+=2) {
        for (d2 = 0; d2 <= 9; d2++) {
            for (d3 = 0; d3 <= 9; d3++) {
                palindrome = 10000*d1 + 1000*d2 +100*d3 + 10*d2 + d1;
                if (prime(palindrome)) {ret[0]++;ret[ret[0]]=palindrome;}
            }
        }
    }

    for (d1 = 1; d1 <= 9; d1+=2) {
        for (d2 = 0; d2 <= 9; d2++) {
            for (d3 = 0; d3 <= 9; d3++) {
                palindrome = 100000*d1 + 10000*d2 + 1000*d3 +100*d3 + 10*d2 + d1;
                if (prime(palindrome)) {ret[0]++;ret[ret[0]]=palindrome;}
            }
        }
    }

    for (d1 = 1; d1 <= 9; d1+=2) {
        for (d2 = 0; d2 <= 9; d2++) {
            for (d3 = 0; d3 <= 9; d3++) {
                for (d4 = 0; d4 <= 9; d4++) {
                    palindrome = 1000000*d1 + 100000*d2 + 10000*d3 + 1000*d4 +100*d3 + 10*d2 + d1;
                    if (prime(palindrome)) {ret[0]++;ret[ret[0]]=palindrome;}
                }
            }
        }
    }

    for (d1 = 1; d1 <= 9; d1+=2) {
        for (d2 = 0; d2 <= 9; d2++) {
            for (d3 = 0; d3 <= 9; d3++) {
                for (d4 = 0; d4 <= 9; d4++) {
                    palindrome =10000000*d1 + 1000000*d2 + 100000*d3 + 10000*d4 + 1000*d4 +100*d3 + 10*d2 + d1;
                    if (prime(palindrome)) {ret[0]++;ret[ret[0]]=palindrome;}
                }
            }
        }
    }

    for (i=1;i<=ret[0];i++)
        if (ret[i]>=a&&ret[i]<=b){
            printf("%d\n",ret[i]);
        }
    return 0;
}

int main()
{
    init();
    solve();
    return 0;
}

















//#include <iostream>
//#include <cstdio>
//#include <cstring>
//using namespace std;
//#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl;
//int prime[3125005],a,b;
//
//int pal(int n)
//{
////    int s[15],i,j;
////    s[0]=0;
////    while (n!=0)
////    {
////        s[0]++;
////        s[s[0]]=n%10;
////        n/=10;
////    }
////    i=1;j=s[0];
////    while (i<j)
////    {
////        if (s[i]!=s[j]) break;
////        i++;j--;
////    }
////    if (i<j) return 0;
////    else return 1;
//    int i=1;
//    while (i<=n) i*=10;i/=10;
//    while (n!=0)
//    {
//        if ((n%10)!=(n/i)) break;
//        n%=i;
//        n/=10;
//        i/=100;
//    }
//    if (n) return 0;
//    else return 1;
//
//}
//
//int test(int i)
//{
//    int total=0;
//    while(i!=0)
//    {
//        cout<<i%2<<' ';
//        i/=2;total++;
//    }
//    cout<<total<<endl;
//    return 0;
//}
//
//int init()
//{
//    int i,j;
//    freopen("pprime.in","r",stdin);
//    freopen("pprime.out","w",stdout);
//    scanf("%d%d",&a,&b);
//    memset(prime,-1,sizeof(prime));
//    //dump(prime[0]);
//    prime[0]=prime[0]&~(1<<31);
//    //dump(prime[0]);
//    prime[0]=prime[0]&~(1<<30);
//    //dump(prime[0]);
//
//    for (i=2;i<=b/2;i++)
//        if (prime[i/32]&(1<<31-i%32))
//        {
//            //cout<<i;
//            j=i+i;
//            while (j<=b)
//            {
//                prime[j/32]=prime[j/32]&~(1<<31-j%32);
//                //dump(j);
//                //test(prime[j/32]);
//                j+=i;
//            }
//        }
//    //test(prime[0]);
//    return 0;
//}
//
//int solve()
//{
//    int i;
//    for (i=a;i<=b;i++)
//    {
//        if ((prime[i/32]&(1<<31-i%32))&&pal(i)) printf("%d\n",i);
//    }
//    return 0;
//}
//
//int main()
//{
//    init();
//    //solve();
//    return 0;
//}
