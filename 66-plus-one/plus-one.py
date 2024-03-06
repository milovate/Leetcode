class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        digits=digits[::-1]
        carry=1
        for i in range(len(digits)):

            if digits[i]==9 and carry==1 :
                carry=1
                digits[i]=0
            else :
                digits[i]+=carry
                carry = 0
                break
        if(carry==1):
            digits.append(1)
        digits=digits[::-1]
        print(digits)
        return digits
            
        