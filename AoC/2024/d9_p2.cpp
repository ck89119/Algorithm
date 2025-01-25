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
  string s;
  cin >> s;

  // len: start_idx
  map<int, set<int>> free;
  // start_idx, len
  vector<tuple<int, int>> files;
  int k = 0, len = 0;
  for (auto ch: s) {
    int d = ch - '0';
    if (k & 1) {
      free[d].emplace(len); 
    } else {
      files.emplace_back(len, d); 
    } 
    k += 1, len += d;
  }

  for (int i = files.size() - 1; i >= 0; --i) {
    auto [file_idx, file_len] = files[i];
    // cout << i << ": " << file_idx << ", " << file_len << endl;

    int len = -1, min_idx = INF;
    for (auto it = free.lower_bound(file_len); it != free.end(); ++it) {
      auto &s = it->second;
      if (!s.empty()) {
        auto e = *s.begin();
        // cout << "e = " << e << endl;
        if (e < min_idx && e < file_idx) {
          min_idx = *s.begin();
          len = it->first;
        }
      }
    }
    // cout << i << ": " << min_idx << ", " << len << endl;

    if (min_idx != INF) {
      free[len].erase(min_idx);
      free[len - file_len].emplace(min_idx + file_len);
      files[i] = make_tuple(min_idx, file_len);
    
      // for (auto &[k, v]: free) {
      //   cout << k << ": ";
      //   for (auto e: v) cout << e << ", ";
      //   cout << endl;
      // }
    }
    // cout << "=====================================" << endl;
  }

  ll ans = 0;
  for (int i = 0; i < files.size(); ++i) {
    auto [file_idx, file_len] = files[i];
    // cout << i << ": " << file_idx << ", " << file_len << endl;
    ans += 1LL * i * (file_idx + file_idx + file_len - 1) * file_len / 2;
  }
  cout << ans << endl;
  return 0;
}
