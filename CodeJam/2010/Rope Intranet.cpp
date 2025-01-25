#include<iostream>
using namespace std;
int main()
{
    int T,N,A[1000],B[1000];
    
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    scanf("%d",&T);
    for (int cases=0;cases<T;cases++)
    {
        scanf("%d",&N);
        for (int i=0;i<N;i++) scanf("%d%d",&A[i],&B[i]);
        int sum=0;
        for (int i=0;i<N-1;i++)
           for (int j=i+1;j<N;j++)
               if ((A[i]-A[j])*(B[i]-B[j])<0) sum++;
        printf("Case #%d: %d\n",cases+1,sum);
                   
        
    }
    return 0;
}
