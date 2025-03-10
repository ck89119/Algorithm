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
const int MAXN=99999;
const int MAXM=9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;
const int MOD = 1000000007;

long long n;
long long ans;
long long sum;

long long sigma_k2(long long n) {
  if (sum % 3 == 0) {
    return sum/3 * ((n+n+1) % MOD) % MOD;
  }
  else {
    return sum * ((n+n+1)/3 % MOD) % MOD;
  }
}

long long sigma_k3(long long n) {
  return sum * sum % MOD;
}

int main() {
    //fin fout
    ios :: sync_with_stdio(false);
    cout << fixed << setprecision(16);
    int T, c;
    cin >> T;
    for (c = 1; c <= T; ++c) {
      cin >> n;
      if (n & 1) {
        sum = ((n+1)/2 % MOD) * (n % MOD) % MOD;
      } else {
        sum = ((n/2) % MOD) * ((n+1) % MOD) % MOD;
      }
      ans = (sum * sum) % MOD * sum % MOD;
      //dump(ans); dump(sigma_k2(n)); dump(sigma_k3(n));
      ans = (ans + 3 * sigma_k3(n) % MOD) % MOD;
      ans = (ans - 3 * sum % MOD * sigma_k2(n) % MOD + MOD) % MOD;
      cout << "Case " << c << ": " << ans << endl;
    }
    return 0;
}
