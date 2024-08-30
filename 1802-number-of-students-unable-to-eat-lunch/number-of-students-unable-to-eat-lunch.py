from collections import deque
class Solution:
    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
        stack=[]
        q=deque()
        cnt=0

        for idx,x in enumerate(students):
            q.append(x)
        q.reverse()
        
        for idx,x in enumerate(sandwiches):
            stack.append(x)
        stack.reverse()


        while(cnt!=len(q)):
            print(q)
            print(cnt)
            if len(q)==0:
                 return 0
            if len(q)>0 and stack[-1]==q[0]:
                stack.pop()
                q.popleft()
                cnt=0
            else :
                q.append(q.popleft())
                cnt+=1
                
        
        return len(q)
            

        