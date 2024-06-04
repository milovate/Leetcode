class Solution {
public:
    int longestPalindrome(string s) {
      //if eve one is odd add 1 to final answer 
      // freqency iff odd bool =true , freq-1 is added 
      unordered_map<char,int> mp;
      for(int i=0;i<s.size();i++){
        mp[s[i]]++;
      }
      bool flg=false;
      int ans=0;
      for(auto it:mp){
        if(it.second%2!=0){
            flg=true;
            ans+=it.second-1;
        }
        else ans+=it.second;

      }

if(flg)return ans+1;      
return ans;
    }
};