#include<iostream>
using namespace std;
#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl;
int col[1000000]={0};

int coll(__int64 i)
{ 
     if (i<1000000)
     {
         if (!col[i]) 
            if (i%2==0) col[i]=coll(i/2)+1;
            else col[i]=coll(3*i+1)+1;
         return col[i];
     }
     else 
     {
         if (i%2==0) return coll(i/2)+1;
         else return coll(3*i+1)+1;
     }
}

int main()
{
    __int64 i,ret=0;
    col[1]=1;
    for (i=2;i<1000000;i++) 
    {
        if (!col[i]) col[i]=coll(i);
        if (col[i]>col[ret]) ret=i; // dump(i);    
    }
    printf("%d\n",ret);system("pause");

}
