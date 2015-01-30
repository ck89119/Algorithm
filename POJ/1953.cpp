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
    int fibo[50],n;
    int i,t;
    fibo[0]=1;fibo[1]=2;
    for (i=2;i<50;i++) fibo[i]=fibo[i-1]+fibo[i-2];
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        scanf("%d",&t);
        printf("Scenario #%d:\n",i);
        printf("%d\n\n",fibo[t]);
    }
    
    
    return 0;
}
