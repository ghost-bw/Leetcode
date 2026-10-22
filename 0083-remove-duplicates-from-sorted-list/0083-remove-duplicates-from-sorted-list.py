# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: ListNode | None) -> ListNode | None:
        s=set()
        curr=head
        while(curr ):
            if curr.val not in s:
                s.add(curr.val)
                prev=curr
            else:
                prev.next=curr.next
            curr=curr.next
        return head