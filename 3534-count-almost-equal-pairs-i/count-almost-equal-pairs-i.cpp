class Solution {
public:


    bool check(string a,string b){
        int cnt=0;
        if(a==b)return true;
        unordered_map<char,int>mpa,mpb;
        for(int i=0;i<a.size();i++){
            mpa[a[i]]++;
            mpb[b[i]]++;
        }
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i]&&mpa==mpb)cnt++;
        }
        // cout<<a<<endl;
        // cout<<b<<" "<<cnt<<endl;
        
        return (cnt==2)?true:false;
    }



    int countPairs(vector<int>& nums) {

        int n=nums.size();
        vector<int>v(n);
        for(int i=0;i<n;i++){
            v[i]+=(100000000+nums[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(check(to_string(v[i]),to_string(v[j]))){
                    ans++;
                }
            }
        }


        return ans;
        
        
    }
};