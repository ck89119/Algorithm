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
set<int> factor;

int get_factor(int x) {
  factor.clear();
  for (int i = 1; i * i <= x; ++i) {
    if (x % i == 0) {
      factor.insert(i);
      factor.insert(x / i);
    }
  }
  return 0;
}

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
  //for (int i = 1; i <= 10; ++i) {
    //dump(i);
    //get_factor(i);
    //for (auto x : factor)
      //printf("%d ", x);
    //printf("\n");
  //}
  while (scanf("%s", s), strcmp(s, ".")) {
    s_len = strlen(s);
    get_factor(s_len);
    KMP();
    //out(fail, s_len);
    //for (auto x : factor)
      //printf("%d ", x);
    //printf("\n");
    
    set<int>::iterator it;
    for (it = factor.begin(); it != factor.end(); ++it) {
      int l = (int)(*it);
      int n = s_len / l;
      //dump(l);
      //dump(n);
      int flag = 1;
      for (int i = 1; i < n && flag; ++i)
        for (int j = 0; j < l && flag; ++j)
          if (fail[l*i+j] != l*(i-1) + j)
            flag = 0;
      if (flag) {
        printf("%d\n", n);
        break;
      }
    }
  }
  return 0;
}
