class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        //sort the input 
        //1 1 3 4 5
        //k=5
        int n=nums.size();
        sort(nums.begin(),nums.end());
        //calculate freq
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(i > 0 && nums[i] == nums[i-1])   // to avoid duplicate ans
                continue;
            int key=nums[i]+k;
            int p=0;
            int q=n-1;
            while(p<=q){
                int mid=p+(q-p)/2;
                if(nums[mid]==key && mid!=i){
                    // if(nums[i]!=nums[mid]){

                    //     ans+=mp[nums[i]];}
                    // else ans+=(mp[nums[i]]-1); unique index
                    ans++;
                    break;
                }
                else if(nums[mid]>key){
                        q=mid-1;
                }
                else {
                    p=mid+1;
                }


            }
        }

        return ans;

    }
};