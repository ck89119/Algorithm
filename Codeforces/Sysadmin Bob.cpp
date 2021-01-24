#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <string>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl;
#define PAU system("pause");

int main()
{
    string str;
    vector<string> l;
    bool a,m;
    int beg=0,i,sum=0;
    cin>>str;
    a=false;m=false;//dump(str)
    for (i=0;i<str.size();i++) if (str[i]=='@') sum++;
    for (i=0;i<str.size();i++)
    {
        //dump(str[i])dump(a)dump(m)
        if (str[i]=='@'&&!m&&a) {m=true;sum--;continue;}
        else if (str[i]=='@') break;
        if (!a) a=true;
        else  if (m) 
        {
              string tmp;
              if (sum) tmp=str.substr(beg,i-beg+1);
              else  tmp=str.substr(beg);
              l.push_back(tmp);//dump(tmp)
              beg=i+1;m=false;a=false;
        }
    }
    if (i<str.size()) printf("No solution\n");
    else if (i==str.size()&&m) printf("No solution\n");
    else if (l.size()==0) printf("No solution\n");
    else 
    {
         for (i=0;i<l.size()-1;i++) cout<<l[i]<<',';
         cout<<l[l.size()-1]<<endl;
    }
    //PAU
    return 0;
}
