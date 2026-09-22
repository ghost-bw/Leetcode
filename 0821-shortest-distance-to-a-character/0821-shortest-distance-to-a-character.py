class Solution:
    def shortestToChar(self, s: str, c: str) -> list[int]:
        n=len(s)
        ans=[float(inf)]*n
        last=-1
        for i in range(0,n):
            if(s[i]==c):
                last=i
            if(last!=-1):
                ans[i]=i-last
        last=-1
        for i in range(n-1,-1,-1):
            if(s[i]==c):
                last=i
            if(last!=-1):
                ans[i]=min(ans[i],last-i)
        return ans