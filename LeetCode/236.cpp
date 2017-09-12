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

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// class Solution {
//  public:
//   map<TreeNode*, int> height;
//   map<TreeNode*, TreeNode*> father;
//   map<TreeNode*, vector<TreeNode*>> anc;
  
//   int get_log(int n) {
//     int log = 0;
//     while (n) ++log, n >>= 1;
//     return log;
//   }

//   int init(int h) {
//     for (auto p: height) {
//       auto node = p.first;
//       vector<TreeNode*> t(h+1, NULL);
//       t[0] = father[node];
//       anc[node] = t;
//     }
    
//     for (auto p: anc) {
//       auto node = p.first;
//       for (int i = 1; i <= h; ++i)
//         if (anc[node][i-1] != NULL)
//           anc[node][i] = anc[anc[node][i-1]][i-1];
//     }
//     return 0;
//   }

//   int travel(TreeNode *cur, TreeNode *pre, int h) {
//     if (cur == NULL) return 0;

//     height[cur] = h;
//     father[cur] = pre;
//     int ans = h;
//     ans = max(ans, travel(cur->left, cur, h+1));
//     ans = max(ans, travel(cur->right, cur, h+1));
//     return ans; 
//   }

//   TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//     if (root == NULL || p == NULL || q == NULL) return NULL;
//     int h = get_log(travel(root, NULL, 0));
//     init(h);
    
//     if (height[p] < height[q]) swap(p, q);
//     for (int i = h; i >= 0; --i)
//       if (height[p] - (1 << i) >= height[q])
//         p = anc[p][i];
//     for (int i = h; i >= 0; --i)
//       if (anc[p][i] != NULL && anc[p][i] != anc[q][i]) {
//         p = anc[p][i];
//         q = anc[q][i];
//       }
//     return p;
//   }
// };

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  
  return 0;
}
