class Solution:
    def minAddToMakeValid(self, S: str) -> int:
        unmatched_open_brackets = unmatched_close_brackets = 0
        for c in S:
            if c == '(':
                unmatched_open_brackets += 1
            elif unmatched_open_brackets > 0:
                unmatched_open_brackets -= 1    
            else:
                unmatched_close_brackets += 1
        return unmatched_open_brackets + unmatched_close_brackets
        