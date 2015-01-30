#!/usr/bin/python

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @param head, a ListNode
    # @return nothing
    def reorderList(self, head):
      node_list = []
      node = head
      while node != None:
        node1 = node
        node_list.append(node1)
        node = node.next
      length = len(node_list)
      last = length - 1
      node = head
      while length > 2:
        node_list[last].next = node.next
        node.next = node_list[last]
        node_list[last-1].next = None
        last -= 1
        node = node.next.next
        length -= 2

s = Solution()
l1 = ListNode(1)
l2 = ListNode(2)
l3 = ListNode(3)
l1.next = l2
l2.next = l3
s.reorderList(l1)
node = l1
while node != None:
  print node.val
  node = node.next
