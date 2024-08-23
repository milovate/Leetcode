# class Solution:


#     def helper(self , a:List[int],b:List[int]) -> int :
#         d=collections.defaultdict(int)
#         ans = 0
#         for i in range(len(a)):
#             d[a[i]]+=1
#         for i in range(len(b)):
#             target=b[i]*b[i]
#             for j in range(len())




#     def numTriplets(self, nums1: List[int], nums2: List[int]) -> int:
#         """
#         save all squares and index 
#         of both 

#         sort both the arrays
        
#         4,7
#         2,5,8,9

#         16  4 
#         49  25
#             64
#             81

#         """







from collections import defaultdict

class Solution:
    def count(self, A, B):
        ans = 0
        freq = defaultdict(int)
        for n in B:
            freq[n] += 1
        for a in A:
            target = a * a
            for b, cnt in freq.items():
                if target % b != 0 or (target // b) not in freq:
                    continue
                if target // b == b:
                    ans += cnt * (cnt - 1)
                else:
                    ans += cnt * freq[target // b]
        return ans // 2

    def numTriplets(self, A, B):
        return self.count(A, B) + self.count(B, A)
