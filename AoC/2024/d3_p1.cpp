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

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  int ans = 0;
  string s;
  while (getline(cin, s)) {
    for (int i = 0; i + 7 < s.size(); ++i) {
      if (!(s[i] == 'm' && s[i+1] == 'u' && s[i+2] == 'l' && s[i+3] == '(')) continue;
      
      int j = 4, a = 0, b = 0;
      while (i + j < s.size() && s[i+j] >= '0' && s[i+j] <= '9') {
        a = a * 10 + s[i+j] - '0';
        ++j;
      }
      if (i + j == s.size() || s[i+j] != ',') continue;
      
      ++j;
      while (i + j < s.size() && s[i+j] >= '0' && s[i+j] <= '9') {
        b = b * 10 + s[i+j] - '0';
        ++j;
      }
      if (i + j == s.size() || s[i+j] != ')') continue;
      
      if (a >= 1000 || b >= 1000) {
        cout << a << " " << b << endl;
      }
      ans += a * b;
    } 

  }
  cout << ans << endl;
  return 0;
}
