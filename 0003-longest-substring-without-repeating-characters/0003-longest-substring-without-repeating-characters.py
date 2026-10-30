class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if(s==""):
            return 0;
        st=set()
        i=0
        maxlen=0
        for j in range(0,len(s)):
            while(s[j] in st):
                st.discard(s[i])
                i+=1
            st.add(s[j])
            l=j-i+1
            maxlen=max(maxlen,l)
        return maxlen