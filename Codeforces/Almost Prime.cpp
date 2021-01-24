#include<iostream>
#include<cstdio>
using namespace std;

int ff(int n)
{
    int div_num=0,i;
    for (i=2;;i++)
    {
        if (n==1||div_num>2) break;
        if (n%i==0) 
        {
            div_num++;
            while (n%i==0) n/=i;
        }
    }
    if (div_num==2) return 1;
    else return 0; 
}

int main()
{
    int n;
    int i,ret=0;
    scanf("%d",&n);
    for (i=1;i<=n;i++) 
        if (ff(i)) ret++;
        
    printf("%d\n",ret);
    
    
    return 0;
}
