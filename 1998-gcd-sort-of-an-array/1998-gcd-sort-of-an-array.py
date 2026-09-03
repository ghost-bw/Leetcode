class UnionFind:
    def __init__(self, size):
        self.parent = list(range(size))
        
    def find(self, i):
        if self.parent[i] == i:
            return i
        # Path compression
        self.parent[i] = self.find(self.parent[i])
        return self.parent[i]
        
    def union(self, i, j):
        root_i = self.find(i)
        root_j = self.find(j)
        if root_i != root_j:
            self.parent[root_i] = root_j

class Solution:
    def gcdSort(self, nums: list[int]) -> bool:
        max_num = max(nums)
        
        # 1. Sieve of Eratosthenes to find the Smallest Prime Factor (SPF)
        spf = list(range(max_num + 1))
        for i in range(2, int(max_num**0.5) + 1):
            if spf[i] == i:
                for j in range(i * i, max_num + 1, i):
                    if spf[j] == j:
                        spf[j] = i
                        
        uf = UnionFind(max_num + 1)
        
        # 2. Union each number with all of its prime factors
        for num in nums:
            temp = num
            while temp > 1:
                factor = spf[temp]
                uf.union(num, factor)
                while temp % factor == 0:
                    temp //= factor
                    
        # 3. Check if elements can reach their correctly sorted destinations
        sorted_nums = sorted(nums)
        for i in range(len(nums)):
            if uf.find(nums[i]) != uf.find(sorted_nums[i]):
                return False
                
        return True
