class Solution:
    
    def peakIndexInMountainArray(self, arr: list[int]) -> int:
        if not arr or len(arr) == 0:
            return -1
        n = len(arr) - 1
        l , r = 0, n
        while l < r:
            m = (l + r) // 2
            if arr[m] < arr[m+1]:
                l = m +1
            else:
                r = m
        return l
