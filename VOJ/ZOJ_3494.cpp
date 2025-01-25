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
const int MAXN= 2000 + 5;
const int MAXM=9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;
const int CHILD_NUM = 2;
const int MOD = 1000000009;

int dp[205][MAXN];
int digit[205];
int bcd[MAXN][10];

struct Trie {
  int next[MAXN][CHILD_NUM], fail[MAXN], end[MAXN];
  int root, size;

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

  int insert(char s[], int len) {
    int cur = root;
    for (int i = 0; i < len; ++i) {
      if (next[cur][s[i]-'0'] == -1) next[cur][s[i]-'0'] = newNode();
      cur = next[cur][s[i]-'0'];
    }
    end[cur] = 1;
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
      end[cur] |= end[fail[cur]];
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
  
  int work() {
    CLR(bcd, -1);
    for (int i = 0; i < size; ++i) {
      if (end[i]) continue;
      for (int j = 0; j < 10; ++j) {
        int s = i;
        int flag = 0;
        for (int k = 3; k >= 0; --k) {
          if (end[next[s][(j>>k)&1]]) flag = 1;
          s = next[s][(j>>k)&1];
        }
        if (!flag) bcd[i][j] = s;
      }
    }
    return 0;
  }
};
Trie ac;

int dfs(int pos, int s, int limit, int all_zero) {
  if (pos < 0) return 1;
  if (!limit && dp[pos][s] != -1) return dp[pos][s];

  int ans = 0;
  if (all_zero) {
    if (pos == 0) {
      ans += bcd[s][0] == -1 ? 0 : 1;
    }
    else {
      ans += dfs(pos-1, s, limit && digit[pos] == 0, all_zero);
      ans %= MOD;
    }
  } else {
    if (bcd[s][0] != -1)
      ans += dfs(pos-1, bcd[s][0], limit && digit[pos] == 0, all_zero);
    ans %= MOD;
  }
  
  int ending = limit ? digit[pos] : 9;
  for (int i = 1; i <= ending; ++i) {
    if (bcd[s][i] != -1) {
      //if (i == 6) {dump(s); dump(bcd[s][i]);}
      ans += dfs(pos-1, bcd[s][i], limit && i == ending, 0);
      ans %= MOD;
      //dump(i); dump(ans);
    }
  }
  if (!limit) dp[pos][s] = ans;
  return ans;
}

int cal(char s[], int len) {
  for (int i = 0; i < len; ++i)
    digit[i] = s[len-1-i] - '0';
  //out(s, len); out(digit, len);
  return dfs(len-1, 0, 1, 1);
}

int sub(char s[], int len) {
  for (int i = len-1; i >= 0; --i)
    if (s[i] > '0') {
      --s[i]; break;
    } else {
      s[i] = '9';
    }
  return 0;
}

int main() {
  //fin; fout;
  int T, n;
  scanf("%d", &T);
  while (T--) {
    char str[205];
    scanf("%d", &n);
    ac.init();
    for (int i = 0; i < n; ++i) {
      scanf("%s", str);
      ac.insert(str, strlen(str));
    }
    ac.build();
    ac.work();
    //for (int i = 0; i < ac.size; ++i)
      //out(bcd[i], 10);


    int ans;
    CLR(dp, -1);
    scanf("%s", str);
    sub(str, strlen(str));
    ans = -cal(str, strlen(str));
    //dump(ans);
    scanf("%s", str);
    ans += cal(str, strlen(str));
    ans = (ans + MOD) % MOD;
    printf("%d\n", ans);
  }
  return 0;
}
