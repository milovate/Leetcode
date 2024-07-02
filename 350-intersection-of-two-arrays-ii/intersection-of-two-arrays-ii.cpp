class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        

        //mp
        //  
        int n=nums1.size();
        int m=nums2.size();

        unordered_map<int,pair<int,int>> mp;
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(mp.find(nums1[i])==mp.end()){
                mp[nums1[i]].first=0;
                mp[nums1[i]].second=0;
            }
            mp[nums1[i]].second++;

        }
        for(int i=0;i<m;i++){
            
            if(mp.find(nums2[i])==mp.end()){
                mp[nums2[i]].first=0;
                mp[nums2[i]].second=0;
            }
            
            
            mp[nums2[i]].first++;
            
        }



        for(auto it :mp){
            int t=min(it.second.first,it.second.second);
            for(int k=0;k<t;k++){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};