#include <bits/stdc++.h>
using namespace std;

#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0xc0
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

void quick_sort(vector<int> &a, int left, int right) {
  if (left >= right) {
    return ; 
  }

  int p = a[right];
  int l = left;
  int r = right;
  do {
    while (l < r && a[l] <= p) ++l;
    while (l < r && a[r] >= p) --r;
    swap(a[l], a[r]);
  } while(l < r);
  a[right] = a[l];
  a[l] = p;

  quick_sort(a, left, l - 1);
  quick_sort(a, l + 1, right);
}

vector<pair<int, int>> k_split(int n, int k) {
  vector<pair<int, int>> ans;
  int part_size = n / k;
  int r = n % k;
  for (int i = 0, offset = 0; i < k; ++i) {
    ans.emplace_back(offset, part_size + (i < r));  
    offset += part_size + (i < r);
  }
  return ans;
}

void merge_sort(vector<int> &a, int left, int right, int k) {
  int len = right - left;
  if (len <= 1) {
    return;
  }
  
  vector<pair<int, int>> sub_index = k_split(right - left, k);
  // for (auto [l, len] : sub_index) cout << l << " " << len << endl;
  priority_queue<tuple<int, int, int>> pq;
  for (int i = 0; i < sub_index.size(); ++i) {
    auto [l, len] = sub_index[i];
    merge_sort(a, left + l, left + l + len, k);

    if (len > 0) {
      pq.emplace(a[left+l], i, 1);
    }
  }
  
  vector<int> tmp;
  while (!pq.empty()) {
    auto [value, i, count] = pq.top(); pq.pop();
    tmp.push_back(value);

    auto [l, len] = sub_index[i];
    if (count < len) {
      pq.emplace(a[left+l+count], i, ++count);
    }
  }
  
  for (int i = 0; i < tmp.size(); ++i) {
    a[left + i] = tmp[i];
  }
  cout << "left = " << left << ", right = " << right << endl;
  out(a);
  cout << "=============\n"; 
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif
  vector<int> a = {2, 1, 5, 3, 4};
  // quick_sort(a, 0, 4);
  merge_sort(a, 0, 5, 2);
  out(a, 5);

  // auto a = k_split(11, 4);
  // for (auto [offset, len] : a) cout << offset << " " << len << endl;

  return 0;
}
