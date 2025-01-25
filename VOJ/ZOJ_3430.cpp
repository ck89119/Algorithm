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

template <class T> void Out(T A[],int n){for (int i=0;i<n;i++) printf("%c", A[i]);cout<<endl;}
template <class T> void out (vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int MAXN= 40000 + 5;
const int MAXM=9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;
const int CHILD_NUM = 256;
const int MOD = 1000000007;

struct Trie {
  int next[MAXN][CHILD_NUM], fail[MAXN], end[MAXN];
  int root, size;

  int newNode() {
    CLR(next[size], -1);
    end[size] = -1;
    return size++;
  }

  int init() {
    size = 0;
    root = newNode();
    return 0;
  }

  int insert(unsigned char s[], int len, int id) {
    int cur = root;
    for (int i = 0; i < len; ++i) {
      if (next[cur][s[i]] == -1) next[cur][s[i]] = newNode();
      cur = next[cur][s[i]];
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

  int work(unsigned char s[], int len) {
    int cur = root;
    int ans = 0;
    int vis[520];
    CLR(vis, 0);
    for (int i = 0; i < len; ++i) {
      int v = next[cur][s[i]];
      cur = v;
      while (v != root) {
        if (end[v] != -1) {
          vis[end[v]] = 1;
        }
        v = fail[v];
      }
    }

    for (int i = 0; i < 520; ++i)
      if (vis[i]) ++ans;
    return ans;
  }
};
Trie ac;

int trans(char ch) {
  if (ch >= 'A' && ch <= 'Z') return ch - 'A';
  if (ch >= 'a' && ch <= 'z') return 26 + ch - 'a';
  if (ch >= '0' && ch <= '9') return 52 + ch - '0';
  if (ch == '+') return 62;
  return 63;
}

int decodeBlock(char in[4], int out[3]) {
  int len = 1;
  int d;
  d = trans(in[0]);
  out[0] = d << 2;
  if (in[1] != '=') {
    d = trans(in[1]);
    out[0] += (d >> 4) & 0x3;
    out[1] = d & 0xf;
    out[1] <<= 4;
  }
  if (in[2] != '=') {
    d = trans(in[2]);
    out[1] += (d >> 2) & 0xf;
    out[2] = d & 0x3;
    out[2] <<= 6;
    ++len;
  }
  if (in[3] != '=') {
    d = trans(in[3]);
    out[2] += d;
    ++len;
  }
  return len;
}

int decode(char *s, unsigned char *res) {
  int index = 0;
  for (int i = 0; i < strlen(s); i += 4) {
    char in[4];
    int out[3];
    for (int j = 0; j < 4; ++j) in[j] = s[i+j];
    int len = decodeBlock(in, out);
    for (int j = 0; j < len; ++j) res[index++] = (unsigned char)out[j];
  }
  res[index] = '\0';
  return index;
}

int main() {
  //fin; fout;
  int n, m;
  char s[4000];
  unsigned char ss[4000];
  while(~scanf("%d", &n)) {
    ac.init();
    for (int i = 0; i < n; ++i) {
      scanf("%s", s);
      int len = decode(s, ss);
      ac.insert(ss, len, i);
    }
    ac.build();

    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
      scanf("%s", s);
      int len = decode(s, ss);
      printf("%d\n", ac.work(ss, len));
    }
    printf("\n");
  }

  return 0;
}
