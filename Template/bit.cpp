#include <bits/stdc++.h>
using namespace std;

#define dump(x) cout <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0xc0
typedef long long ll;
typedef pair<int, int> pii;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 100000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

struct Fenwick {
  vector<int> c;

  Fenwick(int _n) {
    c = vector<int>(_n);
  }

  int add(int x, int v) {
    while (x < c.size()) {
      c[x] += v;
      x += x & -x;
    } 
    return 0;
  }

  int sum(int x) {
    int ans = 0;
    while (x > 0) {
      ans += c[x];
      x -= x & -x;
    }
    return ans;
  }

  int find_kth(int k) {
    int ans, cnt;
    ans = cnt = 0;
    for (int i = 20; i >= 0; --i) {
      ans += (1 << i);
      if (ans > N || cnt + c[ans] >= k)
        ans -= (1 << i);
      else
        cnt += c[ans];
    }
    return ans + 1;
  }
};

struct FenwickRange {
  Fenwick c1, c2;

  FenwickRange(int n, int m): c1(n), c2(m) {}

  int add(int l, int r, int v) {
    c1.add(l, v), c1.add(r+1, -v);
    c2.add(l, v*l), c2.add(r+1, -v*(r+1));
    return 0;
  }

  int sum(int x) {
    return c1.sum(x) * (x+1) - c2.sum(x);
  }

  int sum(int l, int r) {
    return sum(r) - sum(l-1);
  } 
};

struct FenwickMax {
  vector<int> a, c;

  FenwickMax(int n) {
    a = vector<int>(n);
    c = vector<int>(n);
  }

  int lowbit(int x) {
    return x & -x;
  }

  int query(int l, int r) {
    int ans = -INF;
    while (r >= l) {
      ans = max(ans, a[r]);
      for (--r; r - lowbit(r) >= l; r -= lowbit(r)) {
        ans = max(ans, c[r]);
      }
    }
    return ans;
  }
  
  void update(int i, int v) {
    a[i] = v;
    while (i < a.size()) {
      c[i] = a[i];
      for (int j = 1; j < lowbit(i); j <<= 1)
        c[i] = max(c[i], c[i-j]);
      i += lowbit(i);
    } 
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  int n;
  int a[N];
  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> a[i];
  Fenwick s(n);
  for (int i = 1; i <= n; ++i) {
    s.add(i, a[i]);
    //cout << sum(i) << endl;
  }
  for (int i = 1; i <= n; ++i) 
    // cout << s.c[i] << endl;
    cout << s.sum(i) << endl;
  
  return 0;
}
