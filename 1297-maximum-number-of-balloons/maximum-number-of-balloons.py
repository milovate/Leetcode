class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        freq=defaultdict(int)
        for i in range(len(text)):
            freq[text[i]]+=1

        cnt =1e9
        cnt=min(cnt,freq['b'])
        cnt=min(cnt,freq['a'])
        cnt=min(cnt,freq['l']//2)
        cnt=min(cnt,freq['o']//2)
        cnt=min(cnt,freq['n'])

        return cnt