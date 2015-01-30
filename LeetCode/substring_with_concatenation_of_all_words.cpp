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
#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl;
#define FR(i,a,b) for(int i=(a);i<(b);++i)//[a,b)
#define CLR(a,x) memset(a,x,sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0x80
#define MP(A,B) make_pair(A,B)
#define PB(A) push_back(A)
#define PAU system("pause");
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(n) (n^(n-1))&n
#define fin freopen(".in","r",stdin);
#define fout freopen(".out","w",stdout);
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

class Solution {
public:
  vector<int> findSubstring(string S, vector<string> &L) {
    int i, k, len, size;
    vector<int> ans;
    size = L.size();
    len = L[0].size();
    
    map<string, int> l_map;
    for (i = 0; i < size; ++i)
      l_map[L[i]]++;

    for (i = 0; i + len * size <= S.size(); ++i) {
      map<string, int> word_set;
      int flag = 1;
      for (k = i; k < i + size * len; k += len) {
        string s = S.substr(k, len);
        word_set[s]++;
        if (word_set[s] > l_map[s]) {
          flag = 0;
          break;
        }
      }
      if (flag) ans.push_back(i);
    }
    return ans;
  }
};

int main() {
  Solution s;
  string S;
  vector<string> L;
  S = "barfoothefoobarman";
  L.push_back("foo");
  L.push_back("bar");
  vector<int> vec = s.findSubstring(S, L);
  out(vec);

  return 0;
}
