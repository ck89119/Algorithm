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
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i];cout<<endl;}
const int N = 101;
const int M = 103;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

bool check(const vector<vector<int>> &count) {
  for (int i = 0; i < N; ++i) {
    int j = 0; 
    while (j < M && count[i][j] == 0) ++j;
     
    int s = j;     
    while (j < M && count[i][j] != 0) ++j;
    if (j - s >= 8) return true;
  }    
  return false;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  vector<int> x, y, vx, vy;

  int a, b, c, d;
  while (scanf("p=%d,%d v=%d,%d\n", &a, &b, &c, &d) != EOF) {
    x.push_back(a); 
    y.push_back(b); 
    vx.push_back(c); 
    vy.push_back(d); 
  }

  for (int step = 1; ; ++step) {
    dump(step);
    vector<vector<int>> count(N, vector<int>(M));
    for (int i = 0; i < x.size(); ++i) {
      int nx = ((x[i] + vx[i] * step) % N + N) % N;
      int ny = ((y[i] + vy[i] * step) % M + M) % M;
      count[nx][ny] += 1;
    }

    if (step > 6000 && check(count)) {
      for (int i = 0; i < N; ++i) out(count[i]);
      return 0;
    }
  }
}
