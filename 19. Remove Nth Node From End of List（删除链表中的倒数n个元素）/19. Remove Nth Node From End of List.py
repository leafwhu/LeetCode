# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        nodeList = [head]
        tmp = head
        while tmp.next:
            tmp = tmp.next
            nodeList.append(tmp)
        delIndex = len(nodeList) - n
        if delIndex == 0:
            # delete head node(may also be tail node)
            head = head.next
        elif nodeList[delIndex].next:
            # delete intermediate node
            nodeList[delIndex-1].next = nodeList[delIndex+1]   
        else:
            # delete tail node
            nodeList[delIndex-1].next = None
        del nodeList[delIndex]
        return head