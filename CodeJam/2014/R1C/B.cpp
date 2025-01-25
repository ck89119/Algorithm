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
const int CHILD_NUM = 26;
const int MOD = 1000000007;

LL fac[105];
int get_fac() {
  fac[0] = 1;
  for (int i = 1; i < 105; ++i) 
    fac[i] = (fac[i-1] * i) % MOD;
  return 0;
}

string s[105];
int n;
struct Node {
  char s, t;
  LL n;
};
vector<Node> vec, vec2;

int check() {
  int b[26];
  CLR(b, 0);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < s[i].size(); ++j)
      b[s[i][j]0-'a'] = 1;

  for (int i = 0; i < n; ++i)
    for (int j = 1; j < s[i].size()-1; ++j)
      if (b[s[i][j]-'a']) return 0;
  return 1;
}

int main() {
  //fin; fout;
  int T;
  get_fac();
  scanf("%d", &T);
  for (int ncase = 1; ncase <= T; ++ncase) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
      cin >> s[i];
    sort(s, s+n);
    //out(s, n);
      
    for (int i = 0; i+1 < n; ++i)
      if (s[i+1][0] < s[i]
    
    vec.clear();
    for (int i = 0; i < n; ++i) {
      Node a;
      a.s = s[i][0]; a.t = s[i][s[i].size()-1];
      int k = 1;
      while (i+1 < n && s[i+1][s[i+1].size()-1] == a.t) {
        ++i; ++k;
      }
      a.n = fac[k];
      vec.push_back(a);

      cout << a.s << " " << a.t << " " << a.n << endl;
    }

    vec2.clear();
    for (int i = 0; i < vec.size(); ++i) {
      Node a = vec[i];
      while (i+1 < n && vec[i+1].s == a.t) {
        a.n *= vec[i+1].n; a.n %= MOD;
        a.t = vec[i+1].t;
        ++i;
      }
      vec2.push_back(a);
      
      cout << a.s << " " << a.t << " " << a.n << endl;
    }
    

    LL ans = fac[vec2.size()];
    for (int i = 0; i < vec2.size(); ++i)
      ans = (ans * vec2[i].n) % MOD;

    printf("Case #%d: %lld\n", ncase, ans);
  }
  return 0;
}
