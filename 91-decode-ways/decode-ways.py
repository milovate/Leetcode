class Solution:
    def numDecodings(self, s: str) -> int:

        
        #  taken till 2 digits and less than 26
        if s[0]=='0':
            return 0
        n=len(s)

        dp=[0]*(n+1)

        dp[0]=1
        dp[1]=1


        for i in range(2,n+1,1):
        
            one=int(s[i-1])
            if one >=1 and one<=9:
                dp[i]+=dp[i-1]
            
            ten=int(s[i-2:i])

            if ten>=10 and ten<=26:
                dp[i]+=dp[i-2]

            # print(one,ten)

        return dp[n]
