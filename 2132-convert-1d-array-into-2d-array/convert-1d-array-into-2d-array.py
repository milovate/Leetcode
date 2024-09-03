class Solution:
    def construct2DArray(self, original: List[int], m: int, n: int) -> List[List[int]]:
        ans = []
        if len(original) == m*n: 
            for i in range(0, len(original), n): 
                ans.append(original[i:i+n])
        return ans 