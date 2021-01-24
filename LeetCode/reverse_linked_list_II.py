#!/usr/bin/python

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @param head, a ListNode
    # @param m, an integer
    # @param n, an integer
    # @return a ListNode
    def reverseBetween(self, head, m, n):
      if m == n: return head
      node_list = []
      node = ListNode(-1)
      node.next = head
      head = node
      while node != None:
        node1 = node
        node_list.append(node1)
        node = node.next
      node_list.append(None)
      for i in range(m+1, n+1):
        node_list[i].next = node_list[i-1]
      node_list[m-1].next = node_list[n]
      node_list[m].next = node_list[n+1]
      return head.next

ss = Solution()
node1 = ListNode(3)
node2 = ListNode(5)
node1.next = node2
node = ss.reverseBetween(node2, 1, 1)
while node != None:
  print node.val
  node = node.next
