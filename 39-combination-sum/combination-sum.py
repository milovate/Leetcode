class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        # either stay at the place and keep adding 
        # or move forward if next element is less than target 
        
        n=len(nums)
        ans=[]
        t=target
        
        def solve(ind,t,temp):
            if ind==n:
                if(t==0):
                    ans.append(temp[:])
                return
            # print(temp)
            if t >= nums[ind]:
                temp.append(nums[ind])
                solve(ind,t-nums[ind],temp)
                temp.pop()
            solve(ind+1,t,temp)

            return

        temp=[]
        solve(0,t,temp)
        return ans

        