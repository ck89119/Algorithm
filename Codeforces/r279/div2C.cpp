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
const int N = 1000005;
const int M = 9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;
const int CHILD_NUM = 26;
const int MOD = 1000000007;

int n, m;
int r1[N], r2[N];
string key;

int main() {
  //#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  //#endif
  //scanf("%s", key);
  cin >> key;
  cin >> n >> m;
  
  int cur = 0;
  for (int i = 0; i < key.size(); ++i) {
    cur = cur * 10 + key[i] - '0';
    cur %= n;
    r1[i] = cur;
  }
  
  cur = 0;
  int pow10[N];
  pow10[0] = 1 % m;
  for (int i = 1; i < N; ++i)
    pow10[i] = pow10[i-1] * 10 % m;

  for (int i = key.size()-1; i >= 0; --i) {
    cur = cur + (key[i] - '0') * pow10[key.size()-1-i];
    cur %= m;
    r2[i] = cur;
  }
  
  for (int i = 0; i < key.size() - 1; ++i)
    if (r1[i] == 0 && r2[i+1] == 0 && key[i+1] != '0') {
      cout << "YES" << endl;
      cout << key.substr(0, i+1) << endl << key.substr(i+1) << endl;
      return 0;
    }
  cout << "NO" << endl;

  return 0;
}
