class Solution {
    using ll = long long;
    ll find(int ind, const vector<int>& nums, bool flag, vector<vector<ll>>& dp) {
        if (ind == (int)nums.size()) return 0;
        if (dp[ind][flag] != LLONG_MIN) return dp[ind][flag];
        ll old = 0;
        if (flag) {
            old = nums[ind] + find(ind + 1, nums, false, dp);
        } else {
            old = -(nums[ind]) + find(ind + 1, nums, true, dp);
        }
        ll new_val = nums[ind] + find(ind + 1, nums, false, dp);
        return dp[ind][flag] = max(old, new_val);
    }
public:
    long long maximumTotalCost(vector<int>& nums) {
        int n = nums.size();
        vector<vector<ll>> dp(n + 1, vector<ll>(2, LLONG_MIN)); 
        return find(0, nums, true, dp);
    }
};