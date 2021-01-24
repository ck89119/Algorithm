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
    int k,a,b;
    string s;
    scanf("%d%d%d",&k,&a,&b);
    cin>>s;
    if (k*a>s.size()||k*b<s.size()) printf("No solution\n");
    else
    {
        int i=0,len=s.size()/k,j;
        for (j=0;j<k-1;j++){
            string tmp(s,i,len);
            cout<<tmp<<endl;
            i+=len;
        }
        string tmp(s,i);
        cout<<tmp<<endl;
    }
    //PAU
    return 0;
}
