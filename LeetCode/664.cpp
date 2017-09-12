#include <bits/stdc++.h>
using namespace std;

#define dump(x) cout <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0xc0
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define lowbit(x) x & (-x)
typedef long long ll;
typedef pair<int, int> pii;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 100000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

class Solution {
 public:
  // vector<int> pre;
  // int get_pre(string s) {
  //   map<char, int> m;
  //   pre = vector<int>(s.size());
  //   for (int i = 0; i < s.size(); ++i) {
  //     pre[i] = m.find(s[i]) == m.end() ? -1 : m[s[i]];
  //     m[s[i]] = i;
  //   }
  //   return 0;
  // }

  int search(int x, int y, const string &s) {
    if (x > y) return 0;
    if (f[x][y] != -1) return f[x][y];

    int ans = INF;
    for (int i = x; i <= y; ++i)
      for (int j = i; j <= y; ++j) {
        
      }

    return f[x][y] = ans; 
  }

  int strangePrinter(string s) {
    // get_pre(s);
    int n = s.size();
    int f[n][n];
    clr(f, -1);
    for (int i = 0; i < n; ++i) f[i][i] = 1;
    return search(0, n-1, s);   
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  
  return 0;
}
