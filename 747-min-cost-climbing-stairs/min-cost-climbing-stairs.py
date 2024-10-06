class Solution:


    def recurStair(self,ind :int,n:int,dp:list,cost:list)-> int:
        if ind==n:
            return 0
        if ind>n:
            return 1e9 
        if dp[ind]!=0:
            return dp[ind]

        dp[ind]=min(self.recurStair(ind+1,n,dp,cost)+cost[ind],self.recurStair(ind+2,n,dp,cost)+cost[ind])
        return dp[ind] 

    def minCostClimbingStairs(self, cost: List[int]) -> int:
        dp=[0]*(len(cost)+1)
        return min(self.recurStair(0,len(cost),dp,cost),self.recurStair(1,len(cost),dp,cost))
        