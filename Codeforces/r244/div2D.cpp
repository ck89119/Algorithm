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
#define ULL unsigned long long
template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out (vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int MAXN=99999;
const int MAXM=9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;
const int MOD = 9997;


struct HashMap {
  int head[MOD], next[MAXN];
  ULL data[MAXN]; 
  int cnt[2][MAXN];
  int size;

  int init() {
    size = 0;
    CLR(head, -1);
    return 0;
  }

  int insert(ULL key, int no) {
    int k = key % MOD;
    for (int i = head[k]; i != -1; i = next[i])
      if (data[i] == key) {
        ++cnt[no][i];
        return 0;
      }
    data[size] = key;
    next[size] = head[k];
    cnt[0][size] = cnt[1][size] = 0;
    ++cnt[no][size];
    head[k] = size++;
    return 0;
  }

  int check() {
    for (int i = 0; i < size; ++i)
      if (cnt[0][i] == 1 && cnt[1][i] == 1) return 1;
    return 0;
  }
};

HashMap hash_map;
char s1[5005], s2[5005];
int n1, n2;
const int SEED = 10007; 
ULL h1[5005], h2[5005];
ULL p[5005];

int main() {
  int n1, n2;
  scanf("%s%s", s1, s2);
  n1 = strlen(s1); n2 = strlen(s2);
  p[0] = 1;
  for (int i = 1; i <= min(n1, n2); ++i)
    p[i] = p[i-1] * SEED;
  h1[0] = 0;
  for (int i = 1; i <= n1; ++i)
    h1[i] = h1[i-1] * SEED + s1[i-1];
  h2[0] = 0;
  for (int i = 1; i <= n2; ++i)
    h2[i] = h2[i-1] * SEED + s2[i-1];
  //out(h1, n1); out(h2, n2);
  for (int i = 1; i <= min(n1, n2); ++i) {
    hash_map.init();
    for (int j = i; j <= n1; ++j)
      hash_map.insert(h1[j] - h1[j-i] * p[i], 0);
    for (int j = i; j <= n2; ++j)
      hash_map.insert(h2[j] - h2[j-i] * p[i], 1);
    
    if (hash_map.check()) {
      printf("%d\n", i);
      return 0;
    }
  }
  printf("-1\n");
  return 0;
}
