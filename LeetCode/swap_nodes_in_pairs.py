#!/usr/bin/python

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param a ListNode
    # @return a ListNode
    def swapPairs(self, head):
        if head == None: return None
        if head.next == None: return head
        ans = head.next
        pre = head
        while head != None:
          next_node = head.next
          if next_node == None: break
          pre.next = next_node
          head.next = next_node.next
          next_node.next = head
          pre = head
          head = head.next 
        return ans
