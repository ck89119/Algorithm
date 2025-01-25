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

vector<string> numeric = {
  "789", 
  "456", 
  "123", 
  " 0A"
};
vector<string> directional = {
  " ^A", 
  "<v>"
};

// tuple<int, int> get_loc(char ch) {
//   for (int i = 0; i < numeric.size(); ++i)
//     for (int j = 0; j < numeric[i].size(); ++j)
//       if (numeric[i][j] == ch) {
//          return make_tuple(i, j);
//       }
//   return make_tuple(-1, -1);
// }


// int dx[4] = {0, 1, 0, -1};
// int dy[4] = {1, 0, -1, 0};
// map<char, map<char, int>> dis;

// int bfs(const vector<string> &g, string code, int level) {
//   auto in_board = [&](int x, int y) -> bool {
//     return x >= 0 && x < g.size() && y >= 0 && y < g[x].size();
//   };



//   for (int i = 0; i < numeric.size(); ++i)
//     for (int j = 0; j < numeric[i].size(); ++j) {
//       char a = numeric[i][j];

//       for (int k = 0; k < 4; ++k) {
//         int nx = i + dx[k];
//         int ny = i + dy[k];

//         if (in_board(nx, ny)) {
//           char b = numeric[nx][ny];
//           dis[a][b] = ;
//         }
//       }
//     }
// }

map<char, map<char, string>> t {
  {'A', {
    {'A', "A"},
    {'^', "<A"},
    {'>', "vA"},
    {'v', "<vA"},
    {'<', "v<<A"},
  }},
  {'^', {
    {'A', ">A"},
    {'^', "A"},
    {'>', "v>A"},
    {'v', "vA"},
    {'<', "v<A"},
  }},
  {'>', {
    {'A', "^A"},
    {'^', "<^A"},
    {'>', "A"},
    {'v', "<A"},
    {'<', "<<A"},
  }},
  {'v', {
    {'A', "^>A"},
    {'^', "^A"},
    {'>', ">A"},
    {'v', "A"},
    {'<', "<A"},
  }},
  {'<', {
    {'A', ">>^A"},
    {'^', ">^A"},
    {'>', ">>A"},
    {'v', ">A"},
    {'<', "A"},
  }},
};


string solve(const string& s, int level) {
  // dump(s);
  if (level == 2) return s;

  string ans = "";
  char pre = 'A';
  for (auto ch: s) {
    ans += t[pre][ch];
    pre = ch;
  }
  
  return solve(ans, level + 1);
}

void print(const string &s) {
  cout << s.size() << " " << s << endl; 
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  // print(solve("<A", 1));
  // print(solve("^A", 1));
  // print(solve("^^>A", 1));
  // print(solve("vvvA", 1));
  // cout << "====================" << endl;
  // print(solve("^^^A", 1));
  // print(solve("<A", 1));
  // print(solve("vvvA", 1));
  // print(solve(">A", 1));
  // cout << "====================" << endl;
  // print(solve("^<<A", 1));
  // print(solve("^^A", 1));
  // print(solve(">>A", 1));
  // print(solve("vvvA", 1));
  // cout << "====================" << endl;
  // print(solve("^^<<A", 1));
  // print(solve(">A", 1));
  // print(solve(">A", 1));
  // print(solve("vvA", 1));
  // cout << "====================" << endl;
  // print(solve("^A", 1));
  // print(solve("<<^^A", 1));
  // print(solve(">>A", 1));
  // print(solve("vvvA", 1));
  // cout << "====================" << endl;
  

  vector<string> vec; 
  auto f = [&]() {
    int ans = 0;
    for (auto &s : vec) {
      ans += solve(s, 0).size();
    }
    return ans;
  }; 
  
  // 129A
  vec = {"^<<A", ">A", "^^>A", "vvvA"};
  dump(f());

  // 176A
  vec = {"^<<A", "^^A", "v>>A", "vvA"};
  dump(f());

  // 985A
  vec = {"^^^A", "<A", "vA", "vv>A"};
  dump(f());

  // 170A
  vec = {"^<<A", "^^A", ">vvvA", ">A"};
  dump(f());

  // 528A
  vec = {"<^^A", "vA", "^^A", "vvv>A"};
  dump(f());
  return 0;
}
