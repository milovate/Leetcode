class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;

        unordered_map<int,int>mp2;
        for(int i=0;i<n;i++){
            mp[nums[i]]=0;
            mp2[nums[i]]=0;
        }


        for(int i=0;i<n;i++){
            if(mp2[nums[i]]>0)continue;
            if(mp[nums[i]]==0)mp[nums[i]]++;
            mp2[nums[i]]=1;
            int temp=nums[i];
            while(1){
                if(mp.find(temp+1)==mp.end())break;
                if(mp[temp+1]!=0){
                    mp[nums[i]]+=mp[temp+1];
                    mp2[temp+1]=1;
                    // cout<<nums[i]<<endl;
                    break;
                    
                }
                else{
                
                mp[nums[i]]++;
                // mp[temp]++;
                mp2[temp+1]=1;
                temp++;
                }

            }
//             cout<<nums[i]<<endl;
//         for (auto it: mp2){
//                 cout<<it.first<<" "<<it.second<<endl;
//         }
// cout<<endl;
        }

        int a=0;

        for (auto it: mp){
                a=max(a,it.second);
        }
        return a;
        
    }
};