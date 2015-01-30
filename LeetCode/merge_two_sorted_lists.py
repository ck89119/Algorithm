#!/usr/bin/python

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param two ListNodes
    # @return a ListNode
    def mergeTwoLists(self, l1, l2):
      if l1 ==  None: return l2
      if l2 ==  None: return l1
      if l1.val < l2.val:
        head = l1
        l1 = l1.next
      else:
        head = l2
        l2 = l2.next
      end = head

      while l1 != None and l2 != None:
        if l1.val < l2.val:
          end.next = l1
          l1 = l1.next
        else:
          end.next = l2
          l2 = l2.next
        end = end.next

      if l1 != None:
        end.next = l1
      if l2 != None:
        end.next = l2
      return head



