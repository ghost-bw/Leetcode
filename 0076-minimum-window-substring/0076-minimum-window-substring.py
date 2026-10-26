class Solution:
    def find(self,have,need):
        for i in range(256):
            if have[i]<need[i]:
                return False
        return True
    def minWindow(self, s: str, t: str) -> str:
        n=len(s)
        if len(t)>n:
            return ""
        have=[0]*256
        need=[0]*256
        for x in t:
            need[ord(x)]+=1
        minlen=float('inf')
        low=0
        arrs=list(s)
        for high in range(n):
            have[ord(s[high])]+=1
            while(self.find(have,need)):
                length=high-low+1
                if length<minlen:
                    minlen=length
                    start=low
                have[ord(s[low])]-=1
                low+=1
        return "" if minlen==float('inf') else "".join(arrs[start:start+minlen])
                