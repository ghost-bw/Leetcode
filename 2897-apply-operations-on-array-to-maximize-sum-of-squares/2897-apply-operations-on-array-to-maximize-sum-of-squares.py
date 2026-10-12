class Solution:
    def maxSum(self, nums: list[int], k: int) -> int:
        MOD = 1_000_000_007
        bit_counts = [0] * 31
        
        # Step 1: Count the occurrences of each bit
        for num in nums:
            for i in range(31):
                if (num >> i) & 1:
                    bit_counts[i] += 1
                    
        ans = 0
        
        # Step 2: Form the k largest possible numbers
        for _ in range(k):
            current_num = 0
            for i in range(31):
                if bit_counts[i] > 0:
                    current_num |= (1 << i)
                    bit_counts[i] -= 1
            
            # Step 3: Add the square of the number to the answer
            ans = (ans + current_num * current_num) % MOD
            
        return ans
