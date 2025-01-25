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
#define dump(x) cerr<<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl;
#define FR(i,a,b) for(int i=(a);i<(b);++i)//[a,b)
#define CL(a,x) memset(a,x,sizeof(a))
#define MP(A,B) make_pair(A,B)
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

int t,n,m,k;
long long res;

inline int swap(int &a, int &b){
    int t;
    t=a;a=b;b=t;
    return 0;
}

int input(){
    scanf("%d%d%d",&n,&m,&k);
    if (n<m) swap(n,m);
    res=0;
    return 0;
}

int solve(){
    int t;
    int i,j,r,q,p;
    for (p=2;p<=m;p++){
        long long ans=0;
        long long ans1,ans2;
        q=k/p;
        if (q>n) continue;
        t=(p-1)*p/2;
        ans+=(q-1)*q/2*t;
        r=k-q*p;
        ans1=ans2=0;
        if (q<n)
            for (i=0;i<r;i++)
                ans1+=i*q;
        if (r<=q&&p<m)
            for (i=0;i<r;i++)
                ans2+=i*p;
        ans+=max(ans1,ans2);
        if (ans>res) res=ans;
    }
    return 0;
}

int main(){
    scanf("%d",&t);
    FR(i,0,t){
        input();
        solve();
        cout<<"Case #"<<i+1<<": "<<res<<endl;
    }
    return 0;
}
