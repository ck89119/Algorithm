#include<iostream>
#include<cstdio>
using namespace std;
#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl;
__int64 _num[10010],_numsize=0,_s[10010],_tmp;
__int64 m,n,total=0;

int numinit(__int64 x)
{
    int i;
    for (i=2;i*i<=x;i++)
    {
         if (x%i==0)
         {
              while(x%i==0) x/=i;
              _num[_numsize++]=i;
         }
    }
    if(x!=1)
	{
		_num[_numsize++]=x;
	}

    return 0;
}

__int64 power(__int64 a,__int64 b)
{
    __int64 i,t=1;
    for (i=0;i<b;i++) t*=a;
    return t;
}

int get(__int64 a,__int64 b,__int64 c)
{
    __int64 i,t=m;
    if (b==c)    
    {
         for (i=0;i<c;i++) t/=_s[i];
         _tmp+=power(t,n);
    }
    else 
    {
         for (i=a;i<_numsize;i++)
         {
             _s[b]=_num[i];
             get(i+1,b+1,c);
         }
    }
    return 0;
}

int main()
{
    
    __int64 i;
    scanf("%d%d",&n,&m);
    numinit(m);total=power(m,n);
   // dump(_numsize);
    for (i=1;i<=_numsize;i++)
    {
        _tmp=0;
        get(0,0,i);
        if (i%2) total-=_tmp;
        else total+=_tmp;
    }
    printf("%I64d\n",total);  system("pause");
    return 0;
}
