class Solution:
    def checkIfPangram(self, sentence: str) -> bool:
        lis=[1]*26
        for s in sentence:
            lis[ord(s)-ord('a')]-=1
        for i in lis:
            if i>0:
                return False
        return True