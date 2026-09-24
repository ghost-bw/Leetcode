class Solution:
    def smallestIndex(self, nums: List[int]) -> int:
        for i,x in enumerate(nums):
            sum=0
            while(x>0):
                digit=x%10;
                sum+=digit
                x//=10
            if(sum==i):
                return i
        return -1
            