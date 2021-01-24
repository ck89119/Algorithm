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
const int MAXN=50000 + 5;
const int MAXM=9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;
const int CHILD_NUM = 128; 

char word[1005][55];
char str[2000005];
int cnt[1005];

struct Trie {
  int next[MAXN][CHILD_NUM], fail[MAXN], end[MAXN];
  int root, size;

  int newNode() {
    CLR(next[size], -1);
    end[size] = 0;
    return size++;
  }

  int init() {
    size = 0;
    root = newNode();
    return 0;
  }

  int insert(char *s, int id) {
    int cur = root;
    while (*s) {
      if (next[cur][*s] == -1) next[cur][*s] = newNode();
      cur = next[cur][*s];
      ++s;
    }
    end[cur] = id;
    return 0;
  }
  
  int build() {
    queue<int> q;
    fail[root] = root;
    for (int i = 0; i < CHILD_NUM; ++i)
      if (next[root][i] == -1) {
        next[root][i] = root;
      } else {
        fail[next[root][i]] = root;
        q.push(next[root][i]);
      }

    while (!q.empty()) {
      int cur = q.front(); q.pop();
      for (int i = 0; i < CHILD_NUM; ++i)
        if (next[cur][i] == -1) {
          next[cur][i] = next[fail[cur]][i];
        } else {
          fail[next[cur][i]] = next[fail[cur]][i];
          q.push(next[cur][i]);
        }
    }
    return 0;
  }
  
  int work(char *s) {
    int cur = root;
    while (*s) {
      int v = next[cur][*s];
      cur = v;
      while (v != root) {
        if (end[v]) {
          ++cnt[end[v]];
        }
        v = fail[v];
      }
      ++s;
    }
    return 0;
  }

};
Trie ac;

int main() {
  //fin; fout;
  int n;
  while (~scanf("%d", &n)) {
    ac.init();
    for (int i = 1; i <= n; ++i) {
      scanf("%s", word[i]);
      ac.insert(word[i], i);
    }
    ac.build();
    scanf("%s", str);
    CLR(cnt, 0);
    ac.work(str);
    for (int i = 1; i <= n; ++i)
      if (cnt[i]) {
        printf("%s: %d\n", word[i], cnt[i]);
      }
  }
  return 0;
}
