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

int digit_cnt(ll x) {
  int c = 0;
  while (x) {
    x /= 10;
    c++;
  }
  return c;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  vector<ll> base;
  base.push_back(1);
  for (int i = 1; i <= 17; i++) base.push_back(base.back() * 10);

  vector<ll> v;
  ll x;
  while (cin >> x) {
    v.push_back(x);
  }

  int start = 0, end = v.size();
  for (int k = 1; k <= 25; ++k) {
      for (int i = start; i < end; ++i) {
        x = v[i]; 
        if (x == 0) {
          v.push_back(1);
          continue;
        }

        int c = digit_cnt(x);
        if (c % 2 == 0) {
          v.push_back(x / base[c/2]);
          v.push_back(x % base[c/2]);
          continue;
        }

        v.push_back(x * 2024);
      }
      start = end;
      end = v.size(); 
      cout << start << " " << end << endl;
  }
  cout << end - start << endl;
  return 0;
}
