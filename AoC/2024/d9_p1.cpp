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
  vector<int> v;
  int k = 0;
  for (auto ch: s) {
    int d = k & 1 ? -1 : k / 2;
    for (int i = 0; i < ch - '0'; ++i) { 
      v.push_back(d);
    }
    k++;
  }
  // out(v);
  
  int i = 0, j = v.size() - 1;
  while (true) {
    while (i < j && v[i] != -1) ++i; 
    while (i < j && v[j] == -1) --j; 
    if (i >= j) {
      break;
    }
  
    swap(v[i], v[j]);
    ++i, --j;
  }
  
  ll ans = 0;
  for (int i = 0; i < v.size(); ++i) {
    if (v[i] == -1) break;
    ans += v[i] * i;
  }
  cout << ans << endl;
  return 0;
}
