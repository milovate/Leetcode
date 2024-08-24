func letterCombinations(digits string) []string {
    
    if len(digits) == 0 {
        return []string{}
    }

    key := []string{
        "",    // 0
        "",    // 1
        "abc", // 2
        "def", // 3
        "ghi", // 4
        "jkl", // 5
        "mno", // 6
        "pqrs", // 7
        "tuv", // 8
        "wxyz", // 9
    }

    var ans []string
    var backtrack func(index int, path string)
    
    backtrack = func(index int, path string) {
        if index == len(digits) {
            ans = append(ans, path)
            return
        }

        digit := digits[index] - '0'
        possibleLetters := key[digit]

        for _, letter := range possibleLetters {
            backtrack(index+1, path+string(letter))
        }
    }

    backtrack(0, "")
    return ans
}