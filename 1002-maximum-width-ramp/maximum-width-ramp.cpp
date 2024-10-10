class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<pair<int,int>>st;
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            if(st.empty()||nums[i]<st.top().first){

                st.push({nums[i],i});}
        }



        for(int i=n-1;i>=0;i--){
            while (!st.empty() && nums[i] >= st.top().first) {
                ans = max(ans, i - st.top().second);
                st.pop();
            }

            }

        return ans;
        
        
    }
};