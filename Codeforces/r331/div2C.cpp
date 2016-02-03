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

#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0x80
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(x) x & (-x)
#define X first 
#define Y second
typedef long long ll;
typedef pair<int, int> pii;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 100000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n;
int w[N];
map<pii, int> indegree;
pii a[2*N];
vector<pii> ans;

int topsort() {
  for (int i = 0; i < n; ++i) {
    pii t = a[w[i] + N], tt;
    a[w[i] + N] = mp(-1, -1);
    //dump(t.first);
    //dump(t.second);
    ans.pb(t);
    if (t.first == -1) return 0;

    tt = mp(t.first + 1, t.second);
    if (indegree.count(tt)) {
      --indegree[tt];
      if (indegree[tt] == 0)
        a[tt.second - tt.first + N] = tt;
    }
  
    tt = mp(t.first, t.second + 1);
    if (indegree.count(tt)) {
      --indegree[tt];
      if (indegree[tt] == 0)
        a[tt.second - tt.first + N] = tt;
    }
  } 
  return 1;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int x, y, d = 2;
    scanf("%d%d", &x, &y);
    if (x == 0) --d;
    if (y == 0) --d;
    indegree[mp(x, y)] = d;
    //dump(x);
    //dump(y);
    //dump(indegree[mp(x, y)]);
  }
  for (int i = 0; i < n; ++i)
    scanf("%d", &w[i]);
  
  for (int i = 0; i < 2 * N; ++i)
    a[i] = mp(-1, -1);
  a[N] = mp(0, 0);
  
  if (topsort()) {
    printf("YES\n");
    for (int i = 0; i < ans.size(); ++i)
      printf("%d %d\n", ans[i].first, ans[i].second);
  } else {
    printf("NO\n");
  }
  return 0;
}

//#include <bits/stdc++.h>
//#define MAX_N 100010
//using namespace std;

//#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
//int n;
//map<int,vector<pair<int,int> > > weights;
//map<int,vector<int> > cnt;
//pair<int,int> ans[MAX_N];
//vector<int> diag[MAX_N];

//int main(void) {
    //freopen("in.txt", "r", stdin);
    //scanf("%d",&n);
    //for (int i=0; i<n; i++) {
        //int a, b;
        //scanf("%d %d",&a,&b);
        //while (diag[a].size()<=b) diag[a].push_back(0);
        //weights[b-a].push_back(make_pair(a,b));
    //}
    //for (auto& v: weights) {
        //sort(v.second.begin(),v.second.end());
    //}
    //for (int i=0; i<n; i++) {
        //int a;
        //cin >> a;
        //cnt[a].push_back(i);
    //}
    //for (auto v: cnt) {
        //if (weights.count(v.first)==0 || weights[v.first].size()!=v.second.size()) {
            //printf("NO\n");
            //return 0;
        //}
        //for (int i=0; i<v.second.size(); i++) {
            //ans[v.second[i]]=weights[v.first][i];
            //diag[weights[v.first][i].first][weights[v.first][i].second]=v.second[i];
        //}
    //}
    //for (int i=0; i<MAX_N; i++) {
        //for (int j=0; j<(int)diag[i].size(); j++) {
            //if ((int)diag[i+1].size()>j && diag[i+1][j]<diag[i][j]) {
                //printf("NO\n");
                //return 0;
            //}
            //if (j+1<(int)diag[i].size() && diag[i][j]>diag[i][j+1]) {
                //printf("NO\n");
                //return 0;
            //}
        //}
    //}
    //printf("YES\n");
    //for (int i=0; i<n; i++) {
        //printf("%d %d\n",ans[i].first,ans[i].second);
    //}
    //return 0;
//}
