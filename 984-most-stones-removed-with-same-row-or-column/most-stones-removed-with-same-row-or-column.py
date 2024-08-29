
class DSU:
    def __init__(self,n):
        self.parent=list(range(n))
        self.rank=[1]*n

    def find(self,x):
        if self.parent[x]!=x:
            self.parent[x]=self.find(self.parent[x])
        return self.parent[x]
    
    def union(self, x, y):
        rootX = self.find(x)
        rootY = self.find(y)

        if rootX != rootY:
            # Union by rank heuristic
            if self.rank[rootX] > self.rank[rootY]:
                self.parent[rootY] = rootX  # Attach smaller tree under larger tree
            elif self.rank[rootX] < self.rank[rootY]:
                self.parent[rootX] = rootY
            else:
                self.parent[rootY] = rootX
                self.rank[rootX] += 1  # Increase rank if both trees are of equal rank
    
    def num_components(self):
        x = set([])
        for i in range(len(self.parent)):
            x.add(self.find(i))
        return len(x)
    




class Solution:
    def removeStones(self, stones: List[List[int]]) -> int:

        uf=DSU(len(stones))
        col_prev = {}
        row_prev = {}
        for i, (x, y) in enumerate(stones):
            if x in row_prev:
                uf.union(i, row_prev[x])
            if y in col_prev:
                uf.union(i, col_prev[y])
            row_prev[x] = i
            col_prev[y] = i
            
        return len(stones) - uf.num_components()
        

        
        