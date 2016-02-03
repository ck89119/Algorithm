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
#include <ctime>
using namespace std;
#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl
#define FR(i,a,b) for(int i=(a);i<(b);++i)//[a,b)
#define CLR(a,x) memset(a,x,sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0x80
#define MP(A,B) make_pair(A,B)
#define PB(A) push_back(A)
#define PAU system("pause")
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(x) x & (-x)
#define fin freopen(".in","r",stdin)
#define fout freopen(".out","w",stdout)
//ifstream fin("");
//ofstream fout("");
#define LL long long
#define ULL unsigned long long

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out (vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int MAXN=99999;
const int MAXM=9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;
const int CHILD_NUM = 26;
const int MOD = 1000000007;

typedef pair<int, int> PII;
#define X first
#define Y second

int main() {
  //fin; fout;
  int t;
  cin >> t;
  for (int ncase = 0; ncase < t; ++ncase) {
    map<PII, int> m;
    map<PII, int>::iterator it;
    pair<PII, PII> seg[4];
    int flag = 1;
    for (int i = 0; i < 4; ++i) {
      int x, y;
      pair<PII, PII> t;
      cin >> x >> y;
      t.X = MP(x, y);
      m[MP(x, y)]++;
      cin >> x >> y;
      t.Y = MP(x, y);
      m[MP(x, y)]++;
      seg[i] = t;
    }
    if (m.size() != 4) flag = 0;
    for (it = m.begin(); it != m.end(); ++it) {
      if (it->Y != 2) {
        flag = 0;
        break;
      }
      int x = it->X.X;
      int y = it->X.Y;
      int x1, y1, x2, y2;
      int i;
      for (i = 0; i < 4; ++i)
        if (x == seg[i].X.X && y == seg[i].X.Y) {
          x1 = seg[i].Y.X - x;
          y1 = seg[i].Y.Y - y;
          break;
        } else if (x == seg[i].Y.X && y == seg[i].Y.Y) {
            x1 = seg[i].X.X - x;
            y1 = seg[i].X.Y - y;
            break;
        }
      ++i;
      for (; i < 4; ++i)
        if (x == seg[i].X.X && y == seg[i].X.Y) {
          x2 = seg[i].Y.X - x;
          y2 = seg[i].Y.Y - y;
          break;
        } else if (x == seg[i].Y.X && y == seg[i].Y.Y) {
            x2 = seg[i].X.X - x;
            y2 = seg[i].X.Y - y;
            break;
        }
      if (x1 == 0 && y1 == 0 || x2 == 0 && y2 == 0) flag = 0;
      if (x1*x2 + y1*y2 != 0) flag = 0;
    }
    cout << (flag ? "YES" : "NO") << endl;
  
  }
  return 0;
}
