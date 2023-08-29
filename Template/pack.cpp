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
const int V = 100000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int c[N];
int f[V];
int n[N];

// O(N * V)
int ZeroOnePack(int cost, int value) {
  for (int v = V; v >= cost; --v)
    f[v] = max(f[v], f[v - cost] + value);
  return 0;
}

// O(N * V)
int CompletePack(int cost, int value) {
  for (int v = cost; v <= V; ++v)
    f[v] = max(f[v], f[v - cost] + value);
  return 0;
}

// O(sigma{n[i]} * V)
int MutiplePack(int cost, int value, int amount) {
  int k;
  if (cost * amount >= V)
    CompletePack(cost, value);
  k = 1;
  while (k < amount) {
    ZeroOnePack(k * cost, k * value);
    amount -= k;
    k *= 2;
  }
  ZeroOnePack(amount * cost, amount * value);
  return 0;
}

// O(N * V)
// f[i][j] 前i种表示j，第i种最多能剩下的个数 
int MutiplePackII() {
  memset(f, -1, sizeof(f)); 
  f[0] = 1;
  for (int i = 1; i <= N; ++i)
    for (int j = 0; j <= V; ++j)
      if (f[j] >= 0) f[j] = n[i-1];
      else if (j < c[i-1] || f[j-c[i-1]] <= 0) f[j] = -1;
      else f[j] = f[j-c[i-1]] - 1; 
  for (int j = 0; j <= V; ++j) {
    // XXXX
  }
  return 0;
}

// O(N * V * max{n[i]})
// 每组的物品互斥
int GroupPack(int cost, int value, int amount) {
  for (int i = V; i >= 0; --i)
    for (int j = 1; j <= amount; ++j)
      if (i >= j * cost)
        f[i] = max(f[i], f[i - j * cost] + j * value);
  return 0;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  for (int i = 1; i <= N; i++){
    XXPack();
  }
  
  return 0;
}
