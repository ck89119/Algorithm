/*
ID: ck891191
PROG:
LANG: C++
*/
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
using namespace std;
#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl;
#define FR(i,a,b) for(int i=(a);i<(b);++i)//[a,b)
#define CL(a,x) memset(a,x,sizeof(a))
#define MP(A,B) make_pair(A,B)
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
//freopen("","r",stdin);
//freopen("","w",stdout);
//ifstream fin("");
//ofstream fout("");
const int MAXN=99999;
const int INF=(1<<30);
const double PI=acos(-1.0);
const double EPS=1e-11;

int n;

//int init(){
//    int i,j,cnt;
//    prime[0]=prime[1]=1;
//    for (i=2;i<5000000;i++)
//        if (!prime[i]){
//            j=i+i;
//            while (j<=10000000) {
//                prime[j]=1;
//                j+=i;
//            }
//        }
//    cnt=0;
//    for (i=2;i<=10000000;i++)
//        if (!prime[i]) p[cnt++]=i;
//    printf("%d\n",cnt);
//    return 0;
//}

int main(){
    int i;
    scanf("%d", &n);
    for (i=10000000-n;i<10000000;i++)
        printf("%d ",i);
    printf("\n");
    return 0;
}
