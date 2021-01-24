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

class Timestamp {
 public:
  Timestamp(string timestamp) {
    for (auto item: split(timestamp, ':')) {
      time.push_back(str2int(item));
    }
  }

  bool operator<(const Timestamp &t) const {
    for (int i = 0; i < 6; ++i) {
      if (time[i] != t.time[i]) {
        return time[i] < t.time[i];
      }
    }
    return false;
  }

  bool operator<=(const Timestamp &t) const {
    for (int i = 0; i < 6; ++i) {
      if (time[i] != t.time[i]) {
        return time[i] < t.time[i];
      }
    }
    return true;
  }

  friend ostream& operator<<(ostream& os, const Timestamp &timestamp) {
    for (auto item: timestamp.time) {
      os << item << ":";
    }
    return os;
  }

  vector<int> time;
  int str2int(string s) {
    istringstream is(s);
    int t;
    is >> t;
    return t;
  }

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
};

class LogSystem {
 public:
  LogSystem() {
    level.push_back("Year");
    level.push_back("Month");
    level.push_back("Day");
    level.push_back("Hour");
    level.push_back("Minute");
    level.push_back("Second");
  }

  void put(int id, string timestamp) {
    Timestamp s(timestamp);
    logs[s] = id;
  }

  vector<int> retrieve(string s, string e, string gra) {
    Timestamp start(s);
    Timestamp end(e);
    int i = 0;
    for (i = 0; i < 6; ++i) {
      if (gra == level[i]) break;
    }
    end.time[i] += 1;
    for (int j = i + 1; j < 6; ++j) {
      start.time[j] = 0;
      end.time[j] = 0;
    }

    vector<int> ans;
    for (auto it: logs) {
      if (it.first < end && start <= it.first) {
        ans.push_back(it.second);
      }
    }
    return ans;
  }

 private:
  vector<string> level;
  map<Timestamp, int> logs;
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem obj = new LogSystem();
 * obj.put(id,timestamp);
 * vector<int> param_2 = obj.retrieve(s,e,gra);
 */

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  LogSystem obj;
  obj.put(1, "2017:01:01:23:59:59");
  obj.put(2, "2017:01:01:22:59:59");
  obj.put(3, "2016:01:01:00:00:00");
  out(obj.retrieve("2016:01:01:01:01:01","2017:01:01:23:00:00","Year"));
  out(obj.retrieve("2016:01:01:01:01:01","2017:01:01:23:00:00","Hour"));
  return 0;
}
