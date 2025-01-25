//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define CLR(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0x80
#define MP(A, B) make_pair(A, B)
#define PB(A) push_back(A)
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(x) x & (-x)
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 100 + 5;
const int V = 100000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n, m;
int a[N], c[N];
int f[V];
int cap;
int q[V], l, r;
int ans;

int ZeroOnePack(int cost) {
    int v;
    for (v = cap; v >= cost; v--)
      f[v] |= f[v - cost];
    return 0;
}

int CompletePack(int cost) {
    int v;
    for (v = cost; v <= cap; v++)
      f[v] |= f[v - cost];
    return 0;
}

int MutiplePack(int cost, int amount){
  if (amount == 1) {
    ZeroOnePack(cost);
    return 0;
  }
  
  if (cost * amount >= cap) {
    CompletePack(cost);
    return 0;
  }
  
  //dump(cost);
  //out(f, cap+1);
  for (int i = 0; i < cost; ++i) {
    int sum = 0; 
    l = r = 0;
    for (int v = i; v <= cap; v += cost) {
      while (l < r && r - l > amount) sum -= q[l++];
      //dump(l); dump(r); dump(v);
      sum += f[v];
      q[r++] = f[v];
      if (!f[v] && sum) f[v] = 1;
    }
    //out(q, r);
  }
  //out(f, cap+1);
  return 0;
}

int main() {
  #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  #endif
    
  int t;
  scanf("%d", &t);
  for (int ncase = 1; ncase <= t; ++ncase) {
    scanf("%d%d", &n, &m);
  //while (scanf("%d%d", &n, &m), m && n) {
    cap = m; ans = 0;
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < n; ++i) scanf("%d", &c[i]);
    CLR(f, 0); f[0] = 1;
    for (int i = 0; i < n; ++i)
      MutiplePack(a[i], c[i]);
       
    for (int i = 1; i <= m; ++i)
      if (f[i]) ++ans;
    printf("Case %d: %d\n", ncase, ans);
    //printf("%d\n", ans);
  }
  return 0;
}
