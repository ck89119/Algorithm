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

int str2int(string s) {
  istringstream is(s);
  int t;
  is >> t;
  return t;
}

string int2str(int a) {
  ostringstream os;
  os << a;
  return os.str();
}

struct Complex {
  int r, i;
  Complex() {}
  Complex(string s) {
    int idx = 0;
    while (idx < s.size() && s[idx] != '+') ++idx;
    r = str2int(s.substr(0, idx));
    i = str2int(s.substr(idx+1));
  }
  
  Complex operator * (const Complex &a) {
    Complex c;
    c.r = r * a.r - i * a.i;
    c.i = r * a.i + i * a.r;
    return c;
  }

  string to_str() {
    string ans;
    ans += int2str(r);
    ans += "+";
    ans += int2str(i);
    ans += "i";
    return ans;
  }
};

class Solution {
 public:
  string complexNumberMultiply(string a, string b) {
    Complex x = Complex(a);
    Complex y = Complex(b);
    Complex z = x * y;
    return z.to_str();
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  Solution s;
  cout << s.complexNumberMultiply("1+1i", "1+1i") << endl;
  cout << s.complexNumberMultiply("1+-1i", "1+-1i") << endl;
  return 0;
}
