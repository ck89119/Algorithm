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
const int MAXN=200005;
const int MAXM=9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;
const int CHILD_NUM = 26;
const int MOD = 1000000007;

int f[MAXN];
map<string, int> m;

int find(int x) {
  int t = x;
  while (f[t] != t) t = f[t];
  
  while (f[x] != x) {
    int tmp = x;
    x = f[x];
    f[x] = t;
  }
  return t; 
}

int uni(int x, int y) {
  f[find(x)] = f[find(y)];
  return 0;
}

int main() {
  //fin; fout;
  int n, k;
  for (int i = 0; i < MAXN; ++i) f[i] = i;
  m.clear();
  //scanf("%d", &n);
  cin >> n; k = 1;
  for (int i = 0; i < n; ++i) {
    int op;
    int x, y;
    string name1, name2;
    cin >> op >> name1 >> name2;
    if (m.count(name1) == 0) m[name1] = k++;
    if (m.count(name2) == 0) m[name2] = k++;
    x = m[name1]; y = m[name2];
    if (op == 0) uni(x, y);
    //else {
      //if (find(x) == find(y)) cout << "yes" << endl;
      //else cout << "no" << endl;
    //}
    else cout << (find(x) == find(y) ? "yes" : "no") << endl;
  } 
  return 0;
}
