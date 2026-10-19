class Solution:
    def isMonotonic(self, nums: list[int]) -> bool:
        increasing=True
        decreasing=True
        n=len(nums)
        if(n==1):return True
        for i in range(0,n-1):
            if(nums[i]<nums[i+1]):
                decreasing=False
            if(nums[i]>nums[i+1]):
                increasing=False
        return decreasing or increasing
