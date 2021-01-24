# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param head, a ListNode
    # @return a list node
    def detectCycle(self, head):
      node = head
      while node != None:
        if node.val == -999999: return node
        node.val = -999999
        node = node.next
      return None
        
