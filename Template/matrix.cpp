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
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

struct Matrix {
  int n, m;
  vector<vector<int>> data;

  Matrix(int _n, int _m) {
    n = _n;
    m = _m;
    data = vector<vector<int>>(n, vector<int>(m));
  }

  Matrix(vector<vector<int>> &&_data) : data(move(_data)) {
    n = data.size();
    m = data[0].size();
  }
  
  Matrix operator+(const Matrix &r) {
    Matrix m
  }

  Matrix operator-() {}
  Matrix operator*() {}
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  
  return 0;
}
