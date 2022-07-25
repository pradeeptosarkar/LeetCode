class Solution:
    def equalPairs(self, grid: List[List[int]]) -> int:
        st = defaultdict(int)
        
        for i in range(len(grid)):
            st[tuple(grid[i])] += 1
        
        for i in range(len(grid)):
            for j in range(i):
                grid[i][j],grid[j][i] = grid[j][i],grid[i][j]
        ans = 0
        
        for i in range(len(grid)):
            if tuple(grid[i]) in st:
                ans += st[tuple(grid[i])]
        
        return ans