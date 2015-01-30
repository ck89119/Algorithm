/*
ID: ck89119
PROG:
LANG: C++
*/
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;
#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl
#define FR(i,a,b) for(int i=(a);i<(b);++i)//[a,b)
#define CLR(a,x) memset(a,x,sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0x80
#define MP(A,B) make_pair(A,B)
#define PB(A) push_back(A)
#define PAU system("pause")
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(x) x & (-x)
#define fin freopen("C-small-practice.in","r",stdin)
#define fout freopen("C-small-practice.out","w",stdout)
//ifstream fin("");
//ofstream fout("");
#define LL long long
#define ULL unsigned long long

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out (vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int MAXN=99999;
const int MAXM=9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;
const int CHILD_NUM = 26;
const int MOD = 1000000007;

map<string, int> m;
int size;
vector<pair<int, int> > p[10005];

int insert(string &a) {
  if (m.count(a)) return m[a];
  else {
    m[a] = size++;
    return m[a];
  }
}

int main() {
  //fin; fout;
  int T;
  scanf("%d", &T);
  for (int ncase = 1; ncase <= T; ++ncase) {
    m.clear();
    size = 0;
    for (int i = 0; i < 10005; ++i) p[i].clear();
    int N, Q;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
      string s;
      cin >> s;
      for (int j = 0; j < s.size(); ++j)
        if (s[j] == '+' || s[j] == '=') s[j] = ' ';
      istringstream in(s);
      string sa, sb;
      int c;
      in >> sa >> sb >> c;
      int a = insert(sa);
      int b = insert(sb);
      p[a].push_back(MP(b, c));
      p[b].push_back(MP(a, c));
    }
    //for (int i = 0; i < size; ++i) {
      //dump(i);
      //for (int j = 0; j < p[i].size(); ++j)
        //dump(p[i][j].first);
    //}
    printf("Case #%d:\n", ncase);
    scanf("%d", &Q);
    for (int i = 0; i < Q; ++i) {
      string s;
      cin >> s;
      for (int j = 0; j < s.size(); ++j)
        if (s[j] == '+' || s[j] == '=') s[j] = ' ';
      istringstream in(s);
      string sa, sb;
      in >> sa >> sb;
      if (m.count(sa) == 0 || m.count(sb) == 0) continue;
      int a = insert(sa);
      int b = insert(sb);
      
      int visited[size];
      CLR(visited, 0);
      queue<pair<int, int> > q;
      while (!q.empty()) q.pop();
      for (int j = 0; j < p[a].size(); ++j) {
        q.push(p[a][j]);
        visited[p[a][j].first] = 1;
      }
      //visited[a] = 1;
      //out(visited, size);
      while (!q.empty()) {
        pair<int, int> item;
        item = q.front(); q.pop();
        //dump(item.first); dump(item.second);
        if (item.first == b) {
          cout << sa << "+" << sb << "=" << item.second << endl;
          break;
        }
        
        int e = item.first;
        for (int ii = 0; ii < p[e].size(); ++ii) {
          int ee = p[e][ii].first;
          for (int jj = 0; jj < p[ee].size(); ++jj) {
            int t = p[ee][jj].first;
            //dump(e); dump(ee); dump(t);
            if (!visited[t]) {
              visited[t] = 1;
              q.push(MP(t, item.second + p[ee][jj].second - p[e][ii].second));
            }
          }
        }
      }
    }


  }
  return 0;
}
