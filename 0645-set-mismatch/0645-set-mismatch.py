class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        n=len(nums)
        totaln_sum=(n*(n+1))//2;
        unique_sum=sum(set(nums))
        actual_sum=sum(nums)
        duplicate=actual_sum-unique_sum
        missing=totaln_sum-unique_sum
        return [duplicate,missing]