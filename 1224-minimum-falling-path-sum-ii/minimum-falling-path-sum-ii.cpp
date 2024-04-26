class Solution {
public:
    int recur(int r, int i, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if(r==matrix.size()-1 && i<matrix[0].size() && i>=0){
            return matrix[r][i];
        }
        if(i>=matrix[0].size() || i<0) return INT_MAX;
        if(dp[r][i]!=INT_MAX)return dp[r][i];
        
        int mini=INT_MAX;
        for(int k=0;k<matrix[0].size();k++){
            if(k!=i){
                mini=min(mini, recur(r+1, k, matrix, dp));
            }
        }
        
        return dp[r][i] = matrix[r][i]+mini;
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, INT_MAX));
        
        int mini=INT_MAX;        
        for(int i=0;i<matrix[0].size();i++){
            mini=min(recur(0, i, matrix, dp), mini);
        }
        return mini;
    }
};