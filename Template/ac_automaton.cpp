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
const double PI= acos(-1.0);
const double EPS= 1e-11;
const int CHILD_NUM = 26;

struct AcAutomaton {
  int next[N][CHILD_NUM], fail[N];
  int end[N];
  int size, root;

  int NewNode() {
    memset(next[size], -1, sizeof(next[size]));
    end[size] = 0;
    return size++;
  }
  
  int Init() {
    size = 0;
    root = NewNode();
    return 0;
  }

  int Insert(char *s) {
    int cur = root;
    while (*s) {
      if (next[cur][*s-'a'] == -1) {
        next[cur][*s-'a'] = NewNode();
      }
      cur = next[cur][*s-'a'];
      ++s;
    }
    ++end[cur];
    //dump(cur);
    return 0;
  }

  int Build() {
    queue<int> q;
    fail[root] = root;
    for (int i = 0; i < CHILD_NUM; ++i)
      if (next[root][i] != -1) {
        fail[next[root][i]] = root;
        q.push(next[root][i]);
      } else {
        next[root][i] = root;
      }
    
    while (!q.empty()) {
      int cur = q.front(); q.pop();
      //end[cur] |= end[fail[cur]];
      for (int i = 0; i < CHILD_NUM; ++i) {
        if (next[cur][i] == -1) {
          next[cur][i] = next[fail[cur]][i];
        } else {
          fail[next[cur][i]] = next[fail[cur]][i];
          q.push(next[cur][i]);
        }
      }
    }
    return 0;
  }

  int work(char *s) {
    int ans = 0;
    int cur = root;
    while (*s) {
      //dump(*s); dump(cur);
      int v = next[cur][*s-'a'];
      cur = v;
      while (v) {
        ans += end[v];
        // end[v] = 0;
        v = fail[v];
      }
      ++s;
    }
    return ans;
  }

  int debug() {
    for(int i = 0; i < size; i++) {
      printf("id = %3d,fail = %3d,end = %3d,chi = [", i, fail[i], end[i]);
      for(int j = 0; j < 26; j++)
        printf("%2d", next[i][j]);
      printf("]\n");
    }
    return 0;
  }
};

AcAutomaton ac;

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    ac.Init();
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      char s[55];
      scanf("%s", s);
      ac.Insert(s);
    }
    ac.Build();
    //ac.debug();
    char str[1000005];
    scanf("%s", str);
    printf("%d\n", ac.work(str));
  }

  return 0;
}
