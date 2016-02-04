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
const int N = 1000000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

char s[N];
int fail[N];
int s_len;

int KMP() {
  fail[0] = -1;
  for (int i = 1, j = -1; i < s_len; ++i) {
    while (j >= 0 && s[i] != s[j+1]) j = fail[j];
    if (s[i] == s[j+1]) ++j;
    fail[i] = j;
  }
  return 0;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif
  int ncase = 1;
  while (scanf("%d", &s_len), s_len) {
    scanf("%s", s);
    KMP();
    //out(fail, s_len);
    printf("Test case #%d\n", ncase);
    for (int i = 2; i <= s_len; ++i) {
      int l = i - 1 - fail[i-1];
      int n = i / l;
      if (i % l == 0 && n > 1)
        printf("%d %d\n", i, n);
    }
    ++ncase;
    printf("\n");
  }
  return 0;
}
