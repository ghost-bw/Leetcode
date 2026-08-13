class Solution:
    def rotatedDigits(self, n: int) -> int:
        ans=0;
        for i in range(0,n+1):
            s=str(i)
            if any(c in '347' for c in s):
                continue
            if any(c in "2569" for c in s):
                ans+=1;
        return ans;
        