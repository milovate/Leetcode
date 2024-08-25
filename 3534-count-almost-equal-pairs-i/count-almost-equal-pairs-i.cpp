class Solution {
public:

    bool check(const std::string& a, const std::string& b, 
               const std::unordered_map<char, int>& mpa, 
               const std::unordered_map<char, int>& mpb) {
        if (a == b) return true;
        if (mpa != mpb) return false; // Early return if frequency maps differ

        int cnt = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) cnt++;
            if (cnt > 2) return false; // Early exit if more than two mismatches
        }

        return (cnt == 2);
    }



    int countPairs(vector<int>& nums) {

  int n = nums.size();
        std::vector<std::string> strNums(n);
        std::vector<std::unordered_map<char, int>> freqMaps(n);

        // Precompute the strings and their corresponding frequency maps
        for (int i = 0; i < n; i++) {
            strNums[i] = std::to_string(100000000 + nums[i]); // Normalize and convert to string
            for (char c : strNums[i]) {
                freqMaps[i][c]++;
            }
        }

        int ans = 0;
        // Compare each pair of precomputed strings and their frequency maps
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (check(strNums[i], strNums[j], freqMaps[i], freqMaps[j])) {
                    ans++;
                }
            }
        }

        return ans;
        
    }
};