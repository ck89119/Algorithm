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
const int N = 200000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int a[N], c[N];
pii b[N];
int n, m;

bool cmp(const int a, const int b) {
  return a > b;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i)
    scanf("%d", &a[i]);

  int len = 0;
  for (int i = 0; i < m; ++i) {
    int t, r;
    scanf("%d%d", &t, &r);
    while (len > 0 && b[len-1].second <= r) --len;
    b[len++] = mp(t, r);
  }

  int j = 0;
  for (int i = 0; i < len; ++i) {
     if (j != 0 && b[i].first == b[j-1].first) continue;
     b[j++] = b[i];
  }

  len = j;
  if (len == 0) {
    for (int i = 0; i < n; ++i)
      printf("%d ", a[i]);
    printf("\n");
    return 0;
  }
  
  if (b[0].first == 1) 
    sort(a, a+b[0].second);
  else 
    sort(a, a+b[0].second, cmp);
 
  for (int i = b[0].second; i < n; ++i)
    c[i] = a[i];

  int left = 0;
  int right = b[0].second;
  int cur = b[0].second;

  // dump("b = ");
  // for (int i = 0; i < len; ++i)
  //   cout << b[i].first << ' ' << b[i].second << endl;


  b[len] = mp(0, 0);
  for (int i = 0; i < len; ++i) {
    int l = b[i].second - b[i+1].second;
    if (i & 1) {
      for (int j = 0; j < l; ++j)
        c[cur-1-j] = a[left+j];
      left += l; 
    } else {
      for (int j = 0; j < l; ++j)
        c[cur-l+j] = a[right-l+j];
      right -= l;
    }
    cur -= l;
    // out(c, n);
  }
  // dump(cur);  
  // out(c, n);
  for (int i = 0; i < n; ++i)
    printf("%d ", c[i]);
  printf("\n"); 
  
  return 0;
}
