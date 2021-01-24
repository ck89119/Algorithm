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
  vector<int> asteroidCollision(vector<int>& asteroids) {
    int n = asteroids.size();
    vector<int> next(n);
    for (int i = 0; i < n; ++i) next[i] = i+1;
    int head = 0;
    
    while (true) {
      vector<int> p;
      for (int i = head; next[i] < n; i = next[i]) {
        if (asteroids[i] > 0 && asteroids[next[i]] < 0) p.push_back(i); 
      }

      if (p.size() == 0) break;
      for (auto i: p) {
        int s1 = abs(asteroids[i]);
        int s2 = abs(asteroids[next[i]]);
        if (s1 < s2) {
          asteroids[i] = asteroids[next[i]];
        } else if (s1 == s2) {
          asteroids[i] = 0; 
        }
        next[i] = next[next[i]];
      }
      
      while (head < n && asteroids[head] == 0) head = next[head];
      for (int i = head; next[i] < n; i = next[i]) {
        while (next[i] < n && asteroids[next[i]] == 0) {
          next[i] = next[next[i]];
        }
      }
    }
    vector<int> ans;
    for (int i = head; i < n; i = next[i])
      ans.push_back(asteroids[i]);
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
