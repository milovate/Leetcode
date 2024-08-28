class Solution:
    def permute(self, l: List[int]) -> List[List[int]]:
        n=len(l)
        def dfs(ind,temp):
            if len(temp)==n:
                res.append(temp[:])

            for i in range(n):
                if temp.count(l[i])!=0:
                    continue
                temp.append(l[i])
                dfs(ind+1,temp)
                temp.pop()

                    
        res = []
        # dfs([], [False] * len(l), res)
        
        dfs(0,[])
        return res