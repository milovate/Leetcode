class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        mps={}
        mpt={}

        if len(s)!=len(t):
            return False
        
        for i,c in enumerate(s):
            # print(c)
            mps[c]= mps.get(c,0)+1

        for i,c in enumerate(t):
            mpt[c]=mpt.get(c,0)+1

        if mps==mpt:
            return True
        else:
            return False        