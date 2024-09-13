# class Solution:
#     def splitArray(self, nums: List[int], k: int) -> int:
        

#         7 9 14 24 32
#         k=2
#         32/2 =15.2 get the lowerbound

#         1 2 3 4 5
#         1 3. 6. 10 15
#         15 14 12. 9 .5
#         k=3
#         15/3=5


#         4 1 .2 3 .5 

class Solution:
    def splitArray(self, nums: List[int], m: int) -> int:
        sums = list(itertools.accumulate(nums))
        L, H = max(nums), sums[-1]
        while L < H:
            nSubarrays, sumThruPrevSubarray, MID = 0, 0, (L + H) // 2
            i = 0
            while i < len(nums):
                i = bisect.bisect_right(sums, MID + sumThruPrevSubarray, i + 1)
                nSubarrays, sumThruPrevSubarray = nSubarrays + 1, sums[i - 1]
            if nSubarrays > m:
                L = MID + 1
            else:
                H = MID
        return H

