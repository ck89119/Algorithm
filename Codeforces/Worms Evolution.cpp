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
    int n,len[105];
    int i,j,k,ansi,ansj,ansk;
    bool f=false;
    scanf("%d",&n);
    for (i=0;i<n;i++) scanf("%d",&len[i]);
    for (i=0;i<n&&!f;i++)
       for (j=0;j<n&&!f;j++)
          for (k=j+1;k<n&&!f;k++)
          {
              if (len[i]==len[j]+len[k]) {f=true;ansi=i;ansj=j;ansk=k;}
          }
    if (f) printf("%d %d %d\n",ansi+1,ansj+1,ansk+1);
    else printf("-1\n");
    return 0;
}
