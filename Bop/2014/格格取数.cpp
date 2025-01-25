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
#define fin freopen("in.txt","r",stdin)
#define fout freopen("out.txt","w",stdout)
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

struct Node {
  int x, y;
  int v;
};
int n, m;
vector<Node> arr, brr;
int sx[105], sy[105];
int covered;
int sum;

int cmp_less(const Node &a, const Node &b) {
  return a.v < b.v;
}

int cmp_more(const Node &a, const Node &b) {
  return a.v > b.v;
}

int add_node(int x, int y) {
  if (0 == sx[x]) covered++;
  if (0 == sy[y]) covered++;
  sx[x]++; sy[y]++;
  return 0;
}

int del_node(int x, int y, int v) {
  if (sx[x] > 1 && sy[y] > 1) {
    sx[x]--; sy[y]--;
  }
  else {
    sum += v;
  }
  return 0;
}

int main() {
    //fin; fout;
    int t, c;
    int i, j;
    cin >> t;
    for (c = 1; c <= t; ++c) {
      cin >> m >> n;
      arr.clear(); brr.clear();
      for (i = 0; i < m; ++i)
        for (j = 0; j < n; ++j) {
          Node tmp;
          cin >> tmp.v;
          tmp.x = i;
          tmp.y = j;
          arr.PB(tmp);
        }
      sort(arr.begin(), arr.end(), cmp_less);
      covered = 0; i = 0;
      CLR(sx, 0); CLR(sy, 0);
      while (covered < m + n) {
        add_node(arr[i].x, arr[i].y);
        brr.PB(arr[i++]);
      }

      sum = 0;
      sort(brr.begin(), brr.end(), cmp_more);
      for (i = 0; i < brr.size(); ++i) {
        //dump(brr[i].x); dump(brr[i].y); dump(brr[i].v);
        del_node(brr[i].x, brr[i].y, brr[i].v);
      }

      cout << "Case " << c << ": " << sum << endl;
    }
    return 0;
}
