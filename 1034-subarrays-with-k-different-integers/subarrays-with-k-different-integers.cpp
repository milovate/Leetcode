class Solution {
public:

    int solve(vector<int> nums,int k){
        if(k==0)return 0;
        int n=nums.size();
        int count=0;
        int j=0;
        int i=0;
        int ans=0;
        map<int,int> mp;
        while(j<n){

            mp[nums[j]]++;

            while(mp.size() > k && i<j){
                    mp[nums[i]]--;
                   if(mp[nums[i]]==0){mp.erase(nums[i]);}
                    i++;    
                    // decrease arr[i] from hash 
                    // if hash becomes zero delete that index
            }

            ans+=j-i+1;
            j++;

        }

        return ans;
    }


    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);

    }
};