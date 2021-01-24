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
const int N = 10000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

class StockSpanner {
 public:
  int idx;
  pair<int, int> v[N];
  int v_size;

  StockSpanner() {
    idx = 0;
    v_size = 0;
  }

  int next(int price) {
    ++idx;
    while (v_size > 0) {
      auto p = v[v_size-1];
      auto a = p.first;
      auto i = p.second;
      if (a <= price) --v_size;
      else break;
    }
    int ans = v_size == 0 ? idx : idx - v[v_size-1].second;
    v[v_size++] = make_pair(price, idx);
    return ans;
  }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);
 */
int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  
  return 0;
}
