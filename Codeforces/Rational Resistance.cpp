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
#define dump(x) cout <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl;
#define FR(i,a,b) for(int i=(a);i<(b);++i)//[a,b)
#define CLR(a,x) memset(a,x,sizeof(a))
#define MP(A,B) make_pair(A,B)
#define PB(A) push_back(A)
#define PAU system("pause");
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(n) (n^(n-1))&n
#define fin freopen("in.txt","r",stdin);
#define fout freopen("out.txt","w",stdout);
//ifstream fin("");
//ofstream fout("");
#define LL long long

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out (vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int MAXN=99999;
const int MAXM=9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;

LL x, y;

LL gcd(LL a, LL b) {
    if (b == 0) return a;
    else return gcd(b, a%b);
}

LL rec(LL a, LL b) {
    //dump(a) dump(b)
    if (a == b) return 1;
    if (a > b) {
        //LL d = gcd(a, b);
        //a /= d; b /= d;
        if (b == 1) return a;
        return rec(a%b, b) + a/b;
    }
    if (a < b) {
        //LL d = gcd(a, b);
        //a / = d; b /= d;
        if (a == 1) return b;
        return rec(a, b%a) + b/a;
    }
}

int main() {
    //fin fout
    cin >> x >> y;
    cout << rec(x, y) << endl;
    return 0;
}
