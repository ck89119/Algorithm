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
        if head == None: return head
        node = head
        while node.next != None:
          node_next = node.next
          if node.val == node_next.val:
            node.next = node_next.next
          else:
            node = node_next
        return head
