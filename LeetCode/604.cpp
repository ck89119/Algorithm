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

class StringIterator {
 public:
  int x, y;
  vector<pair<char, int>> v;

  int str2int(string s) {
    istringstream is(s);
    int t;
    is >> t;
    return t;
  }

  StringIterator(string compressedString) {
    for (int i = 0; i < compressedString.size(); ) {
      char ch = compressedString[i];
      int j = i + 1;
      while (j < compressedString.size() && compressedString[j] >= '0' && compressedString[j] <= '9')
        ++j;
      v.push_back(make_pair(ch, str2int(compressedString.substr(i+1, j-i-1))));
      i = j;
    }
    x = y = 0;
  }

  char next() {
    if (!hasNext()) return ' ';
    if (y >= v[x].second) {
      ++x;
      y = 0;
    }
    ++y;
    return v[x].first;
  }

  bool hasNext() {
    return !(x == v.size() - 1 && y == v[x].second);
  }
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator obj = new StringIterator(compressedString);
 * char param_1 = obj.next();
 * bool param_2 = obj.hasNext();
 */
int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  
  return 0;
}
