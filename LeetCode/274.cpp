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

bool cmp(const int &a, const int &b) {
  return a > b;
}

class Solution {
 public:
  int hIndex(vector<int>& citations) {
    int n = citations.size();
    if (n == 0) return 0;

    sort(citations.begin(), citations.end(), cmp);
    if (citations[0] < 1) return 0;

    int l = 0;
    int r = n;
    while (l + 1 < r) {
      int m = (l + r) / 2;
      if (citations[m] >= m + 1) l = m;
      else r = m;
    }
    return r;
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  Solution s;
  vector<int> v;
  v.push_back(3);
  v.push_back(0);
  v.push_back(6);
  v.push_back(1);
  v.push_back(5);
  cout << s.hIndex(v) << endl;
  return 0;
}
