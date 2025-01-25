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

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  string line;
  vector<string> g;
  int x, y;
  
  auto print = [&]() {
    // return ;
    for (int i = 0; i < g.size(); ++i) {
      for (int j = 0; j < g[i].size(); ++j)
        if (x == i && y == j) cout << '@';
        else cout << g[i][j];
      cout << endl;
    }
  };

  while (getline(cin, line)) {
    // cout << line << endl;
    if (line.size() == 0) break;
    
    string s(line.size() << 1, '.');
    for (int j = 0; j < line.size(); ++j) {
      if (line[j] == '#' || line[j] == '.') {
        s[j<<1] = s[j<<1|1] = line[j];
      } else if (line[j] == '@') {
        s[j<<1] = s[j<<1|1] = '.';
        x = g.size();
        y = j << 1;
      } else {
        s[j<<1] = '[';
        s[j<<1|1] = ']';
      }
    }
    g.push_back(s);
  }
  print();
  cout << "-----------------------" << endl;
  
  while (cin >> line) {
    for (auto ch: line) {
      // dump(ch);

      if (ch == '^') {
        if (g[x-1][y] == '.') {
          x -= 1;
          print();
          continue;
        }

        set<int> s;
        s.insert(y); 
        int i = x - 1;
        for (int i = x - 1; ; --i) {
          

          if (g[i][y]) 

        }



        while (g[i][y] == 'O') --i;
        if (g[i][y] == '.') {
          g[i][y] = 'O';
          g[--x][y] = '.';
        }



      } else if (ch == '>') {
        if (g[x][y+1] == '.') {
          y += 1;
          // print();
          continue;
        }

        int j = y + 1;
        while (g[x][j] == '[') j += 2;
        if (g[x][j] == '.') {
          while (j > y) {
            g[x][j] = g[x][j-1];
            j -= 1;
          }
          y += 1;
        }
      } else if (ch == 'v') {
        if (g[x+1][y] == '.') {
          x += 1;
          print();
          continue;
        }

        int i = x + 1;
        while (g[i][y] == 'O') ++i;
        if (g[i][y] == '.') {
          g[i][y] = 'O';
          g[++x][y] = '.';
        }
      } else if (ch == '<') {
        if (g[x][y-1] == '.') {
          y -= 1;
          // print();
          continue;
        }

        int j = y - 1;
        while (g[x][j] == ']') j -= 2;
        if (g[x][j] == '.') {
          while (g[x][j] == ']') j -= 2;
          if (g[x][j] == '.') {
            while (j < y) {
              g[x][j] = g[x][j+1];
              j += 1
            }
            y -= 1;
          }
        }
      }

      print();
    }
  }
  
  ll ans = 0 ;
  for (int i = 0; i < g.size(); ++i)
    for (int j = 0; j < g[i].size(); ++j)
      if (g[i][j] == 'O') {
        // cout << i << " " << j << endl;
        ans += 100 * i + j;
      }

  cout << ans << endl;
  return 0;
}
