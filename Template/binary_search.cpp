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
#include <ctime>
using namespace std;
#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl
#define FR(i,a,b) for(int i=(a);i<(b);++i)//[a,b)
#define CLR(a,x) memset(a,x,sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0x80
#define MP(A,B) make_pair(A,B)
#define PB(A) push_back(A)
#define PAU system("pause")
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(x) x & (-x)
#define fin freopen(".in","r",stdin)
#define fout freopen(".out","w",stdout)
//ifstream fin("");
//ofstream fout("");
#define LL long long
#define ULL unsigned long long

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out (vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int MAXN=99999;
const int MAXM=9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;
const int CHILD_NUM = 26;
const int MOD = 1000000007;

int binary_search_lower_bound(int arr[], int left, int right, int t) {   //[left, right)
  while (left < right) {
    int mid = (left + right) >> 1;
    if (arr[mid] >= t) right = mid;
    else left = mid + 1;
  }
  return right;
}

int binary_search_upper_bound(int arr[], int left, int right, int t) {   //[left, right)
  while (left < right) {
    int mid = (left + right) >> 1;
    if (arr[mid] > t) right = mid;
    else left = mid + 1;
  }
  return right;
}

// int binary_search_upper_bound(int arr[], int left, int right, int t) {   //(left, right]
//   while (left < right) {
//     int mid = (left + right + 1) >> 1;
//     if (arr[mid] <= t) left = mid;
//     else right = mid - 1;
//   }
//   return right;
// }

int binary_search_upper_bound_1(int arr[], int left, int right, int t) {  //[left, right)
  if (arr[left] > t) return left - 1;
  int p = 1;
  while (p <= right - left) p <<= 1; p >>= 1;
  for (int i = p; i > 0; i >>= 1) {
    int j = left + i;
    if (j < right && arr[j] <= t) left = j;
  }
  return left;
}

int binary_search_lower_bound_1(int arr[], int left, int right, int t) {  //(left, right]
  if (arr[right] < t) return right + 1;
  int p = 1;
  while (p <= right - left) p <<= 1; p >>= 1;
  for (int i = p; i > 0; i >>= 1) {
    int j = right - i;
    if (j > left && arr[j] >= t) right = j; 
  }
  return right;
}

int binary_search(int arr[], int left, int right, int t) {   //[left, right)
  while (left < right) {
    int mid = (left + right) >> 1;
    if (arr[mid] == t) return mid;
    if (arr[mid] < t) left = mid + 1;
    else right = mid;
  }
  return -1;
}

int main() {
  //fin; fout;
  int arr[5] = {-3, -2, 1};
  int target;
  while (cin >> target) {
    //cout << binary_search(arr, 0, 5, target) << endl; 
    // cout << binary_search_lower_bound(arr, 0, 5, target) << endl; 
    cout << binary_search_upper_bound(arr, 0, 3, target) << endl; 
  }
  return 0;
}
