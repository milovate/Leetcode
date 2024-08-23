class Solution:
    def replaceElements(self, arr: List[int]) -> List[int]:

        max_right=-1
        res=[[-1]for _ in range(len(arr))]
        for i in range(len(arr)-1,-1,-1):
            res[i]=max_right
            max_right=max(max_right,arr[i])

        return res
        