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

#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0x80
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(x) x & (-x)
#define X first 
#define Y second
typedef long long ll;
typedef pair<int, int> pii;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 400000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

char s[N];
int fail[N];

int print(int x) {
  if (fail[x] != -1) print(fail[x]);
  printf("%d ", x + 1);
  return 0;
}

int KMP() {
  int la = strlen(s);
    
  fail[0]  = -1;
  for (int i = 1, j = -1; i < la; ++i) {
    while (j >= 0 && s[i] != s[j+1]) j = fail[j];
    if (s[i] == s[j+1]) ++j;
    fail[i] = j;
  }
  //out(fail, la);
  print(la-1);
  printf("\n");
  return 0;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif
  while (scanf("%s", s) != EOF) {
    KMP();
  } 
  return 0;
}
