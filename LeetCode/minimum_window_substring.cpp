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

class Solution {
public:
    int n1[52], n2[52];

    int check() {
      int i;
      for (i = 0; i < 52; ++i)
        if (n1[i] > n2[i]) return 0;
      return 1;
    }
    
    string minWindow(string S, string T) {
      int n = S.size();
      int l, r, i;
      string ans = S;
      CLR(n1, 0); CLR(n2, 0);
      for (i = 0; i < T.size(); ++i) {
        if (T[i] < 'a') n1[T[i]-'A']++;
        else n1[T[i]-'a'+26]++;
      }
      l = r = 0;
      int flag = 0;
      while (r < n) {
        while (r < n && !check()) 
          if (S[r] < 'a') n2[S[r++]-'A']++;
          else n2[S[r++]-'a'+26]++;
        if (check()) flag = 1;
        while (l < n && check())
          if (S[l] < 'a') n2[S[l++]-'A']--;
          else n2[S[l++]-'a'+26]--;
        if (ans.size() > r - l + 1)
          ans = S.substr(l-1, r-l+1);
      }
      if (flag == 0) return "";
      return ans;
    }
};


