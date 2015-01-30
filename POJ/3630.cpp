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
#define fin freopen("test.in","r",stdin)
#define fout freopen("test.out","w",stdout)
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
  int is_word;
  int next[10];
  int reset() {
    is_word = 0;
    CLR(next, -1);
    return 0;
  }
  TrieNode(): is_word(0) {
    CLR(next, -1);
  }
};
TrieNode t[100005];
int t_size;
char num[10005][15];

//int cmp(const string &a, const string &b) {
  //return a.size() < b.size();
//}

int insert(char *s) {
  int node = 0;
  while (*s) {
    int ord = *s - '0';
    if (t[node].next[ord] == -1) {
      t[t_size].reset();
      t[node].next[ord] = t_size;
      node = t_size++;
    } else {
      node = t[node].next[ord];
      if (t[node].is_word) {
        //dump(s);
        //dump(s[i]);
        return 0;
      }     
    }
    ++s;
  }
  t[node].is_word = 1;
  for (int i = 0; i < 10; ++i)
    if (t[node].next[i] != -1) return 0;
  return 1;
}

int main() {
  //fin; fout;
  int n, T;
  int i;
  scanf("%d", &T);
  while (T--) {
    t_size = 0;
    t[t_size++].reset();
    //root = &t[t_size++];
    scanf("%d", &n);
    for (i = 0; i < n; ++i)
      scanf("%s", num[i]);
    //sort(num, num+n, cmp); 
    //out(num, n);
    int flag = 0;
    for (i = 0; i < n; ++i)
      if (!insert(num[i])) {
        //dump(num[i]);
        flag = 1;
        printf("NO\n");
        break;
      }
    if (!flag) printf("YES\n");
  }
  return 0;
}

