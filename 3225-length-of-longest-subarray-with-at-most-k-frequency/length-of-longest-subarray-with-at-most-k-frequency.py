class Solution:
    def maxSubarrayLength(self, nums: List[int], k: int) -> int:
        # feels like sliding window 
        # 

        i=0
        j=0
        n=len(nums)
        freq=defaultdict(int)
        ans=0
        while(i<n):
            freq[nums[i]]+=1
            while(freq[nums[i]]>k and j<i and j<n):
                freq[nums[j]]-=1
                j+=1
            ans=max(i-j+1,ans)
            i+=1
        


        return ans