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
const int N = 99999;
const int M = 9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;
const int CHILD_NUM = 26;
const int MOD = 1000000007;

int p;
int inv[N];

LL power(LL x, int n) {
  if (n == 1) return x % p;
  int t = power(x, n >> 1);
  if (n & 1) return t * t % p * x % p;
  else return t * t % p;
}

LL get_inv(int x) {
  return power(x, p-2);
}

int get_inv2(int x) {
  inv[1] = 1;
  for (int i = 2; i < x; ++i) {
    inv[i] = (p - (p / i) * inv[p % i] % p) % p;
  }
  return 0;
}


int main() {
  //#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  //#endif
  
  cin >> p;
  cout << "ans from get_inv: ";
  for (int i = 1; i < p; ++i) cout << get_inv(i) << " "; cout << endl;
  get_inv2(p);
  cout << "ans from get_inv2: ";
  for (int i = 1; i < p; ++i) cout << inv[i] << " "; cout << endl;

  return 0;
}
