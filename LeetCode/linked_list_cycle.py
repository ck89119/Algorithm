#!/usr/bin/python

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param head, a ListNode
    # @return a boolean
    def hasCycle(self, head):
      node = head
      while node != None:
        if node.val == -1: return True
        node.val = -1
        node = node.next
      
      return False
