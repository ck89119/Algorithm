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

int check(int &a, int &b, int c, int begin) {
  int c2 = c * c;
  //dump(c2);
  for (a = begin; a * a <= c2; ++a)
    for (b = a; b * b <= c2; ++b) {
      //dump(a*a+b*b);
      if (a * a + b * b == c2) return 1;
      if (a * a + b * b > c2) break;
    }
  return 0;
}


int main() {
    //fin fout
    ios :: sync_with_stdio(false);
    cout << fixed << setprecision(16);
    int a, b;
    int w1, h1, w2, h2;
    int i;
    cin >> a >> b;
    if (a > b) swap(a, b);
    h1 = 0;
    while (true) {
      if (check(h1, w1, a, h1+1) == 0) {
        //dump("####1");
        cout << "NO" << endl;
        return 0;
      }

      w2 = b * h1 / a;
      h2 = b * w1 / a;
      if (w2 * w2 + h2 * h2 != b * b) continue;

      if (h1 == h2) continue;


      cout << "YES" << endl;
      cout << "0 0" << endl;
      cout << -w1 << ' ' << h1 << endl;
      cout << w2 << ' ' << h2 << endl;
      break;
    }

    return 0;
}
