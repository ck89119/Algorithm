#include <iostream>
using namespace std;

int f[105][15][35];
int month_len[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int y, m, d;

int is_leap(int y) {
  if (y % 400 == 0) return 1;
  else if (y % 4 == 0 && y % 100 != 0) return 1;
  else return 0;
}

int check_day(int yy, int mm, int dd) {
  if (mm == 2) month_len[1] += is_leap(yy);
  if (dd < 1 || dd > month_len[mm-1]) return 0;
  if (mm < 1 || mm > 12) return 0;
  if (yy < 0 || yy > 101) return 0;
  if (yy == 101) {
    if (mm > 11 || (mm == 11 && dd > 4)) return 0;
  }
  month_len[1] = 28;
  return 1;
}

int next_day(int &yy, int &mm, int &dd) {
  dd++;
  month_len[1] += is_leap(yy);
  if (dd > month_len[mm-1]) {dd = 1; mm++;}
  if (mm > 12) {mm = 1; yy++;}
  month_len[1] = 28;
  return 0;
}

int next_month(int &yy, int &mm, int &dd) {
  mm++;
  if (mm > 12) {mm = 1; yy++;}
  return check_day(yy, mm, dd);
}

int mem_search(int yy, int mm, int dd) {
  if (f[yy][mm][dd] != -1) return f[yy][mm][dd];
  
  int ty, tm, td;
  ty = yy; tm = mm; td = dd;
  next_day(ty, tm, td);
  if (f[ty][tm][td] == -1) 
    f[ty][tm][td] = mem_search(ty, tm, td);
  if (f[ty][tm][td] == 0) {
    f[yy][mm][dd] = 1;
    return 1;
  }
  
  ty = yy; tm = mm; td = dd;
  if (next_month(ty, tm, td)) {
    if (f[ty][tm][td] == -1)
      f[ty][tm][td] = mem_search(ty, tm, td);
    if (f[ty][tm][td] == 0) {
      f[yy][mm][dd] = 1;
      return 1;
    }
  }

  return f[yy][mm][dd] = 0;
}

int main() {
  int t;
  int i, j, k;
  memset(f, -1, sizeof(f));
  f[101][11][4] = 0;
  for (i = 101; i >= 0; --i)
    for (j = 12; j >= 1; --j)
      for (k = 31; k >= 1; --k)
        if(check_day(i, j, k))
          f[i][j][k] = mem_search(i, j, k);

  scanf("%d", &t);
  while (t--) {
    scanf("%d%d%d", &y, &m, &d);
    if (f[y-1900][m][d] == 1) printf("YES\n");
    else printf("NO\n");
  }
  return 0;
}
