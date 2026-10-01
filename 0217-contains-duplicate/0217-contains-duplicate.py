class Solution:
    def containsDuplicate(self, nums: list[int]) -> bool:
        mp={}
        for n in nums:
            if n in mp:
                return True
            mp[n]=1;
        return False