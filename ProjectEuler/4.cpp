#include<iostream>
#include<vector>
using namespace std;

int isP(int a)
{
    vector <int> num;
    int tmp,i,j;
    while (a!=0) 
    {
          tmp=a%10;
          num.push_back(tmp);
          a/=10;
    }
    i=0;j=num.size()-1;
    while (i<=j)
    {
          if (num[i]!=num[j]) return 0;
          i++;j--;
    }
    return 1;
}

int main()
{
    int max=100*100;
    int i,j;
    for (i=100;i<1000;i++)
       for (j=100;j<1000;j++)
       {
           if (i*j>max&&isP(i*j)) max=i*j;
       }
    printf("%d\n",max);system("pause");
    
    return 0;
}
