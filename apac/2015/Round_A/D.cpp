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
#define fin freopen("D-large-practice.in","r",stdin)
#define fout freopen("D-large-practice.out","w",stdout)
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

int adjust(pair<int, int> &p) {
  if (p.first > p.second) swap(p.first, p.second);
  return 0;
}

int main() {
  fin; fout;
  int t;
  scanf("%d", &t);
  for (int ncase = 1; ncase <= t; ++ncase) {
    map<pair<int, int>, int> m; 
    int n, mm, s[505];
    int ans = 0;
    scanf("%d%d", &n, &mm);
    for (int i = 0; i < n; ++i)
      scanf("%d", &s[i]);
    sort(s, s+n);
    for (int i = n-1; i >= 0; --i) {
      int l = 1 << s[i];
      pair<int, int> p;
      auto ptr = m.lower_bound(MP(l, l));
      if (ptr == m.end()) {
        ++ans;
        p = pair<int, int>(mm, mm); 
      } else {
        //dump((*ptr).first.first);
        //dump((*ptr).first.second);
        //dump((*ptr).second);

        p = (*ptr).first;
        --(ptr->second);
        if (ptr->second == 0)
          m.erase(ptr);
      }
      pair<int, int> p1, p2;
      p1.first = p.first;
      p1.second = p.second - l;
      p2.first = l;
      p2.second = p.first - l;
      adjust(p1); adjust(p2);
      ++m[p1]; ++m[p2];
    }
    printf("Case #%d: %d\n", ncase, ans);
  }


  return 0;
}
