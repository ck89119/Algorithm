#include<iostream>
#include<cstdio>
using namespace std;
#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl;

int main()
{
    int m,t,u,f,d;
    int i,ret=0;
    scanf("%d%d%d%d%d",&m,&t,&u,&f,&d);
    for (i=0;i<t;i++)
    {
        char c;
        scanf("\n%c",&c);dump(c);
        if (c=='f') m=m-f-f;
        else  m=m-d-u;
        ret++;
        if (m<0) {ret--;break;}
    }
    printf("%d\n",ret);system("pause");
    return 0;
}
