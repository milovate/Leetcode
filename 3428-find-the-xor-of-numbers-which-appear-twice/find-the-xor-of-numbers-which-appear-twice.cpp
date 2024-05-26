class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_map<int, int> countMap;
        for (int num : nums) {
            countMap[num]++;
        }
        int result = 0;
        for (auto& entry : countMap) {
            if (entry.second == 2) {
                result ^= entry.first;
            }
        }
        return result;
    }
};