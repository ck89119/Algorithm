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

struct TrieNode {
  int cnt;
  int is_word;
  struct TrieNode *next[26];
  TrieNode(): cnt(1), is_word(0) {
    int i;
    for (i = 0; i < 26; ++i)
      next[i] = NULL;
  }
};
TrieNode t[10000000];
int t_size;
TrieNode *root;

int insert(char *str, TrieNode *node) {
  while (*str) {
    int ord = *str - 'a';
    if (node->next[ord] != NULL) {
      node = node->next[ord];
      ++node->cnt;
    } else {
      node->next[ord] = &t[t_size];
      node = &t[t_size++];
    }
    ++str;
  }
  return 0;
}

int query(char *str) {
  TrieNode *node = root;
  //dump(str);
  while (*str) {
    int ord = *str - 'a';
    if (node->next[ord] == NULL) break;
    ++str;
    node = node->next[ord];
  }
  if (*str) return 0;
  else return node->cnt;
}


int main() {
  //fin; fout;
  char word[15];
  t_size = 0;
  root = &t[t_size++];
  while (gets(word), strlen(word)) {
    //dump(word);
    insert(word, root); 
  }

  while (scanf("%s", word) != EOF) {
    //dump(word);
    printf("%d\n", query(word));   
  }
  return 0;
}
