#define ll long long
class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& q) {
        
        int n=nums.size();
        int m=q.size();
        multiset<pair<ll,ll>>ms;
        vector<ll> res;
        ll tot=0;
        map<int,int> indmp;
        for(int i=0;i<n;i++){
            indmp[i]=0;
            ms.insert({nums[i],i});
            tot+=nums[i];
        }
        
        ll ans=0;
        int marked=0;
       ll markedsum=0;
        
        
        for(int i=0;i<m;i++){
            
            int index=q[i][0];
            int k=q[i][1];
            
            if( indmp[index]!=1){
            markedsum+=nums[index];
            indmp[index]=1;
            marked++;
            ms.erase({nums[index],index});}
            
            int brk=0;
            
            
            for (auto it = ms.begin(); it != ms.end(); it++){
                if(brk==k)break;
                pair<ll,ll> ms_element=*it;               
                if(indmp[ms_element.second]==1)continue;
                brk++;
                indmp[ms_element.second]=1;
                markedsum+=ms_element.first;
               // cout<<ms_element.first<<" "<<ms_element.second<<"  /  "<<markedsum<<endl; 

                ms.erase(it);
                marked++;
                indmp[ms_element.second]=1;
                
       
                
                
            } 
            
            ans=tot-markedsum;
            
            
            res.push_back(ans);
            
            
        }
        
        return res;
        
    }
};