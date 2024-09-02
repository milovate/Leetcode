class Solution:
    def chalkReplacer(self, chalk: List[int], k: int) -> int:
        # feels like prefix sum 
        # 5 6 11
        # 22/maxium-1
        # 3 4 1 2
        # 3 7 8 10
        # 25
        # 25/10 = 2
        # 25-2*10 =5 =mod 10 

        k %= sum(chalk)
        for i, num in enumerate(chalk):
            if k >= num: k -= num
            else: return i
        return -1



        