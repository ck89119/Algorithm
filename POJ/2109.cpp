#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    double p;
    int n;
    while (scanf("%d%lf",&n,&p)!=EOF)
    {
          printf("%d\n",(int)(exp(log(p)/n)+0.5));
    }
    system("pause");
    return 0;
}
