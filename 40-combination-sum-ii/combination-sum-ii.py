class Solution:
    def combinationSum2(self, c: List[int], target: int) -> List[List[int]]:
        res=[]
        c.sort()
        n=len(c)

        def solve(ind,t,temp):
            if t==0:
                # print(temp)
                res.append(temp[:])
                return
            if t<0 :
                return
            # print(temp)

            for i in range(ind,n):
                
                if( i>ind and c[i]==c[i-1]):
                    continue

                temp.append(c[i])
                solve(i+1,t-c[i],temp)
                temp.pop()



        temp=[]
        solve(0,target,temp)
        return res
        