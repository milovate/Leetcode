class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        # seen = {}
        # for num in nums:
        #     if num in seen and seen[num] >= 1:
        #         return True
        #     seen[num] = seen.get(num,0)+ 1
        # print(seen)
        # return False


        d=collections.defaultdict(int)
        ans=0
        for num in nums:
            d[num]+=1
        
        for key,value in d.items():

            if value>1:
                ans+=1
                return True
        
        return False