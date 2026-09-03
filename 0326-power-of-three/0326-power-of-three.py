class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        ex=1
        m=n
        if n<=0:
            return False
        while(m>1):
            ex*=3
            m/=3
        return (ex==n)