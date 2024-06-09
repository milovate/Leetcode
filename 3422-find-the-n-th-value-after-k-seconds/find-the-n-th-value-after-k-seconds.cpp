class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        const int MOD = 1e9 + 7;
        vector<int> vec(n, 1);
        for (int t = 0; t < k; ++t) {
            for (int i = 1; i < n; ++i) {
                vec[i] = (vec[i - 1] + vec[i]) % MOD;
            }
        }
        return vec[n - 1];
    }
};