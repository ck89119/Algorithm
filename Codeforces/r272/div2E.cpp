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
#define CLR(a,x) memset(a,x,sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0x80
#define MP(A,B) make_pair(A,B)
#define PB(A) push_back(A)
#define PAU system("pause")
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(x) x & (-x)
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out (vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 2005;
const int M = 9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;
const int CHILD_NUM = 26;
const int MOD = 1000000007;

string s, p;
int f[N][N];
int have[N];

int check(int i) {
  for (int j = 0; j < p.size(); ++j)
    if (s[i+j] != p[j]) return 0;
  return 1;
}

int main() {
  //#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  //#endif
  cin >> s >> p; 
  int k = 0;
  have[0] = 0;
  for (int i = 0; i < s.size(); ++i) {
    have[i+1] = have[i];
    if (s[i] == p[k]) ++k;
    if (k == p.size()) {
      ++have[i+1];
      k = 0;
    }
  }

  CLR(f, 0);
  for (int i = p.size() - 1; i < s.size(); ++i) {
    if (check(i-p.size()-1)) f[i+1][0] = f[i+1-p.size()][0] + 1;
  }
  
  for (int x = 1; x <= s.size(); ++x)
    for (int i = 0; i < s.size(); ++i) {
      f[i+1][x] = max(f[i][x-1], f[i][x] + (have[i+1] > have[i]));
    }
  for (int x = 0; x <= s.size(); ++x)
    cout << f[s.size()][x] << ' ';
  cout << endl;
  return 0;
}
