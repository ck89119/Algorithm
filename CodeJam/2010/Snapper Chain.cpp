#include<iostream>
using namespace std;
int main()
{   
    freopen("A-large-practice.in","r",stdin);
    freopen("A-large-practice.out","w",stdout);
    int T;
    scanf("%d",&T);
    for (int tcase=0;tcase<T;tcase++)
    {
        int N,K;
        bool f;
        scanf("%d%d",&N,&K);//cout<<"N=  "<<N<<endl;
        f=true;
        if (N==0) f=false;
        for (int i=0;i<N&&f;i++)
        {
            if (K%2) K=K>>1;
            else f=false;      // cout<<"K=  "<<K<<endl;
        }
        if (f) printf("Case #%d: ON\n",tcase+1);
        else printf("Case #%d: OFF\n",tcase+1);
    }
    return 0;
}
