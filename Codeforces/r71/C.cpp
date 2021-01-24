#include <bits/stdc++.h>
using namespace std;

#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define CLR(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0x80
#define MP(A, B) make_pair(A, B)
#define PB(A) push_back(A)
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(x) x & (-x)
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 100000 + 5;
const int M = 9999999;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

char b[10][15];
int n;
vector<int> s, e;

int len_t, len_p;
char t[N], *p;
int Next[N];

int getNext() {
  int k = -1;
  Next[0] = -1;
  for (int i = 0; i < len_p;)
    if (k == -1 || p[i] == p[k])
      Next[++i] = ++k;
    else
      k = Next[k];
  return 0;
}

int KMP_count() {
  int count = 0;
  int i, k;
  for (i = 0, k = 0; i < len_t; ++i) {
    if (k == -1 || t[i] == p[k]) {
      ++k;
    } else {
      k = Next[k];
      --i;
    }
    if (k >= len_p) {
      k = Next[k];
      s.push_back(i - len_p + 1);
      e.push_back(i);
      ++count;
    }
  }
  return count;
}


int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif
  int len[10];
  scanf("%s%d", t, &n);
  len_t = strlen(t);
  for (int i = 0; i < n; ++i) {
    scanf("%s", b[i]);
    len[i] = strlen(b[i]);
  }
  
  for (int i = 0; i < n; ++i) {
    p = b[i];
    len_p = len[i];
    getNext();
    KMP_count();
  }
  sort(s.begin(), s.end());  
  sort(e.begin(), e.begin());
  
  int ans = max(e[0] - 1, s[s.size()-1] - );
  int index = -1;
  for (int i = 0; i < s.size(); ++i) {
    int p = upper_bound(e.begin(), e.end(), s[i]) - e.begin();
    if (ans < e[p] - s[i] - 1) {
      ans = e[p] - s[i] - 1;
      index = 
    }
  }

  return 0;
}
