class Solution {
public:
    string minimizeStringValue(string s) {
       
        map<char,int>mp;
        for(int i=25;i>=0;i--){
        mp['a'+i]=0;           
        }
        string ans;
           
        for(int i=0;i<s.size();i++){
            if(s[i]!='?')
            mp[s[i]]++;
        }
        
        for(int i=0;i<s.size();i++){
            if(s[i]=='?'){
                    
                int mini=INT_MAX;
                char x='a';
               for(auto it :mp){
                   if(mini>it.second){
                       x=it.first;
                       mini=it.second;
                   }
                   
               }
                ans+=x;
                mp[x]++;
            }
            
           
            
            
            
        }
        
      //  cout<<ans<<endl;;
        
        
        sort(ans.begin(),ans.end());
            int j=0;
            for(int i=0;i<s.size();i++){
               if(s[i]=='?'){
                   s[i]=ans[j];
                   j++;
               } 
            }
        
        
        
        return s;
        
        
        
    }
};