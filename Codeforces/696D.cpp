#include <bits/stdc++.h>
using namespace std;

#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0xc0
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
const int N = 200 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
const int CHILD_NUM = 26;

ll n, l;

struct AC_automaton {
  int next[N][CHILD_NUM], fail[N], value[N];
  int size, root;
  
  int NewNode() {
    clr(next[size], -1);
    fail[size] = -1;
    value[size] = 0;
    return size++;
  }

  int Init() {
    size = 0;
    root = NewNode();
    return 0;
  }
  
  int Insert(const char* s, int v) {
    int cur = root;
    while (*s) {
      int u = *s - 'a';
      if (next[cur][u] == -1) {
        next[cur][u] = NewNode();
      }
      cur = next[cur][u];
      ++s;
    }
    value[cur] += v;
    return 0;
  }
  
  int Build() {
    queue<int> q;
    fail[root] = root;
    for (int i = 0; i < CHILD_NUM; ++i) {
      int v = next[root][i];
      if (v == -1) {
        next[root][i] = root;
      } else {
        fail[v] = root;
        q.push(v);
      }
    }

    while (!q.empty()) {
      int node = q.front(); q.pop();
      value[node] += value[fail[node]];
      for (int i = 0; i < CHILD_NUM; ++i) {
        int v = next[node][i];
        if (v == -1) {
          next[node][i] = next[fail[node]][i];
        } else {
          fail[v] = next[fail[node]][i];
          q.push(v);
        }
      }
    }
    return 0;
  }

  int debug() {
    return 0; 
  }
};
AC_automaton ac;

struct Matrix {
  int n;
  ll data[N][N];

  Matrix() {}

  Matrix(int _n) {
   n = _n;
   clr(data, 0xc0);
  }

  Matrix operator * (const Matrix& a) {
    Matrix b(n);
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        for (int k = 0; k < n; ++k)
            b.data[i][j] = max(b.data[i][j], data[i][k] + a.data[k][j]);
    return b; 
  }
};

Matrix Matrix_pow(Matrix& a, ll n) {
  if (n == 1) return a;

  Matrix b = Matrix_pow(a, n >> 1);
  if (n & 1) return b * b * a;
  else return b * b;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif
  int a[N];
  scanf("%I64d%I64d", &n, &l);
  for (int i = 0; i < n; ++i)
    scanf("%d", &a[i]);

  ac.Init();
  for (int i = 0; i < n; ++i) {
    char s[N];
    scanf("%s", s);
    ac.Insert(s, a[i]);
  }
  ac.Build();
  
  Matrix m(ac.size);
  for (int i = 0; i < ac.size; ++i)
    for (int j = 0; j < CHILD_NUM; ++j) {
      int k = ac.next[i][j];
      m.data[i][k] = ac.value[k];
    }
  m = Matrix_pow(m, l); 
  
  ll ans = 0;
  for (int i = 0; i < ac.size; ++i)
    ans = max(ans, m.data[ac.root][i]);
  printf("%I64d\n", ans);
  return 0;
}
