#!/usr/bin/python

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @param head, a ListNode
    # @param k, an integer
    # @return a ListNode
    def rotateRight(self, head, k):
      if head == None: return None
      node_list = []
      node = head
      while node != None:
        node_list.append(node)
        node = node.next
      n = len(node_list)
      k %= n
      if k == 0: return head

      node_list[n-1].next = head
      head = node_list[n-k]
      node_list[n-k-1].next = None
      return head

ss = Solution()
node1 = ListNode(1)
node2 = ListNode(2)
node3 = ListNode(3)
node4 = ListNode(4)
node5 = ListNode(5)
node1.next = node2
node2.next = node3
node3.next = node4
node4.next = node5

node = ss.rotateRight(node1, 2)
while node != None:
  print node.val
  node = node.next
