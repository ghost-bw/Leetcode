class Solution:
    def rotateRight(self, head: ListNode | None, k: int) -> ListNode | None:
        # Edge case: Empty list or single-node list doesn't change
        if not head or not head.next or k == 0:
            return head
            
        # Step 1: Find the length and the last node
        last_node = head
        count = 1
        while last_node.next:
            last_node = last_node.next
            count += 1
            
        # Step 2: Handle cases where k >= length
        k = k % count
        if k == 0:
            return head
            
        # Step 3: Connect the tail to the head to make it circular
        last_node.next = head
        
        # Step 4: Find the new tail node (count - k steps from current head)
        new_tail = head
        for _ in range(count - k - 1):
            new_tail = new_tail.next
            
        # Step 5: Break the circle and set the new head
        new_head = new_tail.next
        new_tail.next = None
        
        return new_head
