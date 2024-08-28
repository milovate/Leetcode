class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        n=len(nums)
        ans=[]


        def solve(ind:int,temp:List[int]):
            if ind ==n :
                ans.append(temp[:])
                return
            # print(temp)
            temp.append(nums[ind])
            solve(ind+1,temp)
            temp.pop()
            solve(ind+1,temp)
            return

        temp=[]
        solve(0,temp)
        return ans
        