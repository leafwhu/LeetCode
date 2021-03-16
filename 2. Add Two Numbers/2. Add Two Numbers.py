# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        result = ListNode()
        itr1 = l1
        itr2 = l2
        itr3 = result
        carry = 0
        while True:
            sumi = itr1.val + itr2.val + carry
            itr3.val = sumi % 10
            carry = sumi // 10
            if (not itr1.next) and (not itr2.next) and carry == 0:
                break
            if itr1.next:
                itr1 = itr1.next
            else:
                itr1.val = 0
            if itr2.next:
                itr2 = itr2.next
            else:
                itr2.val = 0
            itr3.next = ListNode()
            itr3 = itr3.next
        return result