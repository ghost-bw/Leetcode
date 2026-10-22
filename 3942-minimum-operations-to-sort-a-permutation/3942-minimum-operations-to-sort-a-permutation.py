class Solution:
    def minOperations(self, nums: list[int]) -> int:
        n = len(nums)
        if n <= 1:
            return 0
            
        idx0 = nums.index(0)
        
        # Check if cyclic increasing
        is_inc = True
        for i in range(n):
            if nums[(idx0 + i) % n] != i:
                is_inc = False
                break
                
        if is_inc:
            # Case 1: Pure increasing cyclic options
            path1 = idx0
            path2 = 2 + ((n - idx0) % n)
            return min(path1, path2)
            
        # Check if cyclic decreasing
        is_dec = True
        for i in range(n):
            if nums[(idx0 - i + n) % n] != i:
                is_dec = False
                break
                
        if is_dec:
            # Case 2: Pure decreasing cyclic options
            path1 = 1 + (n - 1 - idx0)
            path2 = 1 + ((idx0 + 1) % n)
            return min(path1, path2)
            
        # Case 3: Impossible arrangement
        return -1