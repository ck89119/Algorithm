#include <bits/stdc++.h>
using namespace std;

#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define CLR(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0x80
#define MP(A, B) make_pair(A, B)
#define PB(A) push_back(A)
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(x) x & (-x)
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 999999;
const int M = 9999999;
const int INF = 0x3f3f3f3f;
const int MOD = 10003;
const int SEED = 13331;  // 10003, 10007, 13331, 1000000007, 1000000009

struct HashMap {
  struct Node {
    long long key, value;
    int next;
  } data[N];
  int head[MOD];
  int size;

  int init() {
    size = 0;
    CLR(head, -1);
    return 0;
  }

  int find(long long key) {
    int k = key % MOD;
    for (int i = head[k]; i != -1; i = next[i])
      if (data[i].key == key) return i;
    return -1;
  }

  int insert(long long key) {
    int k = key % MOD;
    for (int i = head[k]; i != -1; i = data[i].next)
      if (data[i].key == key) return 0;
    data[size].key = key;
    data[size].value = 0;
    data[size].next = head[k];
    head[k] = size++;
    return 0;
  }

  int get(long long key, long long &value) {
    int i = find(key);
    if (i != -1) value = data[i].value;
    return i;
  }

  int set(long long key, long long value) {
    int i = find(key);
    if (i == -1) {
      insert(key);
      data[size-1].value = value;
    } else {
      data[i].value = value;
    }
    return 0;
  }

  int add(long long key, long long delta) {
    int i = find(key);
    if (i == -1) {
      insert(key);
      data[size-1].value += delta;
    } else {
      data[i].value += delta;
    }
    return 0;
  }

};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif
  
  return 0;
}
