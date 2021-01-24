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
const int N = 1000000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  string s, ans = "";
  cin >> s;
  int f[N];
  memset(f, 0, sizeof(f));
  for (int i = 1; i < s.size(); ++i)
    if (s[i] == ')' && s[i-1-f[i-1]] == '(' || s[i] == ']' && s[i-1-f[i-1]] == '[') {
      f[i] = f[i-1] + 2 + (i-1-f[i-1]-1 >= 0 ? f[i-1-f[i-1]-1] : 0);
      if (f[i] > ans.size()) {
        ans = s.substr(i-f[i]+1, f[i]);
      }
    }
  cout << ans << endl;
  return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// #define dump(x) cout <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
// #define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0xc0
// #define mp(a, b) make_pair(a, b)
// #define pb(a) push_back(a)
// #define lowbit(x) x & (-x)
// typedef long long ll;
// typedef pair<int, int> pii;

// template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
// template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
// const int N = 100000 + 5;
// const int INF = 0x3f3f3f3f;
// const int MOD = 1000000007;

// int main() {
// #ifndef ONLINE_JUDGE
//   freopen("in.txt", "r", stdin);
//   // freopen("out.txt", "w", stdout);
// #endif
//   string s; 
//   cin >> s;
//   string ans = "";
//   int pre_len = 0;
//   stack<pair<int, char>> a;
//   vector<pair<int, int>> b;
//   for (int i = 0; i < s.size(); ++i) {
//     if (s[i] == '(' || s[i] == '[') {
//       a.emplace(i, s[i]);
//     } else if (s[i] == ')') {
//       if (!a.empty() && a.top().second == '(') {
//         auto [j, ch] = a.top(); a.pop();
//         if (!b.empty() && j == b.back().first - 1) b.pop_back();
//         // dump(b.size());
//         if (!b.empty() && j == b.back().first + b.back().second) {
//           j = b.back().first;
//           b.pop_back();
//         }
//         // dump(i), dump(s[i]), dump(j), dump(i-j+1);
//         b.emplace_back(j, i - j + 1);

//         if (a.empty()) {
//           pre_len += b.back().second;
//           b.clear();
//           if (pre_len > ans.size()) ans = s.substr(i-pre_len+1, pre_len);
//         }
//       } else {
//         a = stack<pair<int, char>>();
//         pre_len = 0;
//         for (auto [idx, len]: b)
//           if (len > ans.size()) ans = s.substr(idx, len);
//         b.clear();
//       }
//     } else {
//       if (!a.empty() && a.top().second == '[') {
//         auto [j, ch] = a.top(); a.pop();
//         if (!b.empty() && j == b.back().first - 1) b.pop_back();
//         // dump(b.size());
//         if (!b.empty() && j == b.back().first + b.back().second) {
//           j = b.back().first;
//           b.pop_back();
//         }
//         // dump(i), dump(s[i]), dump(j), dump(i-j+1);
//         b.emplace_back(j, i - j + 1);

//         if (a.empty()) {
//           pre_len += b.back().second;
//           b.clear();
//           if (pre_len > ans.size()) ans = s.substr(i-pre_len+1, pre_len);
//         }
//       } else {
//         a = stack<pair<int, char>>();
//         pre_len = 0;
//         for (auto [idx, len]: b)
//           if (len > ans.size()) ans = s.substr(idx, len);
//         b.clear();
//       }
//     }
//   }
//   for (auto [idx, len]: b)
//     if (len > ans.size()) ans = s.substr(idx, len);
//   cout << ans << endl;
//   return 0;
// }