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
    int n,l,len[105];
    int maxl=0,i,j,ans=0;
    scanf("%d%d",&n,&l);
    for (i=0;i<n;i++)
    {
        scanf("%d",&len[i]);
        if (len[i]>maxl) maxl=len[i];
    }
    for (i=l;i<=maxl;i++)
    {
        int tmp=0;
        for (j=0;j<n;j++) tmp+=i*(len[j]/i);
        if (tmp>ans) ans=tmp;
    }
    printf("%d\n",ans);
    //PAU
    return 0;
}
