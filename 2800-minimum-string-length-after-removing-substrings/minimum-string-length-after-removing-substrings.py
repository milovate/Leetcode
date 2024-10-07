class Solution:
    def minLength(self, s: str) -> int:
        s = list(s)
        top = -1
        for i in range(len(s)):
            if top >= 0 and s[top] + s[i] in ("AB","CD"):
                top -= 1
            else:
                top += 1
                s[top] = s[i]
        return top + 1