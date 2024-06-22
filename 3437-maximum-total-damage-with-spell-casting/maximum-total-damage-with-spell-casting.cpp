class Solution {
public:

    long long solve(map<int,int>&mp,vector<int>&power,int ind,vector<long long>&dp){
        int n=power.size();
        if(ind>=n)return 0;
        if(dp[ind]!=-1)return dp[ind];
        // skip that index 
        long long pick1=solve(mp,power,ind+1,dp);
        //pick an index => cant pick 
        long long pick2=0;
        long long nextind=ind+1;
        while(nextind<n&&power[nextind]-power[ind]<=2){
            nextind++;
           
        }
        pick2=(1ll*mp[power[ind]]*power[ind])+solve(mp,power,nextind,dp);
        return dp[ind]=max(pick1,pick2);
    }






    long long maximumTotalDamage(vector<int>& power) {  map<int, int> frequencyMap;
        vector<int> uniquePowers;
        map<int, int> mp;
       
        for (auto p : power) {
            mp[p]++;
        }
        for (auto it : mp) {
            uniquePowers.push_back(it.first);
        }
         vector<long long>dp(mp.size(),-1);
        sort(power.begin(),power.end());
        //get all the unique elements 
        //map<int,int>
        return solve(mp,uniquePowers,0,dp);
    }
};