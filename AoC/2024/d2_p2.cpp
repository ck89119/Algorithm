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

bool is_safe(const vector<int> &v, int j, int op) {
  auto check = [&](int x, int y) -> bool {
    if (op > 0 && v[x] < v[y]) return false;
    if (op < 0 && v[x] > v[y]) return false;
    return abs(v[x]-v[y]) > 0 && abs(v[x]-v[y]) <= 3;
  };

  for (int i = 0; i + 1 < j; ++i) {
    if (!check(i, i+1)) {
      return false;
    }     
  }

  if (j - 1 >= 0 && j + 1 < v.size() && !check(j-1, j+1)) {
    return false;
  }

  for (int i = j + 1; i + 1 < v.size(); ++i) {
    if (!check(i, i+1)) {
      return false;
    }     
  }
  
  return true;
}

bool is_safe(const vector<int> &v) {
  for (int i = 0; i < v.size(); ++i) {
    if (is_safe(v, i, -1) || is_safe(v, i, 1)) {
      return true; 
    }
  }
  return false;
}


int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  string line;
  int ans = 0;
  while (getline(cin, line)) {
    vector<int> v;
    int a;
    istringstream is(line);
    while (is >> a) {
      v.push_back(a);
    }
    if (v.size() < 3) out(v);
    // if (is_safe(v)) out(v);
    ans += is_safe(v);
  }
  cout << ans << endl;
  
  return 0;
}
