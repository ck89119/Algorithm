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
#define fin freopen("A-large-practice.in","r",stdin)
#define fout freopen("A-large-practice.out","w",stdout)
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
const int CHILD_NUM = 26;
const int MOD = 1000000007;

int n;
vector<vector<pair<char, int> > > vec;

vector<pair<char, int> > prepro(char s[]) {
  vector<pair<char, int> > ans;
  for (int i = 0; s[i]; ++i) {
    pair<char, int> p;
    p.first = s[i]; p.second = 1;
    while (s[i+1] && s[i+1] == s[i]) {
      p.second++;
      i++;
    }
    ans.push_back(p);
  }
  return ans;
}

int check() {
  int len = vec[0].size();
  for (int i = 1; i < vec.size(); ++i) {
    if (vec[i].size() != len) return 0;
    for (int j = 0; j < len; ++j)
      if (vec[i][j].first != vec[0][j].first) return 0;
  }
  return 1;
}

int cal(int x) {
  int y[105];
  for (int i = 0; i < n; ++i) y[i] = vec[i][x].second;
  sort(y, y + n);
  
  int ans = 0;
  for (int i = 0, j = n-1; i < j; ++i, --j)
    ans += (y[j] - y[i]);
  return ans;
}

int main() {
  fin; fout;
  int T;
  scanf("%d", &T);
  for (int ncase = 1; ncase <= T; ++ncase) {
    char s[105];
    scanf("%d", &n);
    vec.clear();
    for (int i = 0; i < n; ++i) {
      scanf("%s", s);
      vec.push_back(prepro(s));
    }
    
    if (!check()) {
      printf("Case #%d: Fegla Won\n", ncase);
    } else {
      int ans = 0;
      for (int i = 0; i < vec[0].size(); ++i)
        ans += cal(i);
      printf("Case #%d: %d\n", ncase, ans);
    }
  }
  return 0;
}
