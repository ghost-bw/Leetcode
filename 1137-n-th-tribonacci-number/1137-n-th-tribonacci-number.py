class Solution:
    def tribonacci(self, n: int) -> int:
        if(n==0 or n==1):
            return n
        if(n==2):
            return 1
        first,second,third=0,1,1
        
        for i in range(3,n+1):
            sum=first+second+third
            first=second
            second=third
            third=sum
        return sum