class Solution:

    def preProcess(self,formula):
        fm = []

        for f in formula:
            if f.islower() or (f.isdigit() and fm[-1].isdigit()):
                fm[-1]+=f
            else:
                fm.append(f)
        return fm

        
    def countOfAtoms(self, formula: str) -> str:
        
        hm = dict()
        formula = [""]+self.preProcess(formula)[::-1]+[""]
        print(formula)
        d = 1
        n = len(formula)
        stack = []

        for i in range(1,n):
            f = formula[i]
            pf = formula[i-1]

            if f.isdigit():
                d = d * int(f)
            
            elif f == ')':
                stack.append(pf)
            
            elif f == '(':
                x = stack.pop()
                if x.isdigit(): d = d//int(x)
            
            else:
                hm[f] = hm.get(f,0) + d
                if pf.isdigit():
                    d = d//int(pf)
                    
        ans = list(hm.items())
        ans.sort()
        
        final = ""

        for f,n in ans:
            if n == 1:
                final += f
            else:
                final += f + str(n)
        
        return final
        

