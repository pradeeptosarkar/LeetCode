class Solution:
    class UnionFind:
        def __init__(self, n):
            self.parent = list(range(n))
            self.rank = [1] * n

        def find(self, x):
            if self.parent[x] != x:
                self.parent[x] = self.find(self.parent[x])
            return self.parent[x]

        def unite(self, x, y):
            rootX = self.find(x)
            rootY = self.find(y)

            if rootX != rootY:
                if self.rank[rootX] < self.rank[rootY]:
                    self.parent[rootX] = rootY
                elif self.rank[rootX] > self.rank[rootY]:
                    self.parent[rootY] = rootX
                else:
                    self.parent[rootX] = rootY
                    self.rank[rootY] += 1


    def canTraverseAllPairs(self, nums):
        n = len(nums)
        uf = self.UnionFind(n)

        factors = {}

        for i in range(n):
            for j in range(2, int(nums[i]**0.5) + 1):
                if nums[i] % j == 0:
                    factors.setdefault(j, []).append(i)
                    while nums[i] % j == 0:
                        nums[i] //= j
            if nums[i] > 1:
                factors.setdefault(nums[i], []).append(i)

        for factor, indices in factors.items():
            for i in range(1, len(indices)):
                uf.unite(indices[i-1], indices[i])

        root = uf.find(0)
        for i in range(1, n):
            if uf.find(i) != root:
                return False

        return True
