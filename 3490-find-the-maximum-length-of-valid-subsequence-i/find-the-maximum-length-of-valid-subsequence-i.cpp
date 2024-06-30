class Solution {
public:
    int maximumLength(vector<int> &nums){
        int AllZeroes = 0 , AllOnes = 0;
        int ZeroOne = 0 , OneZero = 0;
        int ReqdForZeroOne = 0 , ReqdForOneZero = 1;

        for(int num : nums){
            int newNum = num % 2;

            if(newNum == 0) AllZeroes++;
            
            if(newNum == 1) AllOnes++;

            if(newNum == ReqdForZeroOne){
                ZeroOne++;
                ReqdForZeroOne ^= 1;
            }

            if(newNum == ReqdForOneZero){
                OneZero++;
                ReqdForOneZero ^= 1;
            }

        }
        return max({AllZeroes , AllOnes , ZeroOne , OneZero});

    }
};