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
  bool check(int cnt1[26], int cnt2[26]) {
    for (int i = 0; i < 26; ++i)
      if (cnt1[i] != cnt2[i]) return false;
    return true;
  }

  bool checkInclusion(string s1, string s2) {
    if (s1.size() > s2.size()) return false;

    int n = s1.size();
    int cnt1[26], cnt2[26];
    clr(cnt1, 0); clr(cnt2, 0);
    for (int i = 0; i < n; ++i) {
      ++cnt1[s1[i]-'a'];
      ++cnt2[s2[i]-'a'];
    }
    if (check(cnt1, cnt2)) return true;

    for (int i = n; i < s2.size(); ++i) {
      ++cnt2[s2[i]-'a'];
      --cnt2[s2[i-n]-'a'];
      if (check(cnt1, cnt2)) return true;
    }
    return false;
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  Solution s;
  string s1("ab");
  string s2("eidbaooo");
  string s3("eidboaoo");
  cout << s.checkInclusion(s1, s2) << endl;
  cout << s.checkInclusion(s1, s3) << endl;
  return 0;
}
