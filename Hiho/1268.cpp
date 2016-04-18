#include <bits/stdc++.h>
using namespace std;

#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0x80
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(x) x & (-x)
#define X first 
#define Y second
typedef long long ll;
typedef pair<int, int> pii;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 100000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int mat[3][3];
int ans[3][3], ans_num;
int vis[10];

int check() {
  int sum;
  for (int i = 0; i < 3; ++i) {
    sum = 0;
    for (int j = 0; j < 3; ++j)
      sum += mat[i][j];
    if (sum != 15) return 0; 
  }

  for (int i = 0; i < 3; ++i) {
    sum = 0;
    for (int j = 0; j < 3; ++j)
      sum += mat[j][i];
    if (sum != 15) return 0; 
  }
  
  sum = 0;
  for (int i = 0; i < 3; ++i)
    sum += mat[i][i];
  if (sum != 15) return 0; 

  sum = 0;
  for (int i = 0; i < 3; ++i)
    sum += mat[i][2-i];
  if (sum != 15) return 0; 

  return 1;
}

int dfs(int x, int y) {
  //printf("%d %d\n", x, y);
  if (ans_num > 1) return 0;
  if (x >= 3) {
      //for (int i = 0; i < 3; ++i) {
        //for (int j = 0; j < 3; ++j)
          //printf("%d ", mat[i][j]);
        //printf("\n");
      //}
      //printf("+++++++++++\n");
    if (check()) {
      for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
          ans[i][j] = mat[i][j];
      ++ans_num;

    }
    return 0;
  }

  if (mat[x][y]) {
    dfs(x + (y + 1) / 3, (y + 1) % 3);
  } else {
    for (int i = 1; i <= 9; ++i)
      if (!vis[i]) {
        mat[x][y] = i;
        vis[i] = 1;
        dfs(x + (y + 1) / 3, (y + 1) % 3);
        vis[i] = 0;
        mat[x][y] = 0;
      }
  }
  return 0;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif
  clr(vis, 0);
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j) {
      scanf("%d", &mat[i][j]);
      vis[mat[i][j]] = 1;
    }
  //out(vis, 10);
  ans_num = 0;
  dfs(0, 0);
  if (ans_num == 1) {
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j)
        printf("%d ", ans[i][j]);
      printf("\n");
    }
  } else {
    printf("Too Many\n");
  }
  return 0;
}
