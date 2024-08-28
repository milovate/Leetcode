class Solution {
public:

    int solve(int ind,vector<int>&nums,int res){
            if(ind==nums.size()){
                return res;
            }

            int pick =solve(ind+1,nums,res^nums[ind]);
            int notpick =solve(ind+1,nums,res);

            return pick+notpick;

    }



    int subsetXORSum(vector<int>& nums) {
        return solve(0,nums,0);
    }
};