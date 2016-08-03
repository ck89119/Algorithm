#include <bits/stdc++.h>
#include "complex.cpp"
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
const double PI = acos(-1.0);

Complex* FFT(Complex* a, int n) {
  if (n == 1) {
    return a;
  }
  
  Complex w = Complex(1, 0);
  Complex w1 = Complex(cos(2 * PI / n), sin(2 * PI / n));
  Complex* a0 = new Complex[n >> 1];
  Complex* a1 = new Complex[n >> 1];
  for (int i = 0; i < n; ++i)
    if (i & 1) {
      a1[(i - 1) >> 1] = a[i]; 
    } else {
      a0[i >> 1] = a[i]; 
    }
  Complex* y0 = FFT(a0, n >> 1);
  Complex* y1 = FFT(a1, n >> 1);
  Complex* y = new Complex[n];
  for (int i = 0; i < (n >> 1); ++i) {
    y[i] = y0[i] + w * y1[i];
    y[i + (n >> 1)] = y0[i] - w * y1[i];
    w = w * w1;
  }
  return y;
}

Complex* InverseFFT(Complex* a, int n) {
  if (n == 1) {
    return a;
  }
  
  Complex w = Complex(1, 0);
  Complex w1 = w / Complex(cos(2 * PI / n), sin(2 * PI / n));
  Complex* a0 = new Complex[n >> 1];
  Complex* a1 = new Complex[n >> 1];
  for (int i = 0; i < n; ++i)
    if (i & 1) {
      a1[(i - 1) >> 1] = a[i]; 
    } else {
      a0[i >> 1] = a[i]; 
    }
  Complex* y0 = FFT(a0, n >> 1);
  Complex* y1 = FFT(a1, n >> 1);
  Complex* y = new Complex[n];
  for (int i = 0; i < (n >> 1); ++i) {
    y[i] = (y0[i] + w * y1[i]) / Complex(n, 0);
    y[i + (n >> 1)] = (y0[i] - w * y1[i]) / Complex(n, 0);
    w = w * w1;
  }
  return y;
}

int rev(int index, int len) {
  int result = 0;
  for (int i = 0; (1 << i) < len; ++i) {
    result <<= 1;
    if (index & (1 << i)) result |= 1;
  }
  return result;
}

Complex* IterativeFFT(Complex* a, int len, int DFT) {
  Complex* b = new Complex[len];
  for (int i = 0; i < len; ++i)
    b[rev(i, len)] = a[i];

  for (int i = 1; (1 << i) <= len; ++i) {
    int n = (1 << i);
    Complex w1 = Complex(cos(DFT * 2 * PI / n), sin(DFT * 2 * PI / n));
    for (int j = 0; j < len; j += n) {
      Complex w = Complex(1, 0);
      for (int k = 0; k < (n >> 1); ++k) {
        Complex u = b[k + j];
        Complex t = w * b[k + j + (n >> 1)];
        b[k + j] = u + t;
        b[k + j + (n >> 1)] = u - t;
        w = w * w1;
      }
    }
  }
  if (DFT == -1)
    for (int j = 0; j < len; ++j)
      b[j] = b[j] / Complex(len, 0);
  return b; 
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif
  Complex* a = new Complex[10];
  a[0] = Complex(0, 0);
  a[1] = Complex(1, 0);
  a[2] = Complex(2, 0);
  a[3] = Complex(3, 0);
  Complex* b = new Complex[10];
  Complex* c = new Complex[10];

  b = FFT(a, 4);
  cout << "<-------FFT------->" << endl;
  for(int i = 0; i < 4; i++)
    cout << b[i] << endl;
  c = InverseFFT(b, 4);
  cout << "<-------InverseFFT------->" << endl;
  for(int i = 0; i < 4; i++)
    cout << c[i] << endl;

  b = IterativeFFT(a, 4, 1);
  cout << "<------IterativeFFT------->" << endl;
  for(int i = 0; i < 4; i++)
    cout << b[i] << endl;
  c = IterativeFFT(b, 4, -1);
  cout << "<-------IterativeFFT------->" << endl;
  for(int i = 0; i < 4; i++)
    cout << c[i] << endl;
  return 0;
}
