/*
ID: ck89119
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
#define CLR(a,x) memset(a,x,sizeof(a))
#define MP(A,B) make_pair(A,B)
#define PAU system("pause");
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(n) (n^(n-1))&n
#define fin freopen("in.txt","r",stdin);
#define fout freopen("out.txt","w",stdout);
//ifstream fin("");
//ofstream fout("");

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out (vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int MAXN=99999;
const int INF=(1<<30);
const double PI=acos(-1.0);
const double EPS=1e-11;

int a, b, c, d;
int p, q;

int gcd(int p, int q) {
    if (q == 0) return p;
    else return gcd(q, p%q);
}

int main(){
    scanf("%d%d%d%d", &a, &b, &c, &d);
    if (c*b > d*a) {
        int p = c*b-d*a;
        int q = c*b;
        int d = gcd(p, q);
        if (p) printf("%d/%d", p/d, q/d);
        else printf("%d/%d", 0, 1);
    }
    else {
        int p = d*a-c*b;
        int q = d*a;
        int d = gcd(p, q);
        if (p) printf("%d/%d", p/d, q/d);
        else printf("%d/%d", 0, 1);
    }
    return 0;
}
