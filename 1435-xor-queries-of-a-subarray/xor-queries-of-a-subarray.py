class Solution:
    def xorQueries(self, arr: List[int], queries: List[List[int]]) -> List[int]:
        for i in range(len(arr)-1):
            arr[i+1]^=arr[i]
        return [arr[j]^arr[i-1] if i else arr[j] for i,j in queries]



        