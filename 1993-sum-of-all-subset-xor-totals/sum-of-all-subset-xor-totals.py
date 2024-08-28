class Solution:
    def subsetXORSum(self, nums: List[int]) -> int:

        n=len(nums)

        def solve (ind:int,nums:List[int],res:int)->int:
            
            if ind==len(nums):
                return res
        
            pick=solve(ind+1,nums,nums[ind]^res)
            npick=solve(ind+1,nums,res)

            return pick+npick
        
        return solve(0,nums,0)