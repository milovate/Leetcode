class Solution {
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        int res=0;
        for(int i=0;i<n;i++){
            
            string s=to_string(nums[i]);
            char x='0';
            for(int j=0;j<s.size();j++){
                x=max(x,s[j]);
            }
            string newl;
            for(int j=0;j<s.size();j++){
                newl+=x;
            }
            //cout<<newl<<" "<<endl;
            ans=stoi(newl);
            res+=ans;
          
            
        }
        return res;
            
    }
};