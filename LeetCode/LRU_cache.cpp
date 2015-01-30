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
using namespace std;
#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl
#define FR(i,a,b) for(int i=(a);i<(b);++i)//[a,b)
#define CLR(a,x) memset(a,x,sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0x80
#define MP(A,B) make_pair(A,B)
#define PB(A) push_back(A)
#define PAU system("pause")
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(n) (n^(n-1))&n
#define fin freopen(".in","r",stdin)
#define fout freopen(".out","w",stdout)
//ifstream fin("");
//ofstream fout("");
#define LL long long

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out (vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int MAXN=99999;
const int MAXM=9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;

struct DoubleLinkedNode {
  int key, value;
  struct DoubleLinkedNode *next, *pre;
  DoubleLinkedNode(int _key = -1, int _value = -1) {
    key = _key;
    value = _value;
    next = pre = NULL;
  }
};

class LRUCache{
public:
    DoubleLinkedNode *head, *tail;
    int cap, size;
    map<int, struct DoubleLinkedNode*> h;

    LRUCache(int capacity) {
      cap = capacity;
      size = 0;
      head = new DoubleLinkedNode(-INF, -1);
      tail = new DoubleLinkedNode(INF, -1);
      head->next = tail;
      tail->pre = head;
      //h[-INF] = head;
      //h[INF] = tail;
    }
    
    DoubleLinkedNode *removeNode(int key) {
      DoubleLinkedNode *tmp = h[key];
      DoubleLinkedNode *pre = tmp->pre;
      DoubleLinkedNode *next = tmp->next;
      pre->next = next;
      next->pre = pre;
      h.erase(key);
      return tmp;
    }
    
    int pushNode(DoubleLinkedNode *a) {
      tail->pre->next = a;
      a->pre = tail->pre;
      tail->pre = a;
      a->next = tail;
      h[a->key] = a;
      return 0;
    }
    
    DoubleLinkedNode *popNode() {
      if (head->next == tail) return NULL;
      DoubleLinkedNode *a = head->next;
      head->next = a->next;
      a->next->pre = head;
      h.erase(a->key);
      return a;
    }

    int get(int key) {
      if (h.count(key) == 0) return -1;
      else {
        DoubleLinkedNode *tmp;
        tmp = removeNode(key);
        pushNode(tmp);
        return tmp->value;
      }
    }
    
    void set(int key, int value) {
      if (h.count(key) == 0) {
        if (size == cap) popNode();
        DoubleLinkedNode *a = new DoubleLinkedNode(key, value);
        pushNode(a);
      } else {
        DoubleLinkedNode *a;
        a = removeNode(key);
        a->value = value;
        pushNode(a);
      } 
    }
};
