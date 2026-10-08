class Solution:
    def deleteAndEarn(self, nums: list[int]) -> int:
        if not nums:
            return 0
        freq=[0]*(max(nums)+1)
        for num in nums:
            freq[num]+=num
        prev1,prev2=0,0
        for x in freq:
            curr=max(prev2+x,prev1)
            prev2=prev1
            prev1=curr
        return prev1