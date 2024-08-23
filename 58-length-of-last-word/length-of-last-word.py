# class Solution:
#     def lengthOfLastWord(self, s: str) -> int:
#         arr=s.split()
#         return len(arr[-1])
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        s=s.strip()
        s=s.split()
        return len(s[-1])
        