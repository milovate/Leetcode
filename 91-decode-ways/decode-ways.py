class Solution:
    def numDecodings(self, s: str) -> int:
        # Initialize
        memo = {}

        
        def find_ways(index):

            # Check if done
            if index == len(s):
                return 1
            # Check if invalid
            elif s[index] == '0':
                return 0
            # Check if last digit
            elif index == len(s) - 1:
                return 1
            # CHeck if visited before
            elif index in memo:
                return memo[index]
            
            # Add 1 way
            ways = find_ways(index + 1)
            # Potentially add second way
            if int(s[index:index + 2]) <= 26:
                ways += find_ways(index + 2)
            
            # Save and return
            memo[index] = ways
            return ways
        
        # Start recursion
        return find_ways(0)

# class Solution:
#     def numDecodings(self, s: str) -> int:

        
#         #  taken till 2 digits and less than 26
#         if s[0]=='0':
#             return 0
#         n=len(s)

#         dp=[0]*(n+1)

#         dp[0]=1
#         dp[1]=1


#         for i in range(2,n+1,1):
        
#             one=int(s[i-1])
#             if one >=1 and one<=9:
#                 dp[i]+=dp[i-1]
            
#             ten=int(s[i-2:i])

#             if ten>=10 and ten<=26:
#                 dp[i]+=dp[i-2]

#             # print(one,ten)

#         return dp[n]
