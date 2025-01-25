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
#define fin freopen("A-small-attempt0.in","r",stdin)
#define fout freopen("A-small-attempt0.out","w",stdout)
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

int same_card(const vector<int> &a, const vector<int> &b, int &same) {
  int i, j;
  int ans = 0;
  for (i = 0; i < 4; ++i)
    for (j = 0; j < 4; ++j)
      if (a[i] == b[j]) {
        ans++;
        same = a[i];
      }
  return ans;
}

int main() {
    fin; fout;
    ios :: sync_with_stdio(false);
    cout << fixed << setprecision(16);
    int T, c;
    int i, j, cnt, x;
    int card;
    vector<int> a, b;
    cin >> T;
    for (c = 1; c <= T; ++c) {
      a.clear();
      cin >> x;
      for (i = 1; i <= 4; ++i)
        for (j = 1; j <= 4; ++j) {
          cin >> card;
          if (i == x) a.PB(card);
        }
      b.clear();
      cin >> x;
      for (i = 1; i <= 4; ++i)
        for (j = 1; j <= 4; ++j) {
          cin >> card;
          if (i == x) b.PB(card);
        }

      cnt = same_card(a, b, card);
      if (cnt < 1) cout << "Case #" << c <<": Volunteer cheated!" << endl;
      else if (cnt == 1) cout << "Case #" << c << ": " << card << endl;
      else cout << "Case #" << c << ": Bad magician!" << endl;

    }

    return 0;
}
