class Solution {
    private:
    int solve(vector<int> &nums,int k)
    {
        int i=0,j=0;
        int n=nums.size();
        int ans=0;


        while(j<n)
        {
            if(nums[j]%2)k--;
            while(k<0)
            {
                if(nums[i]%2)
                {
                    k++;
                }
                i++;
            }
            ans+=j-i+1;
            j++;
        }
        return ans;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);
    }
};