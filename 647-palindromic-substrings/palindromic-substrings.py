class Solution:
    def countSubstrings(self, s: str) -> int:
        
        n=len(s)

        dp=[[False]*n for _ in range(n)]
        # count True in the dp array 
        cnt=0
        for i in range(n):
            cnt+=1
            dp[i][i]=True
        for i in range(n-1):
            if s[i]==s[i+1]:
                dp[i][i+1]=True
                cnt+=1

        for length in range(3,n+1):
            for left in range(n-length+1):
                right=length+left-1
                if s[left]==s[right] and dp[left+1][right-1]:
                    dp[left][right]=True
                    cnt+=1
            




        return cnt

        