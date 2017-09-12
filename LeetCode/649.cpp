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
  string predictPartyVictory(string senate) {
    int n = senate.size();
    vector<bool> available(n, true);
    set<char> s;
    while (true) {
      s.clear();
      for (int i = 0; i < n; ++i)
        if (available[i]) s.insert(senate[i]);
      if (s.size() == 1) break;

      for (int i = 0; i < n; ++i) {
        if (!available[i]) continue;
        char ch = senate[i];
        if (ch == 'R') {
          for (int j = i+1; j < n+i; ++j) {
            if (senate[j%n] == 'D' && available[j%n]) {
              available[j%n] = false;
              break;
            }
          } 
        } else {
          for (int j = i+1; j < n+i; ++j) {
            if (senate[j%n] == 'R' && available[j%n]) {
              available[j%n] = false;
              break;
            }
          } 
        }
      }
    }
    return *s.begin() == 'R' ? "Radiant" : "Dire";
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  Solution s;
  cout << s.predictPartyVictory("RD") << endl;
  cout << s.predictPartyVictory("RDD") << endl;
  cout << s.predictPartyVictory("DDRRR") << endl;
  return 0;
}
