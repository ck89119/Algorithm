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
const int N = 100 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int f[N];

int match(int cur, const string &s, const vector<string> &v) {
  if (f[cur] != -1) return f[cur]; 
  
  int ans = 0;
  for (auto &w: v){
    if (cur + w.size() > s.size()) continue; 
    
    bool flag = true;
    for (int i = 0; flag && i < w.size(); ++i) {
      if (s[cur+i] != w[i]) flag = false;
    }
    if (!flag) continue;

    ans |= match(cur + w.size(), s, v);
    if (ans) break;
  }
  return f[cur] = ans;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  string s;
  getline(cin, s);
  // dump(s);

  istringstream is(s);
  vector<string> v;
  while (is >> s) {
    // cout << "`" << s << "`" << endl;
    v.emplace_back(s.back() == ',' ? s.substr(0, s.size() - 1): s);
  }
  // out(v);
  
  int ans = 0;
  while (cin >> s) {
    memset(f, -1, sizeof(f)); 
    f[s.size()] = 1;
    ans += match(0, s, v);
    // dump(s), dump(ans);
  }
  cout << ans << endl;
  return 0;
}
