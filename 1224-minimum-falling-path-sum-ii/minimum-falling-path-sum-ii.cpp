class Solution {
public:


    int dfs(int row,int col,vector<vector<int>>& grid,vector<vector<int>>&dp){
        int n=grid.size();
        int m=grid[0].size();

        if(row==n-1 && col<m && col>=0){
            return grid[row][col];
        }
          
        if(col>=m||col<0)return INT_MAX;
        if(dp[row][col]!=INT_MAX)return dp[row][col];
      
        int mini=INT_MAX;
         for(int k=0;k<m;k++){
            if(k!=col){
                mini=min(mini, dfs(row+1, k,grid,dp));
            }
        }

        return dp[row][col] = grid[row][col]+mini;

    }



    int minFallingPathSum(vector<vector<int>>& grid) {
        int mini=INT_MAX;        
                int rows=grid.size();
        int cols=grid[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, INT_MAX));

        for(int i=0;i<grid[0].size();i++){
            mini=min(dfs(0, i, grid,dp), mini);
        }
        return mini;
    }
};