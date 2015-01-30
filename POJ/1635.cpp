#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int MOD = 9997;
int n, h[10005];
char a[3005], *p;

int init() {
  int i;
  for (i = 0; i < 10000; ++i)
    h[i] = rand() % MOD;
  return 0;
}

int hashing(int i) {
  int sum = h[i];
  while (*p && *p++ == '0') {
    sum = (sum + hashing(i+1) * h[i]) % MOD;
  }
  return sum * sum % MOD; 
}

int main() {
  scanf("%d", &n);
  init();
  while (n--) {
    int n1, n2;
    scanf("%s", a);
    p = a;
    n1 = hashing(0);
    scanf("%s", a);
    p = a;
    n2 = hashing(0);
    //cout << n1 << " " << n2 << endl;
    if (n1 == n2) printf("same\n");
    else printf("different\n");
  }
  return 0;
}
