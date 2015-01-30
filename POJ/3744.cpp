/*
ID: ck89119
PROG:
LANG: C++
*/
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
using namespace std;
#define FR(i,a,b) for(int i=(a);i<(b);++i)//[a,b)
#define CLR(a,x) memset(a,x,sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0x80
#define MP(A,B) make_pair(A,B)
#define PB(A) push_back(A)
#define PAU system("pause")
#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(n) (n^(n-1))&n
#define fin freopen(".in","r",stdin)
#define fout freopen(".out","w",stdout)
//ifstream fin("");
//ofstream fout("");
#define LL long long

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out (vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int MAXN=99999;
const int MAXM=9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;
const int CHILD_NUM = 26;
const int MOD = 1000000007;

struct Matrix {
  double mat[2][2];

  Matrix() {
    //CLR(mat, 0);
    mat[0][0] = mat[0][1] = 0.0;
    mat[1][0] = mat[1][1] = 0.0;
  }
  
  Matrix operator*(const Matrix &a) const {
    Matrix ans;
    for (int i = 0; i < 2; ++i)
      for (int j = 0; j < 2; ++j)
        for (int k = 0; k < 2; ++k)
          ans.mat[i][j] += mat[i][k] * a.mat[k][j];
    return ans;
  }
};

Matrix pow_m(const Matrix &a, int n) {
  Matrix ans;
  ans.mat[0][0] = ans.mat[1][1] = 1;
  Matrix tmp = a;
  while (n) {
    if (n & 1) ans = ans * tmp;
    tmp = tmp * tmp;
    n >>= 1;
  }
  return ans;
}

int n, pos[15];
double p;
Matrix m;

int main() {
  //fin; fout;
  while (scanf("%d%lf", &n, &p) != EOF) {
    for (int i = 0; i < n; ++i) scanf("%d", &pos[i]);
    sort(pos, pos+n);
    if (pos[0] == 1) {
      printf("%.7f\n", 0.0);
      continue;
    }

    m.mat[0][0] = p; m.mat[0][1] = 1-p;
    m.mat[1][0] = 1; m.mat[1][1] = 0;
    
    Matrix tmp;
    int pre = 1;
    double ans = 1.0;
    tmp = pow_m(m, pos[0]-1-pre);
    ans *= (1-p) * tmp.mat[0][0];
    pre = pos[0] + 1;

    for (int i = 1; i < n; ++i) {
      if (pos[i] == pos[i-1]) continue;
      if (pos[i] == pos[i-1] + 1) {
        ans = 0.0;
        break;
      }
      tmp = pow_m(m, pos[i]-1-pre);
      ans *= (1-p) * tmp.mat[0][0];
      pre = pos[i]+1;
    }
    printf("%.7f\n", ans);
  }
  return 0;
}
