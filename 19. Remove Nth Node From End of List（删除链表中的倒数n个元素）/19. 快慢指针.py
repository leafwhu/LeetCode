# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        fastPoint = slowPoint = head
        for i in range(n):
            fastPoint = fastPoint.next
        
        
        
        # delete head node
        if  slowPoint == head and fastPoint == None:
            head = slowPoint.next
            del slowPoint
        else:
            while fastPoint.next:
                fastPoint = fastPoint.next
                slowPoint = slowPoint.next
            fastPoint = slowPoint.next
            slowPoint.next = fastPoint.next
            del fastPoint
        return head