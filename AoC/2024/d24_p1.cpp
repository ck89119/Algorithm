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
  unordered_map<string, int> val;  
  unordered_map<string, tuple<string, string, string>> dep; 

  string line;
  while (getline(cin, line)) {
    if (line == "") break;  
    val[line.substr(0, 3)] = line.back() - '0';    
  }
  // for (auto &[k, v]: val) cout << k << ": " << v << endl;
  
  auto set_val = [&](string &k) {
    if (val.find(k) == val.end()) {
      val[k] = -1;
    }
  };

  while (getline(cin, line)) {
    string a, b, c, op, dummy;
    istringstream is(line);
    is >> a >> op >> b >> dummy >> c;
    set_val(a);
    set_val(b);
    set_val(c);
    dep[c] = make_tuple(a, op, b);
  }
  dump(val.size());
  
  auto i2s = [](int i) -> string {
    string s = "00";
    if (i >= 10) s[0] = i / 10 + '0';
    s[1] = i % 10 + '0';
    return s;
  };
  
  function<int(string)> dfs;
  dfs = [&](string cur) -> int {
    if (val[cur] != -1) {
      return val[cur]; 
    }
    
    auto &[a, op, b] = dep[cur];
    int ans;
    if (op == "AND") {
      ans = dfs(a) & dfs(b); 
    } else if (op == "XOR") {
      ans = dfs(a) ^ dfs(b); 
    } else {
      ans = dfs(a) | dfs(b); 
    }

    return val[cur] = ans;
  };

  ll ans = 0;
  for (int i = 0; i < 100; ++i) {
    string k = "z" + i2s(i);
    if (val.find(k) == val.end()) break;
    
    ll v = dfs(k);
    cout << k << ": " << v << endl;
    ans |= (v << i);
  }
  dump(ans);  
  return 0;
}
