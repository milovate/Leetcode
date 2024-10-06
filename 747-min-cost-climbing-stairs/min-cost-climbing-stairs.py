
class Solution:

    def minCostClimbingStairs(self, cost: list) -> int:
        n = len(cost)
        
        
        dp = [0] * (n + 1)
        dp[n] = 0
                
        for i in range(n - 1, -1, -1):
            if i == n - 1:
                dp[i] = cost[i]  
            else:
                dp[i] = cost[i] + min(dp[i + 1], dp[i + 2])

        return min(dp[0], dp[1])
