#!/usr/bin/python

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @return a ListNode
    def removeNthFromEnd(self, head, n):
      node_list = []
      node = head
      length = 0
      while node != None:
        node1 = node
        node_list.append(node1)
        length += 1
        node = node.next
      if n == length:
        return head.next
      else:
        node_list[length-n-1].next = node_list[length-n].next
        return head
