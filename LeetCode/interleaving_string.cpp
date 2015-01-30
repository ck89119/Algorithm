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

int f[105][105][205];
class Solution {
public:
  int check(const string &s1, const string &s2, const string &s3, int i1, int i2, int i3) {
    if (f[i1][i2][i3] != -1) return f[i1][i2][i3];
    int ans = 0;
    if (i3 >= s3.size()) return 1;
    if (i1 < s1.size() && s3[i3] == s1[i1])
      ans |= check(s1, s2, s3, i1+1, i2, i3+1);
    if (i2 < s2.size() && s3[i3] == s2[i2])
      ans |= check(s1, s2, s3, i1, i2+1, i3+1);
    f[i1][i2][i3] = ans;
    return ans;
  }
  
  bool isInterleave(string s1, string s2, string s3) {
    int n1, n2, n3;
    n1 = s1.size();
    n2 = s2.size();
    n3 = s3.size();
    if (n1 + n2 != n3) return false;
    CLR(f, -1);
    if (check(s1, s2, s3, 0, 0, 0)) return true;
    else return false;
  }
};

int main() {
  string s1, s2, s3;
  s1 = "aabcc";
  s2 = "dbbca";
  s3 = "aadbbcbcac";
  Solution s;
  cout << s.isInterleave(s1, s2, s3) << endl;
  ios :: sync_with_stdio(false);
  cout << fixed << setprecision(16);
  return 0;
}
