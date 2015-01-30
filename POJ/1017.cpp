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
#include <cstdlib>
using namespace std;
#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl;
#define FR(i,a,b) for(int i=(a);i<(b);++i)//[a,b)
#define CL(a,x) memset(a,x,sizeof(a))
#define Mp(A,B) make_pair(A,B)
#define two(X) (1<<(X))
#define towL(X) (((int64)(1))<<(x))
#define contain(S,X) ((S&two(X))>0)
#define containL(S,X) ((S&twoL(X))>0)
//freopen("","r",stdin);
//freopen("","w",stdout);
const long long MAXN=(1LL<<62);
const int INF=(1<<30);
const double PI=acos(-1.0);
const double EPS=1e-11;

int num[7];

int main(){
    int i;
    int res;
    while (1){
        num[0]=0;
        for (i=1;i<=6;i++){
            scanf("%d",&num[i]);
            num[0]+=num[i];
        }
        if (!num[0]) break;
        res=0;
        res+=num[6];

        res+=num[5];
        if (num[1]>=num[5]*11) num[1]-=num[5]*11;
        else num[1]=0;

        res+=num[4];
        if (num[2]>=num[4]*5) num[2]-=num[4]*5;
        else {
            if (num[1]>=(num[4]*5-num[2])) num[1]-=(num[4]*5-num[2]);
            else num[1]=0;
            num[2]=0;
        }

        res+=num[3]/4;
        int r=num[3]%4;
        if (r){
            res++;
            if (r==1){
                if (num[2]>=5){
                    num[2]-=5;
                    if (num[1]>=7) num[1]-=7;else num[1]=0;
                }
                else {
                    if (num[1]>=(27-4*num[2])) num[1]-=(27-4*num[2]);
                    else num[1]=0;
                    num[2]=0;
                }
            }
            if (r==2){
                if (num[2]>=3){
                    num[2]-=3;
                    if (num[1]>=6) num[1]-=6;else num[1]=0;
                }
                else {
                    if (num[1]>=(18-4*num[2])) num[1]-=(18-4*num[2]);
                    else num[1]=0;
                    num[2]=0;
                }
            }
            if (r==3){
                if (num[2]>=1){
                    num[2]-=1;
                    if (num[1]>=5) num[1]-=5;else num[1]=0;
                }
                else {
                    if (num[1]>=9) num[1]-=9;else num[1]=0;
                }
            }
        }

        res+=num[2]/9;
        r=num[2]%9;
        if (r){
            res++;
            if (num[1]>=(36-4*r)) num[1]-=(36-4*r);else num[1]=0;
        }

        res+=num[1]/36;
        r=num[1]%36;
        if (r) res++;

        printf("%d\n",res);
    }

    return 0;
}
