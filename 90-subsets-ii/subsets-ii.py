class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:

        n=len(nums)
        ans=[]
        nums.sort()

        def solve(ind,temp):
            ans.append(temp[:])
            for i in range(ind,n):
                if i>ind and nums[i]==nums[i-1]:
                    continue
                temp.append(nums[i])
                solve(i+1,temp)
                temp.pop()
        temp=[]
        solve(0,temp)
        return ans
        