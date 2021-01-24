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
const int N = 140000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
const double PI = acos(-1.0);
const double EPS = 1e-11;

class Complex {
 public:
  Complex() {};
  Complex(double real, double image): real_(real), image_(image) {};
  Complex operator + (const Complex& a);
  Complex operator - (const Complex& a);
  Complex operator * (const Complex& a);
  Complex operator / (const Complex& a);
  friend std::ostream& operator << (std::ostream& out, const Complex& a) {
    out << a.real_ << " + " << a.image_ << "i";
    return out;
  }
  double real_, image_;
  
};

Complex Complex::operator + (const Complex& a) {
  return Complex(real_ + a.real_, image_ + a.image_);
}

Complex Complex::operator - (const Complex& a) {
  return Complex(real_ - a.real_, image_ - a.image_);
}

Complex Complex::operator * (const Complex& a) {
  return Complex(real_ * a.real_ - image_ * a.image_, real_ * a.image_ + a.real_ * image_);
}

Complex Complex::operator / (const Complex& a) {
  double s = a.real_ * a.real_ + a.image_ * a.image_;
  return Complex((real_ * a.real_ + image_ * a.image_) / s, (image_ * a.real_ - real_ * a.image_) / s);
}

int rev(int index, int len) {
  int ans = 0;
  for (int i = 0; (1 << i) < len; ++i) {
    ans <<= 1;
    if (index & (1 << i)) ans |= 1;
  }
  return ans;
}

int FFT(Complex* a, int len, int DFT) {
  Complex b[N];
  for (int i = 0; i < len; ++i)
    b[rev(i, len)] = a[i];

  for (int i = 0; (1 << i) <= len; ++i) {
    int n = (1 << i);
    Complex w1 = Complex(cos(DFT * 2 * PI / n), sin(DFT * 2 * PI / n));
    for (int j = 0; j < len; j += n) {
      Complex w = Complex(1, 0);
      for (int k = 0; k < (n >> 1); ++k) {
        Complex u = b[j + k];
        Complex t = w * b[j + k + (n >> 1)];
        b[j + k] = u + t;
        b[j + k + (n >> 1)] = u - t;
        w = w * w1;
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


Complex ca[N], cb[N]; 
char sa[N], sb[N];

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif
  while (scanf("%s", sa) != EOF) {
    scanf("%s", sb);
    int la = strlen(sa);
    int lb = strlen(sb);
    int len = 0;
    while ((1 << len) < la + lb - 1) ++len;
    len = (1 << len);
    // dump(sa);dump(sb);dump(len);

    for (int i = 0; i < len; ++i) {
      if (i < la) ca[i] = Complex(sa[la-1-i] - '0', 0);
      else ca[i] = Complex(0, 0);
      if (i < lb) cb[i] = Complex(sb[lb-1-i] - '0', 0);
      else cb[i] = Complex(0, 0);
    }
    
    FFT(ca, len, 1);
    FFT(cb, len, 1);
    
    for (int i = 0; i < len; ++i)
      ca[i] = ca[i] * cb[i];
    
    FFT(ca, len, -1);

    int ans[N];
    for (int i = 0; i < len; ++i)
      ans[i] = (int)(ca[i].real_ + 0.5);
    for (int i = 0; i < len - 1; ++i) {
      ans[i+1] += ans[i] / 10;
      ans[i] %= 10;
    }

    int flag = 0;
    for (int i = len - 1; i >= 0; --i)
      if (!flag && ans[i] == 0 && i) continue;
      else {
        flag = 1;
        printf("%d", ans[i]);
      }
    printf("\n");
  } 
  return 0;
}
