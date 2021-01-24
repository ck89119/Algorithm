#include <bits/stdc++.h>
using namespace std;

#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0xc0
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

int sign(int x) {
  return x > 0;
}

struct Trie {
  vector<vector<int> > data;
  vector<int> end;
  int root;
  
  int NewNode() {
    vector<int> v(2, -1);
    data.push_back(v);
    end.push_back(-1);
    return data.size() - 1;
  }

  int Init() {
    data.clear();
    end.clear();
    root = NewNode();
    return 0;
  }

  int Insert(int x) {
    int cur = root;
    for (int i = 31; i >= 0; --i) {
      int bit = sign(x & (1 << i));
      if (data[cur][bit] == -1) {
        data[cur][bit] = NewNode();
      }
      cur = data[cur][bit];
    }
    end[cur] = x;
    return 0;
  }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
      Trie trie;
      trie.Init();
      for (auto num: nums)
        trie.Insert(num);

      int ans = 0;
      for (auto num: nums) {
        int cur = trie.root;
        for (int i = 31; i >= 0; --i) {
          int bit = sign(num & (1 << i));
          if (trie.data[cur][1-bit] != -1)
            cur = trie.data[cur][1-bit];
          else
            cur = trie.data[cur][bit];
        }
        ans = max(ans, num ^ trie.end[cur]); 
      }
      return ans;
    }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif
  Solution s;
  vector<int> nums;
  nums.push_back(3);
  nums.push_back(10);
  nums.push_back(5);
  nums.push_back(25);
  nums.push_back(2);
  nums.push_back(8);
  cout << s.findMaximumXOR(nums) << endl;
  return 0;
}
