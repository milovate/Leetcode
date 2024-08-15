
#define pp pair<int,pair<int,int>>

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
 vector<vector<int>> res;
 int n1=nums1.size();
 int n2=nums2.size();

priority_queue<pp,vector<pp>,greater<pp>> pq;


 for(int i=0;i<k&&i<n1;i++){
pq.push({nums1[i]+nums2[0],{i,0}});
 }


while(k>0 && !pq.empty()){
    auto curr=pq.top();
    pq.pop();

    int i=curr.second.first;
    int j=curr.second.second;

res.push_back({nums1[i],nums2[j]});

if(j<n2-1){

    pq.push({nums1[i]+nums2[j+1],{i,j+1}});
    
    }


k--;



}
        return res;
        
    }
};