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
const int MAXN=99999;
const int MAXM=9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;
const int CHILD_NUM = 26;
const int MOD = 1000000007;

int k, n;
string s;

int main() {
  //fin; fout;
  int t;
  cin >> t;
  while (t--) {
    int ans = 0;
    cin >> s >> k;
    n = s.size();
    if (k >= (n+2)/2) {
      int dx = n - k;
      int cnt[4];
      for (int i = 0; i < n - k; ++i) {
        int j = i;
        int max_cnt, sum_cnt;
        CLR(cnt, 0);
        while (j < n) {
          if (s[j] == 'A') ++cnt[0];
          else if (s[j] == 'C') ++cnt[1];
          else if (s[j] == 'T') ++cnt[2];
          else if (s[j] == 'G') ++cnt[3];
          j += dx;
        }
        max_cnt = sum_cnt = 0;
        for (int i = 0; i < 4; ++i) {
          max_cnt = max(max_cnt, cnt[i]);
          sum_cnt += cnt[i];
        }
        ans += (sum_cnt - max_cnt);
      }
    } else {
      for (int i = 0; i < k; ++i)
        if (s[i] != s[n-k+i]) ++ans;
    }
    cout << ans << endl;
  }
  return 0;
}
