#include <iostream>
#include <cstdio>
using namespace std;

const int MAXN = (1 << 7) + 5;
double p[MAXN][MAXN];
double f[10][MAXN];

int main() {
  int n;
  while (scanf("%d", &n), n != -1) {
  	for (int i = 0; i < (1 << n); ++i)
  		for (int j = 0; j < (1 << n); ++j)
 				scanf("%lf", &p[i][j]);

 		for (int i = 0; i < (1 << n); ++i) f[0][i] = 1.0;
 		for (int i = 1; i <= n; ++i) {
 			int len = (1 << (i - 1));
 			for (int j = 0; j < (1 << n); ++j) {
 				int t = (j / len);
 				f[i][j] = 0.0;
 				if (t & 1) {
	 				for (int k = t*len - len; k < t*len; ++k)
	 					f[i][j] += f[i-1][j] * f[i-1][k] * p[j][k];			
 				} else { 					
	 				for (int k = t*len + len; k < t*len + 2*len; ++k)
	 					f[i][j] += f[i-1][j] * f[i-1][k] * p[j][k];			
 				}
 			}
 		}

 		double max_p = -1;
 		int ans;
 		for (int i = 0; i < (1 << n); ++i)
 			if (f[n][i] > max_p) {
 				max_p = f[n][i];
 				ans = i;
 			}
 		printf("%d\n", ans + 1);

  }
  return 0;
}