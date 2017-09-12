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
const int N = 10000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int cmp(const vector<int> &a, const vector<int> &b) {
  return a[1] < b[1];
}

class Solution {
 public:
  int scheduleCourse(vector<vector<int>>& courses) {
    int start = 0;
    priority_queue<int> q;
    sort(courses.begin(), courses.end(), cmp);
    for (auto course: courses) {
      start += course[0];
      q.push(course[0]);
      while (start > course[1]) {
        start -= q.top();
        q.pop();
      }
    }
    return q.size();
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  
  return 0;
}
