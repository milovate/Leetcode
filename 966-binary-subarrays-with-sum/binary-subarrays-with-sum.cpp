class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
    
        map<int,int> mp;
        int n=nums.size();

        mp[0]=1;// basically mp[ps-goal]we can always add 1 when prefix == goal count++;

int count=0;
        int ps=0;

        for(int i=0;i<n;i++){
            ps+=nums[i];
            if(mp[ps-goal])count+=mp[ps-goal];
            mp[ps]++;

            

        }
return count;
    }
};