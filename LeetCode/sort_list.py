#!/usr/bin/python

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param head, a ListNode
    # @return a ListNode
    def sortList(self, head):
      array = []
      node = head
      while node != None:
        array.append(node.val)
        node = node.next
      array.sort()
      node = head
      for i in range(len(array)):
        node.val = array[i]
        node = node.next
      return head
