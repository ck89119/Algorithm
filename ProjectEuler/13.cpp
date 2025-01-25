#include<iostream>
using namespace std;
#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl;
int main()
{
    __int64 ret=0,tmp=0;
    char c,ss[100];
    int i,j;
    for (i=0;i<100;i++)
    {
        tmp=0;
        for (j=0;j<12;j++)
        {
            scanf("%c",&c);//dump(c);system("pause");
            tmp=tmp*10+c-'0';//
        }
        ret+=tmp;dump(ret);
        gets(ss);
    }
    printf("%I64d\n",ret);
    system("pause");
    return 0;
}
