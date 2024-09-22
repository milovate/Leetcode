import math
class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:



        def checkPossible(node) -> bool:
            hrsTaken=0
            for x in piles:
                hrsTaken+=math.ceil(x/node)
            # print(hrsTaken)
            return hrsTaken<=h
        
        

        left=1
        right= max(piles)

        while(left<=right):
            mid=left+(right-left)//2

            # print(mid)
            # print(checkPossible(mid))

            if checkPossible(mid):
                right=mid-1
            else :
                left=mid+1
        

        return left




        