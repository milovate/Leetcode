class Solution:
    def letterCombinations(self, digits: str):
        if not digits:
            return []
        
        # Mapping of digits to corresponding letters
        key = ["", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
        
        def backtrack(index: int, path: str):
            # Base case: If the current path is complete, add it to the results
            if index == len(digits):
                ans.append(path)
                return
            
            # Get the letters that the current digit can represent
            possible_letters = key[int(digits[index])]
            
            # Iterate through all possible letters and backtrack
            for letter in possible_letters:
                backtrack(index + 1, path + letter)
        
        # Initialize the result list
        ans = []
        
        # Start the backtracking process
        backtrack(0, "")
        
        return ans
