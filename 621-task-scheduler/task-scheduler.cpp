class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>mp;

        int maxfreq=0;
        for(int i=0;i<tasks.size();i++)
        {
            mp[tasks[i]]++;
            maxfreq=max(maxfreq,mp[tasks[i]]);
        }
    
        int time=(n+1)*(maxfreq-1);
        for(auto i:mp)
        {
            if(i.second==maxfreq) time++; 
        }
        
        int t=tasks.size();
        return max(t,time);
    }
};