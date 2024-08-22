class Solution:



    def dfs(self, row:int,col:int,grid: List[List[int]],vis: List[List[int]]) ->int:
        m=len(grid)
        n=len(grid[0])

        vis[row][col]=1

        dx = [1,-1,0,0]
        dy = [0,0,-1,1]
        
        res=1
        for i in range(4):
            nrow=dx[i]+row
            ncol=dy[i]+col

            if nrow>=0 and nrow <m and ncol>=0 and ncol<n and vis[nrow][ncol]==0 and grid[nrow][ncol]:
                res+=self.dfs(nrow,ncol,grid,vis)

        return res



    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        m=len(grid)
        n=len(grid[0])
        # vis=[[0]*n]*m
        # print(vis)
        vis=[[0]*n for _ in range(m)]
        # print(" ")
        # print(vis2)

        ans = 0
        marea = 0

        for i in range(m):
            for j in range(n):
                if vis[i][j] == 0 and grid[i][j]==1:
                    ans=max(ans,self.dfs(i,j,grid,vis)) 


        return ans


        