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
    int n,m;
    int d[105];
    int i,j,t1,t2;
    scanf("%d%d",&n,&m);
    for (i=1;i<=n;i++) d[i]=0;
    for (i=0;i<m;i++){
        scanf("%d%d",&t1,&t2);
        for (j=t1;j<=t2;j++) d[j]++;
    }
    for (i=1;i<=n;i++){
        if (d[i]!=1) break;
    }
    if (i>n) printf("OK\n");
    else printf("%d %d",i,d[i]);

    
    
    return 0;
}
