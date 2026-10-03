class Solution:
    def findMaxConsecutiveOnes(self, nums: list[int]) -> int:
        mxcnt=cnt=0
        for i in nums:
            if i==1:
                cnt+=1
                mxcnt=max(cnt,mxcnt)
            else:
                cnt=0
        return mxcnt