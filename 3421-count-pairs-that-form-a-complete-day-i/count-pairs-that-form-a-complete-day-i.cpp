class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        unordered_map<int, int> seenMap;
        long long count = 0;

        for (int hour : hours) {
            int rem = hour % 24;
            int complement = (24 - rem) % 24;
            if (seenMap.find(complement) != seenMap.end()) {
                count += seenMap[complement];
            }
            seenMap[rem]++;
        }

        return count;
    }
};