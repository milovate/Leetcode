import sys 


class Solution:
    def beautySum(self, s: str) -> int:
        ans=0
        for i in range(len(s)):
            t=""

            for j in range(i,len(s),1):
                t+=s[j]
                d=collections.Counter(t)
                mini=1000000000000
                maxi=0
                for c,x in d.items():
                    maxi=max(maxi,x)
                    mini=min(mini,x)
                ans+=abs(maxi-mini)
                # print(ans)
                # print(d)


        return ans



        