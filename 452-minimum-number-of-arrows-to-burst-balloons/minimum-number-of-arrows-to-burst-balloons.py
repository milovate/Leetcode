class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        # feelslike : merge intevals
        # 
        #           ____
        #    ___
        #  ___          _____

        # at x point how many ballons can we burst 
        # 

        n=len(points)
        if n == 1:
            return 1
        p=sorted(points)

        cnt=1
        x=p[0][0]
        y=p[0][1]


        for i in range(1,n,1):
            if(y >= p[i][0]):
                x=max(x,p[i][0])
                y=min(y,p[i][1])
            else :
                cnt+=1
                x=p[i][0]
                y=p[i][1]
        

        return cnt

        