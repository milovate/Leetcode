class Solution {
public:


    long long solve(int ind, bool parity,vector<int>&nums,vector<vector<long long>>&dp){
        int n=nums.size();

        if(ind == n){
            return 0;
        }
        if(dp[ind][int(parity)]!=-1){
            return dp[ind][int(parity)];
        }

        long long pick=LLONG_MIN;
        long long notpick=LLONG_MIN;
        if(parity){
                     pick= 1ll*nums[ind]+solve(ind+1,!parity,nums,dp);
                     notpick= solve(ind+1,parity,nums,dp);
        
        }
        else{
                    pick= -1ll*nums[ind]+solve(ind+1,!parity,nums,dp);
                    notpick= solve(ind+1,parity,nums,dp);

        }

        return dp[ind][int(parity)]=max(pick,notpick);
    }



    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<long long>> dp(n,vector<long long>(2,-1));
        return solve(0,1,nums,dp);

    }
};