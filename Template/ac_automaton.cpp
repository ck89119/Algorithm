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
const int MAXN = 500000 + 5;
const int MAXM=9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;
const int CHILD_NUM = 26;

struct Ac_automaton {
  int next[MAXN][CHILD_NUM], fail[MAXN];
  int end[MAXN];
  int size, root;
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

  int insert(char *s) {
    int cur = root;
    while (*s) {
      if (next[cur][*s-'a'] == -1) {
        next[cur][*s-'a'] = newNode();
      }
      cur = next[cur][*s-'a'];
      ++s;
    }
    ++end[cur];
    //dump(cur);
    return 0;
  }

  int build() {
    queue<int> q;
    fail[root] = root;
    for (int i = 0; i < CHILD_NUM; ++i)
      if (next[root][i] != -1) {
        fail[next[root][i]] = root;
        q.push(next[root][i]);
      } else {
        next[root][i] = root;
      }
    
    while (!q.empty()) {
      int cur = q.front(); q.pop();
      //end[cur] |= end[fail[cur]];
      for (int i = 0; i < CHILD_NUM; ++i) {
        if (next[cur][i] == -1) {
          next[cur][i] = next[fail[cur]][i];
        } else {
          fail[next[cur][i]] = next[fail[cur]][i];
          q.push(next[cur][i]);
        }
      }
    }
    return 0;
  }

  int work(char *s) {
    int ans = 0;
    int cur = root;
    while (*s) {
      //dump(*s); dump(cur);
      int v = next[cur][*s-'a'];
      cur = v;
      while (v) {
        ans += end[v];
        end[v] = 0;
        v = fail[v];
      }
      ++s;
    }
    return ans;
  }

  int debug() {
    for(int i = 0; i < size; i++) {
      printf("id = %3d,fail = %3d,end = %3d,chi = [", i, fail[i], end[i]);
      for(int j = 0; j < 26; j++)
        printf("%2d", next[i][j]);
      printf("]\n");
    }
    return 0;
  }
};
Ac_automaton ac;

int main() {
  //fin; fout;
  
  int T;
  scanf("%d", &T);
  while (T--) {
    ac.init();
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      char s[55];
      scanf("%s", s);
      ac.insert(s);
    }
    ac.build();
    //ac.debug();
    char str[1000005];
    scanf("%s", str);
    printf("%d\n", ac.work(str));
  }

  return 0;
}
