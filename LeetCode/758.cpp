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

class Solution {
 public:
  string boldWords(vector<string>& words, string S) {
    int n = S.size();
    vector<bool> v(n, false);
    for (int i = 0; i < n; ++i) {
      for (auto &word: words) {
        int f = true;
        for (int k = 0; k < word.size(); ++k)
          if (word[k] != S[i+k]) {
            f = false;
            break;
          }
        if (f) {
          for (int k = 0; k < word.size(); ++k) v[i+k] = true;
        }
      } 
    }

    string ans;
    for (int i = 0; i < n; )
      if (!v[i]) {
        ans += S[i++];
      } else {
        ans += "<b>";
        while (i < n && v[i]) ans += S[i++];
        ans += "</b>";
      }
    return ans;
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  
  return 0;
}
