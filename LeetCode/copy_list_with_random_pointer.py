#!/usr/bin/python

# Definition for singly-linked list with a random pointer.
class RandomListNode:
    def __init__(self, x):
        self.label = x
        self.next = None
        self.random = None

class Solution:
    # @param head, a RandomListNode
    # @return a RandomListNode
    def copyRandomList(self, head):
      if head == None: return None
      ans = RandomListNode(head.label)
      ans_node_list = {}
      ans_node_list[None] = None
      ans_node_list[head] = ans
      node = head.next
      node_ans = ans
      while node != None:
        new_node = RandomListNode(node.label)
        ans_node_list[node] = new_node
        node_ans.next = new_node
        node = node.next
        node_ans = node_ans.next
      
      node = head
      ans_node = ans
      while node != None:
        ans_node.random = ans_node_list[node.random]
        node = node.next
        ans_node = ans_node.next
      return ans

ss = Solution()
head = RandomListNode(-1)
node = ss.copyRandomList(head)
while node != None:
  print node.label
  node = node.next

