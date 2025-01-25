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

vector<ll> base{
  1LL, 
  10LL, 
  100LL, 
  1000LL, 
  10000LL,  
  100000LL,  
  1000000LL,  
  10000000LL,  
  100000000LL,  
  1000000000LL,  
  10000000000LL,  
  100000000000LL,  
  1000000000000LL,  
  10000000000000LL,  
  100000000000000LL,  
  1000000000000000LL,  
  10000000000000000LL,  
};

map<ll, ll> mp[76];

int digit_cnt(ll x) {
  int c = 0;
  while (x) {
    x /= 10;
    c++;
  }
  return c;
}

ll dfs(ll x, int times) {
  // cout << x << " " << times << endl;
  if (mp[times].find(x) != mp[times].end()) {
    return mp[times][x];
  }
  
  if (times == 0) {
    return 1;
  }
  
  if (x == 0) {
    return mp[times][x] = dfs(1, times - 1);
  }
  
  int c = digit_cnt(x);
  // cout << "c = " << c << endl;
  if (c % 2 == 0) {
    // cout << "x / base[c/2] = " << x / base[c/2] << endl;
    // cout << "x % base[c/2] = " << x % base[c/2] << endl;
    return mp[times][x] = dfs(x / base[c/2], times - 1) + dfs(x % base[c/2], times - 1);
  }
  
  return mp[times][x] = dfs(x * 2024, times - 1);;
}


int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  ll ans = 0, x;  
  while (cin >> x) {
    ans += dfs(x, 75);
  }
  cout << ans << endl;
  return 0;
}
