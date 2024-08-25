class Solution:
        def largestPerimeter(self, A: List[int]) -> int:
            cur = sum(A)
            heapq._heapify_max(A)
            while A and cur <= A[0] * 2:
                cur -= heapq._heappop_max(A)
            return cur if len(A) > 2 else -1
        