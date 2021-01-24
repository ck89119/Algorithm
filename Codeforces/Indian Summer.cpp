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
    map<string,set<string> > m;
    set<string> s;
    int n;
    string a,b;
    int i;
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        cin>>a>>b;
        s=m[a]; 
        set<string>::iterator it;
       // for (it=s.begin();it!=s.end();it++) 
       //   cout<<"***"<<*it<<endl;
        if (s.count(b));
        else {
             s.insert(b);
             m[a]=s;
        }  
       // for (it=s.begin();it!=s.end();it++) 
       //   cout<<"***"<<*it<<endl;    
    }
    int ans=0;
    map<string,set<string> > ::iterator it;
    for (it=m.begin();it!=m.end();it++) ans+=it->second.size();
    printf("%d\n",ans);
    
   // system("pause");
    return 0;
}
