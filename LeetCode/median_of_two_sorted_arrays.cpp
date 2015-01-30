/*
ID: ck89119
PROG:
LANG: C++
*/
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
using namespace std;
#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl;
#define FR(i,a,b) for(int i=(a);i<(b);++i)//[a,b)
#define CLR(a,x) memset(a,x,sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0x80
#define MP(A,B) make_pair(A,B)
#define PB(A) push_back(A)
#define PAU system("pause");
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(n) (n^(n-1))&n
#define fin freopen(".in","r",stdin);
#define fout freopen(".out","w",stdout);
//ifstream fin("");
//ofstream fout("");
#define LL long long

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out (vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int MAXN=99999;
const int MAXM=9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;

class Solution {
public:
  int find_kth_ele(int a[], int end_a, int start_a, int b[], int end_b, int start_b, int k) {
    int len_a = end_a - start_a + 1;
    int len_b = end_b - start_b + 1;
    if (len_a == 0) return b[start_b+k];
    if (len_b == 0) return a[start_a+k];
    if (k == 0) return a[start_a] < b[start_b] ? a[start_a] : b[start_b];
    int mid_a = k * len_a / (len_a + len_b);
    int mid_b = k - mid_a - 1;
    mid_a += start_a;
    mid_b += start_b;
    //dump(start_a) dump(end_a) dump(start_b) dump(end_b)
    //dump(mid_a) dump(mid_b)
    if (a[mid_a] > b[mid_b]) {
      k -= (mid_b - start_b + 1);
      end_a = mid_a;
      start_b = mid_b + 1;
    }
    else {
      k -= (mid_a - start_a + 1);
      end_b = mid_b;
      start_a = mid_a + 1;
    }
    return find_kth_ele(a, end_a, start_a, b, end_b, start_b, k);
  }

  double findMedianSortedArrays(int A[], int m, int B[], int n) {
    if ((m + n) % 2) return find_kth_ele(A, m-1, 0, B, n-1, 0, (m+n)/2);
    else return (find_kth_ele(A, m-1, 0, B, n-1, 0, (m+n)/2-1) + 
                 find_kth_ele(A, m-1, 0, B, n-1, 0, (m+n)/2)) * 0.5;
  }
};

int main() {
  Solution s;  
  int a[3] = {2,3,4};
  int b[1] = {1};
  cout << s.findMedianSortedArrays(a, 3, b, 1) << endl;
  ios :: sync_with_stdio(false);
  cout << fixed << setprecision(16);
  return 0;
}

