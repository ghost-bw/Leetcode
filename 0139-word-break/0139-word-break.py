class Solution:
    def wordBreak(self, s: str, wordDict: list[str]) -> bool:
        n=len(s)
        st=set(wordDict)
        dp=[False]*(n+1)
        dp[0]=True
        maxlen=0
        for x in wordDict:
            maxlen=max(maxlen,len(x))

        for i in range(1,n+1):
            for j in range(max(0,i-maxlen),i):
                if dp[j] and s[j:i] in st:
                    dp[i]=True
                    break
        return dp[n]