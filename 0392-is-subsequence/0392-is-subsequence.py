class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        if(len(s)==0):
            return True
        i,j=0,0
        for i in range(0,len(t)):
            if(s[j]==t[i]):
                j+=1;
            else:
                continue
            if(j==len(s)):
                return True
        return False