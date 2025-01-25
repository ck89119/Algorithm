#include<iostream>
#include<string>
using namespace std;
#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl;
int main()
{
    int max=0,tmp,i;
    string s;
    cin>>s;dump(s);
    for (i=0;i<996;i++)
    {
        tmp=1;
        tmp*=s[i]-'0';
        tmp*=s[i+1]-'0';
        tmp*=s[i+2]-'0';
        tmp*=s[i+3]-'0';
        tmp*=s[i+4]-'0';
        if (tmp>max) max=tmp;
    }
    cout<<max<<endl;system("pause");
    return 0;
}
