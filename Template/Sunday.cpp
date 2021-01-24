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

#define dump(x) cout <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0xc0
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define lowbit(x) x & (-x)
typedef long long ll;
typedef pair<int, int> pii;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 2000000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

struct Sunday {
  int next[256];
  const string &s, &p;

  Sunday(const string &s, const string &p): s(s), p(p) {
    get_next(); 
  }

  int get_next() {
    clr(next, -1);
    for (int i = 0; i < p.size(); ++i)
      next[p[i]] = i;
    return 0;
  }
  
  int search() {
    int cnt = 0;
    int n = s.size();
    int m = p.size();
    for (int i = 0; i <= n - m; ) {
      int k = 0;
      while (k < m && p[k] == s[i+k]) ++k;
      if (k == m) ++cnt;
      i += m - next[s[i+m]]; 
    }
    return cnt;
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int T;
  scanf("%d", &T);
  while (T--) {
    string s, p;
    cin >> p >> s;
    Sunday matcher(s, p);
    printf("%d\n", matcher.search());
  }
  return 0;
}
