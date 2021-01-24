#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    struct Node {
      int key;
      int value;
      bool operator < (const Node &a) const {
        return a.value < value;
      }
    };

    ListNode *mergeKLists(vector<ListNode *> &lists) {
      priority_queue<Node> q;
      int i;
      int k = lists.size();
      if (k == 0) return NULL;
      for (i = 0; i < k; ++i) {
        if (lists[i] == NULL) continue;
        Node node;
        node.key = i;
        node.value = lists[i]->val;
        q.push(node);
      }
      ListNode head(-1);
      ListNode *tail = &head;
      while (!q.empty()) {
        Node tmp = q.top();
        q.pop();
        //cout << tmp.key << ' ' << tmp.value << endl;
        tail->next = lists[tmp.key];
        tail = tail->next;
        if (lists[tmp.key]->next != NULL) {
          Node node;
          node.key = tmp.key;
          node.value = lists[tmp.key]->next->val;
          q.push(node);
          lists[tmp.key] = lists[tmp.key]->next;
        }
      }
      return head.next;
    }
};

int main() {
  Solution ss;
  vector<ListNode *> lists;
  ListNode node1(1), node2(2), node3(2);
  ListNode node4(1), node5(1), node6(2);
  node1.next = &node2;
  node2.next = &node3;
  lists.push_back(&node1);
  node4.next = &node5;
  node5.next = &node6;
  lists.push_back(&node4);
  //lists.push_back(&node3);
  ListNode *node = ss.mergeKLists(lists);
  while (node != NULL) {
    cout << node->val << ' ';
    node = node->next;
  }
  cout << endl;
  return 0;
}
