class Solution:

    def recurStair(self,ind :int,n:int,dp:list)-> int:
        if ind==n:
            return 1

        if ind>n:
            return 0 
            
        if dp[ind]!=0:
            return dp[ind]
        dp[ind]=self.recurStair(ind+1,n,dp)+self.recurStair(ind+2,n,dp)
        return dp[ind] 


    def climbStairs(self, n: int) -> int:

        dp=[0]*(n+1)
        return self.recurStair(0,n,dp)


        
        
        