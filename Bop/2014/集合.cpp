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
#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl
#define FR(i,a,b) for(int i=(a);i<(b);++i)//[a,b)
#define CLR(a,x) memset(a,x,sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0x80
#define MP(A,B) make_pair(A,B)
#define PB(A) push_back(A)
#define PAU system("pause")
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(n) (n^(n-1))&n
#define fin freopen(".in","r",stdin)
#define fout freopen(".out","w",stdout)
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

int f[1050000];

int main() {
    //fin; fout;
    int i, j;
    int n, m;
    int cnt;
    //scanf("%d", &n);
    for (n = 1; n <= 20; ++n) {
    cnt = 0;
    for (i = 0; i < (1<<n); ++i) {
      f[i] = 0;
      for (j = 0; j < n; ++j)
        if ((i & (1<<j)) != 0) {
          f[i] ^= (j+1);
          //dump(i); dump(j);
        }
    }
    //out(f, 1<<n);
    for (i = 0; i < (1<<n); ++i)
      for (j = 0; j < (1<<n); ++j)
        if ((i & j) == 0 && f[i] <= f[j]) cnt++;
    cout << cnt << ' ';
    }
    cout << endl;
    return 0;
}
