class Solution {
public:
    long long minimumSteps(string s) {
        long long ans = 0LL;
        int ones = 0; // count number of ones encountered so far
        for(int i = 0;i<s.length();i++){
            if(s[i]=='1')   
                ones++;
            else 
// if current element is zero, we need to apply opeartions equal to the number of ones occuring before it
                ans+=ones;
        }
        return ans;
    }
};