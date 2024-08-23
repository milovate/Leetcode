from fractions import Fraction as f

class Solution:
    def fractionAddition(self, exp):
        res = sum(map(f, exp.replace('+', ' +').replace('-', ' -').split()))
        return '%s/%s' % (res.numerator, res.denominator)
        