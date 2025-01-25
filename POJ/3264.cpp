#include <iostream>
#include <cstdio>
using namespace std;

const int M = 50001;
int val[M];
int Max[20][M];
int Min[20][M];
int idx[M];

int initRMQ(int n) {
  int i, j;
  idx[0] = -1;
  for (i = 1; i <= n; i++) {
    idx[i] = (i&(i-1)) ? idx[i-1] : idx[i-1] + 1;
    Min[0][i] = Max[0][i] = val[i];
  }
  for (i = 1; i <= idx[n]; i++) {
    int limit = n + 1 - (1<<i);
    for (j = 1; j <= limit; j++) {
      Min[i][j] = min(Min[i-1][j], Min[i-1][j+(1<<(i-1))]);
      Max[i][j] = max(Max[i-1][j], Max[i-1][j+(1<<(i-1))]);
    }
  }
  return 0;
}

int getval(int a,int b) {
  int t = idx[b-a+1];
  b -= (1<<t) - 1;
  return max(Max[t][a], Max[t][b]) - min(Min[t][a], Min[t][b]);
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  int n, m;
  int i;
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++) {
    scanf("%d", &val[i]);
  }
  initRMQ(n);
  while (m--) {
    int a, b ;
    scanf("%d%d", &a, &b);
    printf("%d\n", getval(a,b));
  }
  return 0;
}
