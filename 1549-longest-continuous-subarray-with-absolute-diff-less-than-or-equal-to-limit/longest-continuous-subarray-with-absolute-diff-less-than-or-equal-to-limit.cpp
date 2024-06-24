class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        //keep track
        int n=nums.size();
        int i=0,j=0;
        int ans=0;
        multiset<int>m;
        while(j<n){

            m.insert(nums[j]);
            int mini=*m.begin();
            int maxi=*(--m.end());
            while(maxi-mini>limit && i<j)
            {
                auto it=m.find(nums[i]);
                m.erase(it);
                i++;
                mini=*m.begin();
                maxi=*(--m.end());
                
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;

    }
};