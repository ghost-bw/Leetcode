class Solution:
    def fairCandySwap(self, aliceSizes: list[int], bobSizes: list[int]) -> list[int]:

        diff = int((sum(bobSizes) - sum(aliceSizes)) / 2)
        searchset = set(bobSizes)
        
        return next(([x, x + diff] for x in aliceSizes if (x + diff) in searchset), [])
