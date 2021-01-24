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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
 public:
  ListNode* reverse(ListNode* head) {
    if (head == NULL || head->next == NULL) return head;

    ListNode *pre = head;
    ListNode *cur = head->next;
    head->next = NULL;
    while (cur != NULL) {
      ListNode *next = cur->next;
      cur->next = pre;
      pre = cur;
      cur = next;
    }
    return pre; 
  }

  bool isPalindrome(ListNode* head) {
    if (head == NULL || head->next == NULL) return true;

    ListNode *cur = head;
    ListNode *mid = head;
    while (1) {
      if (cur == NULL || cur->next == NULL) {
        ListNode *tmp = head;
        while (tmp->next != mid) tmp = tmp->next;
        tmp->next = NULL;
        if (cur != NULL) mid = mid->next;
        break;
      }
      cur = cur->next->next;
      mid = mid->next;
    }

    ListNode *tail = reverse(mid);
    while (1) {
      if (head == NULL && tail == NULL) return true;
      if (head == NULL || tail == NULL) return false;
      if (head->val != tail->val) return false;
      head = head->next;
      tail = tail->next;
    }
    return false; 
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  
  return 0;
} 
