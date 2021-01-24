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
#define lowbit(n) (n^(n-1))&n
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

int op, m, n;

int main() {
  //fin fout
  int T;
  while (scanf("%d", &T) != EOF) {
  	while (T--) {
	 		scanf("%d%d%d", &op, &m, &n);
	 		if (op) {
	 			double d[MAXN];
	 			d[1] = 1.0;
	 			for (int i = 1; i < n; ++i)
	 				d[i+1] = d[i] * m / (m-i);
	 			double ans = 0.0;
	 			for (int i = 1; i <= n; ++i)
	 				ans += d[i];
	 			printf("%.8lf\n", ans);
	 		}	else {
	 			double ans = 0;
	 			for (int i = 0; i < n; ++i)
	 				ans += pow(1.0*m, 1.0*i);
	 			printf("%.8lf\n", ans);
	 		}
  	}
  }
  return 0;
}