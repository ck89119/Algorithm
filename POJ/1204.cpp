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
#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl;
#define FR(i,a,b) for(int i=(a);i<(b);++i)//[a,b)
#define CLR(a,x) memset(a,x,sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0x80
#define MP(A,B) make_pair(A,B)
#define PB(A) push_back(A)
#define PAU system("pause");
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(n) (n^(n-1))&n
#define fin freopen(".in","r",stdin);
#define fout freopen(".out","w",stdout);
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

struct Trie {
  int idx;
  char ch;
  struct Trie *next[26];
  Trie(char c) {
    int i;
    idx = -1;
    ch = c;
    for (i = 0; i < 26; ++i)
      next[i] = NULL;
  }
};
Trie *root;
int l, c, w;
char puzzle[1005][1005];
int ans[1005][3];
int vis[1005];
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int travel(Trie *node, string s) {
  int i;
  if (node == NULL) return 0;
  s += node->ch;
  if (node->idx != -1) cout << s << endl; 
  for (i = 0; i < 26; ++i)
     travel(node->next[i], s); 
  return 0;
}

int insert(char *word, Trie *root, int index) {
  int i = 0;
  while (word[i] != '\0') {
    //dump(word[i])
    if (root->next[word[i]-'A'] == NULL) {
      Trie *node = new Trie(word[i]);
      root->next[word[i]-'A'] = node;
    }
    root = root->next[word[i++]-'A'];
  }
  root->idx = index;
  return 0;
}

int search(Trie *node, int x, int y, int tx, int ty, int k) {
  if (node == NULL) return 0;
  int index = node->idx;
  if (index != -1 && !vis[index]) {
    vis[index] = 1;
    ans[index][0] = x;
    ans[index][1] = y;
    ans[index][2] = k;
  }
  if (tx < 0 || tx >= l || ty < 0 || ty >= c) return 0;
  search(node->next[puzzle[tx][ty]-'A'], x, y, tx+dx[k], ty+dy[k], k);
  return 0;
}

int init() {
  int i, j;
  scanf("%d%d%d", &l, &c, &w);
  for (i = 0; i < l; ++i)
    scanf("%s", puzzle[i]);
  root = new Trie('$');
  for (i = 0; i < w; ++i) {
    char word[1005];
    scanf("%s", word);
    //dump(word)
    insert(word, root, i);
  }
  //travel(root, "");
  return 0;
}

int solve() {
  int i, j, k;
  CLR(vis, 0);
  for (i = 0; i < l; ++i)
    for (j = 0; j < c; ++j)
      for (k = 0; k < 8; ++k)
        search(root, i, j, i, j, k);
  for (i = 0; i < w; ++i)
    printf("%d %d %c\n", ans[i][0], ans[i][1], ans[i][2]+'A');

  return 0;
}

int main() {
  init();
  solve();
  return 0;
}
