/*
ID: ck891191
PROG:
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
using namespace std;
#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl;
#define FR(i,a,b) for(int i=(a);i<(b);++i)//[a,b)
#define CL(a,x) memset(a,x,sizeof(a))
#define MP(A,B) make_pair(A,B)
#define two(X) (1<<(X))
#define towL(X) (((int64)(1))<<(x))
#define contain(S,X) ((S&two(X))>0)
#define containL(S,X) ((S&twoL(X))>0)
#define lowbit(x) ((x)&(-(x)))
//freopen("","r",stdin);
//freopen("","w",stdout);
const long long MAXN=(1LL<<62);
const int INF=(1<<30);
const double PI=acos(-1.0);
const double EPS=1e-11;
int t;
char s1[50000+5],s2[50000+5];

int main(){
    int i,j,k;
    scanf("%d",&t);
    for (k=1;k<=t;k++){
        int res,l1,l2;
        res=INF;
        getchar();
        scanf("%s",s1);
        scanf("%s",s2);
        l1=strlen(s1);l2=strlen(s2);
        for (i=0;i<=l1-l2;i++){
            int tot=0;
            for (j=0;j<l2;j++){
                if (s1[i+j]!=s2[j]) tot++;
                if (tot>=res) break;
            }
            if (tot<res) res=tot;
        }
        printf("Case #%d: %d\n",k,res);
    }



    return 0;
}
