class Solution:
    def isSubsetSum(self,arr:list[int],targetsum:int)->bool:
        dp=[False]*(targetsum+1)
        dp[0]=True
        for num in arr:
            for j in range(targetsum,num-1,-1):
                dp[j]=dp[j] or dp[j-num]
        return dp[targetsum]
    def canPartition(self, nums: list[int]) -> bool:
        total=sum(nums)
        if total%2!=0:
            return False
        return self.isSubsetSum(nums,total//2)