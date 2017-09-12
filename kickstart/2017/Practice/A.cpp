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
  freopen("A-large-practice.in", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int t;
  int n;
  cin >> t;
  for (int ncase = 1; ncase <= t; ++ncase) {
    string ans;
    int l = 0;
    cin >> n; getchar();
    for (int i = 0; i < n; ++i) {
      set<char> s;
      string name;
      getline(cin, name);
      for (auto ch: name)
        if (ch != ' ')
          s.insert(ch);
      if (s.size() > l) {
        l = s.size();
        ans = name;
      } else if (s.size() == l && ans > name) {
        ans = name;
      }
    } 
    cout << "Case #" << ncase << ": " << ans << endl;
  }
  return 0;
}
