import heapq

class Solution:
    def getFinalState(self, nums: List[int], k: int, multiplier: int) -> List[int]:
        # make a heap of pair then 
        minheap = []
        for ix,val in enumerate(nums):
            heapq.heappush(minheap, (val,ix))
        i = 0
        while minheap and i < k:
            x, y = heapq.heappop(minheap)
            heapq.heappush(minheap, (x*multiplier,y))
            i += 1
        # print(minheap)
        return [i for i,j in sorted(minheap,key = lambda x : x[1])]





        