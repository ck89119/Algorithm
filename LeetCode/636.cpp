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
  vector<string> split(const string &s, char delim) {
    vector<string> ans;
    stringstream ss;
    ss.str(s);
    string item;
    while (getline(ss, item, delim)) {
      ans.push_back(item);
    }
    return ans;
  }

  int str2int(const string &s) {
    istringstream is(s);
    int t;
    is >> t;
    return t;
  }

  vector<int> exclusiveTime(int n, vector<string>& logs) {
    stack<pair<int, int>> s;
    vector<int> ans(n);
    auto items = split(logs[0], ':');
    int index = str2int(items[0]);
    int time = str2int(items[2]) + (items[1] == "end");
    s.push(make_pair(index, time));
    int pre_time = time;
    for (int i = 1; i < logs.size(); ++i) {
      auto log = logs[i];
      auto items = split(log, ':');
      int index = str2int(items[0]);
      int time = str2int(items[2]) + (items[1] == "end");
      auto top = s.top(); 
      ans[top.first] += time - pre_time;
      pre_time = time;
      if (items[1] == "end") {
        s.pop();
      } else {
        s.push(make_pair(index, time));
      }
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
