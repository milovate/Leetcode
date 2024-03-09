class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        

        int i=0;
        int j=0;
        cout<<nums2.size()<<endl;
        while(i<nums1.size() && j<nums2.size()){
            cout<<i<<" "<<j<<endl;
            if(nums1[i]==nums2[j]) return nums1[i];

            if(nums1[i]>nums2[j])j++;

             else if(nums1[i]<nums2[j])i++;

        }

        // if(i==nums1.size()){
        //         whi
        // }


        // if(j==nums2.size()){
            
        // }

        return -1;




    }
};