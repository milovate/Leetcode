from sortedcontainers import SortedList
from typing import List

class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        # Use a SortedList to maintain the elements in sorted order
        st = SortedList()
        n = len(nums)
        ans = [0] * n
        
        for i in range(n - 1, -1, -1):
            # Find the number of elements smaller than nums[i]
            x = st.bisect_left((nums[i], 0))
            # Insert the current element with its index to maintain uniqueness
            st.add((nums[i], i))
            # Store the result
            ans[i] = x
        
        return ans
