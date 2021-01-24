#!/usr/bin/python

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param head, a ListNode
    # @return a ListNode
    def deleteDuplicates(self, head):
      node = ListNode(-9999)
      node.next = head
      head = node
      
      while node.next != None:
        if node.next.next != None and node.next.val == node.next.next.val:
          k = node
          while k.next.next != None and k.next.val == k.next.next.val:
            k = k.next
          node.next = k.next.next
        else:
          node = node.next
      return head.next
