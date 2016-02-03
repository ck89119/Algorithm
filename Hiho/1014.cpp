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
const int MAXN=1000005;
const int MAXM=9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;
const int CHILD_NUM = 26;
const int MOD = 1000000007;

struct Trie {
  int next[MAXN][26];
  int cnt[MAXN];
  int root, size;

  int build() {
    CLR(next, -1);
    CLR(cnt, 0);
    root = 0; size = 1;
    return 0;
  }

  int insert(char *s) {
    int cur = root;
    while (*s) {
      cnt[cur]++;
      if (next[cur][*s-'a'] == -1) {
        next[cur][*s-'a'] = size++;
      }
      cur = next[cur][*s-'a'];
      s++;
    }
    cnt[cur]++;
    return 0;
  }
  
  int query(char *s) {
    int cur = root;
    while (*s) {
      if (next[cur][*s-'a'] == -1) return 0;
      cur = next[cur][*s-'a'];
      s++;
    }
    return cnt[cur];
  }
  
};
Trie trie;

int main() {
  //fin; fout;
  int n, m;
  trie.build();
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    char s[20];
    scanf("%s", s);
    trie.insert(s);
  }
  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    char s[20];
    scanf("%s", s);
    printf("%d\n", trie.query(s));
  }
  return 0;
}
