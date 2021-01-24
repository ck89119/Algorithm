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
#include <ctime>
using namespace std;
#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl
#define FR(i,a,b) for(int i=(a);i<(b);++i)//[a,b)
#define CLR(a,x) memset(a,x,sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0x80
#define MP(A,B) make_pair(A,B)
#define PB(A) push_back(A)
#define PAU system("pause")
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(x) x & (-x)
#define fin freopen("A-large-practice.in","r",stdin)
#define fout freopen("A-large-practice.out","w",stdout)
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
const int CHILD_NUM = 26;
const int MOD = 1000000007;

int twop[7] = {1, 2, 4, 8, 16, 32, 64};
int pat[10] = {126, 48, 109, 121, 51, 91, 95, 112, 127, 123};
//string pat[10] = {"1111110", "0110000", "1101101", "1111001", "0110011",
                  //"1011011", "1011111", "1110000", "1111111", "1111011"};


int trans(char *s) {
  int ans = 0;
  for (int i = 0; i < 7; ++i)
    ans = ans * 2 + s[i] - '0';
  return ans;
}

int int2char(int t, char *ans) {
  for (int i = 6; i >= 0; --i) {
    ans[i] = '0' + (t & 1);
    t >>= 1;
  }
  ans[7] = '\0';
  return 1;
}


int main() {
  fin; fout;
  int t;
  scanf("%d", &t);
  for (int ncase = 1; ncase <= t; ++ncase) {
    int n, s[105];
    int ans_size = 0, ans;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      char str[10];
      scanf("%s", str);
      s[i] = trans(str);
    }
    for (int guess = 0; guess < 128; ++guess)
      for (int i = 0; i <= 9; ++i)
        if ((guess & pat[i]) == s[0]) {
          int j, k;
          int flag = 1;
          for (j = i - 1, k = 1; k < n; --j, ++k) {
            if (j < 0) j += 10;
            if ((pat[j] & guess) != s[k]) {
              flag = 0;
              break;
            }
          }
          if (flag) {
            if (j < 0) j += 10;
            if (ans_size == 0) {
              ans_size++;
              ans = pat[j] & guess;
            }
            else {
              if (ans != (pat[j] & guess)) ans_size++;
            }
          }
        } 
    
    if (ans_size != 1) {
      printf("Case #%d: ERROR!\n", ncase);
    }
    else {
      char s[10];
      int2char(ans, s);
      printf("Case #%d: %s\n", ncase, s);
    }

  }
  return 0;
}
