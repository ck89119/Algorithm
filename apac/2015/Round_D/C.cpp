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

map<string, int> Count;
map<string, string> tickets;
int n;


int main() {
  #ifndef ONLINE_JUDGE
    freopen("C-large.in", "r", stdin);
    freopen("C-large.out", "w", stdout);
  #endif
  int T;
  cin >> T;
  for (int ncase = 1; ncase <= T; ++ncase) {
    Count.clear(); tickets.clear();
    cin >> n;
    for (int i = 0; i < n; ++i) {
      string a, b;
      cin >> a >> b;
      ++Count[a]; ++Count[b];
      tickets[a] = b;
    }
    
    map<string, int>::iterator it;
    string start;
    for (it = Count.begin(); it != Count.end(); ++it) {
      if (it->second == 1) {
         if (tickets.count(it->first) != 0) {
           start = it->first;
           break;
         }
      }
    }

    cout << "Case #" << ncase << ": ";
    for (int i = 0; i < n; ++i) {
      cout << start << '-' << tickets[start] << ' ';
      start = tickets[start];
    }
    cout << endl;
  
  }
  return 0;
}
