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
const int N = 100 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

vector<int> v(64, -1); 
vector<int> ops;

ll dfs(int cur) {
  // dump(cur);
  if (cur == ops.size()) {
    ll ans = 0;
    for (int i = v.size() - 1; i >= 0; --i) ans = ans * 2 + v[i];
    printf("%lld\n", ans);
    return 0;
  }

  int op0 = ops[cur] & 0x1, op1 = ops[cur] >> 1 & 0x1, op2 = ops[cur] >> 2 & 0x1;
  for (int s = 0; s < 8; ++s) {
    int s0 = s & 0x1, s1 = s >> 1 & 0x1, s2 = s >> 2 & 0x1;

    int i = cur * 3;
    int v0 = v[i], v1 = v[i+1], v2 = v[i+2];
    if (v0 != -1 && v0 != s0) continue;
    if (v1 != -1 && v1 != s1) continue;
    if (v2 != -1 && v2 != s2) continue;
    v[i] = s0, v[i+1] = s1, v[i+2] = s2;

    int shift = 7 - s;
    if (i + shift + 2 >= 3 * ops.size()) {
      v[i] = v0, v[i+1] = v1, v[i+2] = v2;
      continue;   
    }

    int vs0 = v[i+shift], vs1 = v[i+1+shift], vs2 = v[i+2+shift];
    int xor0 = op0 ^ s0, xor1 = op1 ^ s1, xor2 = op2 ^ s2;
    if (vs0 != -1 && vs0 != xor0) {
      v[i] = v0, v[i+1] = v1, v[i+2] = v2;
      continue;   
    }
    if (vs1 != -1 && vs1 != xor1) {
      v[i] = v0, v[i+1] = v1, v[i+2] = v2;
      continue;   
    }
    if (vs2 != -1 && vs2 != xor2) {
      v[i] = v0, v[i+1] = v1, v[i+2] = v2;
      continue;   
    }
    
    v[i+shift] = xor0, v[i+1+shift] = xor1, v[i+2+shift] = xor2;
    // dump(s);
    // cout << "v[" << i << "] = " << v[i] << ", v[" << i+1 << "] = " << v[i+1] << ", v[" << i+2 << "] = " << v[i+2] << endl;
    // cout << "v[" << i+shift << "] = " << v[i+shift] << ", v[" << i+shift+1 << "] = " << v[i+shift+1] << ", v[" << i+shift+2 << "] = " << v[i+shift+2] << endl;
    dfs(cur+1);
    v[i+shift] = vs0, v[i+1+shift] = vs1, v[i+2+shift] = vs2;
    v[i] = v0, v[i+1] = v1, v[i+2] = v2;
  }
  return 0;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  int a, b, c;
  char s[N];
  scanf("Register A: %d\n", &a);  
  scanf("Register B: %d\n", &b);  
  scanf("Register C: %d\n", &c);  
  scanf("\nProgram: %s\n", s);  
  // dump(a),
  // dump(b),
  // dump(c),
  // dump(s);

  for (int i = 0; i < strlen(s); i += 4) {
    ops.emplace_back(s[i]-'0');
    ops.emplace_back(s[i+2]-'0');
  }
  out(ops);
  
  dfs(0);
  return 0;
}
