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
const int M = 270000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
const double PI = acos(-1.0);

class Complex {
 public:
  double real_, image_;
  Complex() {};
  Complex(double real, double image): real_(real), image_(image) {};
  Complex operator + (const Complex& a) { return Complex(real_ + a.real_, image_ + a.image_); }
  Complex operator - (const Complex& a) { return Complex(real_ - a.real_, image_ - a.image_); }
  Complex operator * (const Complex& a) { return Complex(real_ * a.real_ - image_ * a.image_, real_ * a.image_ + image_ * a.real_); }
  Complex operator / (const Complex& a) {
    double s2 = a.real_ * a.real_ + a.image_ * a.image_;
    return Complex((real_ * a.real_ + image_ * a.image_) / s2, (-real_ * a.image_ + image_ * a.real_) / s2);
  }
  friend std::ostream& operator << (std::ostream& out, const Complex& a) {
    out << "(" << a.real_ << " + " << a.image_ << "i" << ")";
    return out;
  }
};

int n;
int l[N];
int num[N];
Complex c[M], b[M];

int rev(int index, int len) {
  int ans = 0;
  for (int i = 0; (1 << i) < len; ++i) {
    ans <<= 1;
    if (index & (1 << i)) ans |= 1;
  }
  return ans;
}

int FFT(Complex* a, int len, int DFT) {
  for (int i = 0; i < len; ++i)
    b[rev(i, len)] = a[i];

  for (int i = 1; (1 << i) <= len; ++i) {
    int n = (1 << i);
    Complex wn = Complex(cos(-DFT * 2 * PI / n), sin(-DFT * 2 * PI / n));
    for (int j = 0; j < len; j += n) {
      Complex w = Complex(1, 0);
      for (int k = 0; k < (n >> 1); ++k) {
        Complex u = b[j + k];
        Complex t = w * b[j + k + (n >> 1)];
        b[j + k] = u + t;
        b[j + k + (n >> 1)] = u - t;
        w = w * wn;
      }
    }
  }

  if (DFT == -1)
    for (int i = 0; i < len; ++i)
      b[i] = b[i] / Complex(len, 0);
  for (int i = 0; i < len; ++i)
    a[i] = b[i];
  return 0;
}

int Conv(Complex* a, int len) {
  FFT(a, len, 1);
  for (int i = 0; i < len; ++i)
    a[i] = a[i] * a[i];
  FFT(a, len, -1);
  return 0;
}

int solve() {
  sort(l, l + n);
  int max_l = l[n-1] + 1;
  int len = 1;
  while (len < max_l + max_l - 1) len <<= 1;
  for (int i = 0; i < len; ++i)
    if (i < max_l) c[i] = Complex(num[i], 0);
    else c[i] = Complex(0, 0);

  Conv(c, len);

  ll ans[M];
  for (int i = 0; i < len; ++i)
    ans[i] = (ll)(c[i].real_ + 0.5);
  for (int i = 0; i < n; ++i)
    --ans[l[i]+l[i]];
  for (int i = 0; i < len; ++i)
    ans[i] /= 2;

  ll sum[M];
  sum[0] = ans[0];
  for (int i = 1; i < len; ++i)
    sum[i] = sum[i-1] + ans[i];
  ll cnt = 0;
  for (int i = 0; i < n; ++i) {
    cnt += sum[len-1] - sum[l[i]];
    cnt -= (ll)(n - i - 1) * i;
    cnt -= (ll)(n - i - 1) * (n - i - 2) / 2;
    cnt -= (ll)(n - 1);
  }
  ll total = (ll)n * (n-1) * (n-2) / 6;
  printf("%.7lf\n", (double)cnt / total);
  return 0;
}


int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    clr(num, 0);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &l[i]);
      ++num[l[i]];
    }
    solve();
  }

  return 0;
}
