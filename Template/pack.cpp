/*
ID: ck891191
PROG:
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define dump(x) cerr<<__LINE__<<"  "<<#x<<"  :  "<<(x)<<endl;
#define two(X) (1<<(X))
#define towL(X) (((int64)(1))<<(x))
#define contain(S,X) ((S&two(X))>0)
#define containL(S,X) ((S&twoL(X))>0)
#define FR(i,a,b) for(int i=(a);i<(b);++i)//[a,b)
#define FOR(i,n) FR(i,0,n)//[0,n)
#define RF(i,a,b) for(int i=(a)-1;i>=(b);--i)//(a,b]
#define ROF(i,n) RF(i,n,0)//[0,n)
#define CL(a,x) memset(a,x,sizeof(a))

const int N = 1000 + 5;
const int V = 100000 + 5;
const int INF=(1<<30);
const double PI=acos(-1.0);
const double EPS=1e-11;

int c[N];
int f[V];
int n[N];

// O(N * V)
int ZeroOnePack(int cost, int value) {
  int v;
  for (v = V; v >= cost; --v)
    f[v] = max(f[v], f[v - cost] + value);
  return 0;
}

// O(N * V)
int CompletePack(int cost, int value) {
  int v;
  for (v = cost; v <= V; ++v)
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

int GroupPack(int cost, int value, int amount) {
  for (int i = V; i >= 0; --i)
    for (int j = 1; j <= amount; ++j)
      if (i >= j * cost)
        f[i] = max(f[i], f[i - j * cost] + j * value);
  return 0;
}

int main(){
  int i;
  for (i = 1; i <= N; i++){
    XXPack();
  }
  return 0;
}
