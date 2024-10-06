class Solution:
    def longestPalindrome(self, s: str) -> str:

        n=len(s)
        if n == 0:
            return ""
        dp=[[False]*n for _ in range(n)]

        start=0
        max_length=1

        for i in range(n):
            dp[i][i]=True   
        
        for i in range(n-1):
            if s[i]==s[i+1]:
                dp[i][i+1]=True 
                start=i
                max_length=2

        for length in range(3,n+1):
            for left in range(n-length+1):
                right=left+length-1
                if s[left]==s[right] and dp[left+1][right-1]:
                    dp[left][right]=True
                    max_length=length
                    start=left

        return s[start:start+max_length]

        