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
#define fin freopen(".in","r",stdin)
#define fout freopen(".out","w",stdout)
//ifstream fin("");
//ofstream fout("");
#define LL long long
#define ULL unsigned long long

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out (vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int MAXN= 300000 + 5;
const int MAXM=9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;
const int CHILD_NUM = 20;
const int MOD = 1000000007;

int n, m, k;
int digit_l[200+5], digit_r[200+5], len_l, len_r;

struct AC {
  int next[MAXN][CHILD_NUM], fail[MAXN], end[MAXN];
  int size, root;
  
  int newNode() {
    CLR(next[size], -1);
    fail[size] = -1;
    end[size] = 0;
    return size++;
  }

  int init() {
    size = 0;
    root = newNode();
    return 0;
  }

  int insert(int s[], int len, int v) {
    int cur = root;
    int i = 0;
    while (i < len) {
      if (next[cur][s[i]] == -1) next[cur][s[i]] = newNode();
      cur = next[cur][s[i]];
      ++i;
    }
    end[cur] += v;
    return 0;
  }

  int build() {
    queue<int> q;
    fail[root] = -1;
    for (int i = 0; i < m; ++i)
      if (next[root][i] == -1) {
        next[root][i] = root;
      } else {
        fail[next[root][i]] = root;
        q.push(next[root][i]);
      }
    
    while (!q.empty()) {
      int cur = q.front(); q.pop();
      end[cur] += end[fail[cur]];
      for (int i = 0; i < m; ++i)
        if (next[cur][i] == -1) {
          next[cur][i] = next[fail[cur]][i];
        } else {
          fail[next[cur][i]] = next[fail[cur]][i];
          q.push(next[cur][i]);
        }
    }
    return 0;
  }

};
AC ac;

int f[205][505][205][2][2];
int dfs(int pos, int v, int node, int zero, int limit, int digit[], int len) {
  //v += ac.end[node];
  if (v > k) return 0;
  if (pos >= len) return 1;

  int &ans = f[pos][v][node][zero][limit];
  if (ans != -1) return ans;
  ans = 0;

  int end = limit ? digit[pos] : m-1;
  for (int i = 0; i <= end; ++i) {
    int nextNode = node;
    if (!zero || i != 0) nextNode = ac.next[node][i];
    ans += dfs(pos+1, v + ac.end[nextNode], nextNode, zero && i == 0, limit && i == end, digit, len);
    if (ans >= MOD) ans -= MOD;
  }

  return ans;
}

int cal(int digit[], int len) {
  CLR(f, -1);
  //dump(len); out(digit, len);
  return dfs(0, 0, ac.root, 1, 1, digit, len);
}

int sub(int digit[], int &len) {
  --digit[len-1];
  for (int i = len-1; i >= 0; --i)
    if (digit[i] < 0) {
      digit[i] += m;
      digit[i-1] -= 1;
    }
  if (digit[0] == 0) {
    for (int i = 1; i < len; ++i)
      digit[i-1] = digit[i];
    --len;
  }
  return 0;
}

//int rec(int at, bool leadingZero, bool sameL, bool sameR, int u, int have) {
	//have += ac.end[u];
	//if (have > k)
		//return 0;

	//if (at == len_l) {
		//return 1;
	//}

	//bool save = !(sameL || sameR);
	//int ret = 0;
	//if (save) {
		//ret = f[at][u][have];
		//if (ret != -1)
			//return ret;
		//ret = 0;
	//}

	//for (int nxt = 0; nxt < m; ++nxt) { //nxt digit
		//if (sameL && nxt < digit_l[at])
			//continue;
		//if (sameR && nxt > digit_r[at])
			//continue;
		//int nu = u;
		//if (!leadingZero || nxt > 0)
			//nu = ac.next[u][nxt];

		//ret += rec(at + 1, leadingZero && (nxt == 0), sameL && (nxt == digit_l[at]),
				//sameR && (nxt == digit_r[at]), nu, have);
		//if (ret >= MOD)
			//ret -= MOD;
	//}

	//if (save) {
		//f[at][u][have] = ret;
	//}

	//return ret;
//}

int main() {
  //fin; fout;
  scanf("%d%d%d", &n, &m, &k);
  scanf("%d", &len_l);
  for (int i = 0; i < len_l; ++i)
    scanf("%d", &digit_l[i]);
  scanf("%d", &len_r);
  for (int i = 0; i < len_r; ++i)
    scanf("%d", &digit_r[i]);
  for (int i = len_r-1; i >= len_r-len_l; --i)
    digit_l[i] = digit_l[i-len_r+len_l];
  for (int i = len_r-len_l-1; i >= 0; --i)
    digit_l[i] = 0;
  len_l = len_r;
  ac.init();
  for (int i = 0; i < n; ++i) {
    int len, t[200+5], v;
    scanf("%d", &len);
    for (int j = 0; j < len; ++j)
      scanf("%d", &t[j]);
    scanf("%d", &v);
    ac.insert(t, len, v);
  }
  ac.build();
  sub(digit_l, len_l);
  int ans = (cal(digit_r, len_r) - cal(digit_l, len_l) + MOD) % MOD; 
  //CLR(f, -1);
  //int ans = rec(0, 1, 1, 1, ac.root, 0);
  cout << ans << endl;
  return 0;
}
