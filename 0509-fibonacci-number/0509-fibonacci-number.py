class Solution:
    def fib(self, n: int) -> int:
        if n<=1:
            return n
        prev1,prev2=1,1
        for i in range(1,n-1):
            sum=prev1+prev2
            prev2=prev1
            prev1=sum
        return prev1