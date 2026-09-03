class Solution:
    def gcdOfOddEvenSums(self, n: int) -> int:
        se=n**2
        so=se+n
        return math.gcd(so,se)