class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> indices;
        vector<int> result;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == x) {
                indices.push_back(i);
            }
        }

        for (int query : queries) {
            if (query <= indices.size()) {
                result.push_back(indices[query - 1]);
            } else {
                result.push_back(-1);
            }
        }

        return result;
    }
};