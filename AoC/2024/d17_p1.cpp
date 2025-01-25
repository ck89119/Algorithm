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

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  ll a, b, c;
  char s[N];
  scanf("Register A: %lld\n", &a);  
  scanf("Register B: %lld\n", &b);  
  scanf("Register C: %lld\n", &c);  
  scanf("\nProgram: %s\n", s);  
  // dump(a),
  // dump(b),
  // dump(c),
  // dump(s);

  vector<int> ops;
  for (int i = 0; i < strlen(s); i += 4) {
    ops.emplace_back(s[i]-'0');
    ops.emplace_back(s[i+2]-'0');
  }
  
  auto get_value_from_oprand = [&](int oprand) -> int {
    if (oprand < 4) return oprand;
    if (oprand == 4) return a;
    if (oprand == 5) return b;
    if (oprand == 6) return c;
    return oprand;
  };

  auto adv = [&](int oprand) {
    auto v = get_value_from_oprand(oprand);
    a = a >> v;
  };

  auto bxl = [&](int oprand) {
    auto v = get_value_from_oprand(oprand);
    b ^= v;
  };

  auto bst = [&](int oprand) {
    auto v = get_value_from_oprand(oprand);
    b = v & 0x7;
  };
  
  auto jnz = [&](int oprand, int i) -> int {
    auto v = get_value_from_oprand(oprand);
    return a == 0 ? i : v - 2;
  };
  
  auto bxc = [&]() {
    b ^= c;
  };
   
  auto out = [&](int oprand) {
    auto v = get_value_from_oprand(oprand);
    cout << (v & 0x7) << ",";
  };
  
  auto bdv = [&](int oprand) {
    auto v = get_value_from_oprand(oprand);
    b = a >> v;
  };

  auto cdv = [&](int oprand) {
    auto v = get_value_from_oprand(oprand);
    c = a >> v;
  };
  
  for (int i = 0; i < ops.size(); i += 2) {
    auto opcode = ops[i];     
    auto oprand = ops[i+1];     

    if (opcode == 0) {
      adv(oprand);
    } else if (opcode == 1) {
      bxl(oprand);
    } else if (opcode == 2) {
      bst(oprand);
    } else if (opcode == 3) {
      i = jnz(oprand, i);
    } else if (opcode == 4) {
      bxc();
    } else if (opcode == 5) {
      out(oprand);
    } else if (opcode == 6) {
      bdv(oprand);
    } else if (opcode == 7) {
      cdv(oprand);
    }
  }
  cout << endl;
  return 0;
}
