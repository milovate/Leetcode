class Solution {
public:
    int findTheLongestSubstring(string s) {
        // using the bit map and hash map we can solve this problem simply
        unordered_map<int,pair<int,int>>Mpp;
        int XOR=0;
        Mpp[0].first=-1;
        Mpp[0].second=0;
        int maxSubLen=0;
        for(int i=0;i<s.size();i++){
            int val=0;
            if(s[i]=='a'){
                val=(1<<0);
            }
            else if(s[i]=='e'){
                val=(1<<1);
            }
            else if(s[i]=='i'){
                val=(1<<2);
            }
            else if(s[i]=='o'){
                val=(1<<3);
            }
            else if(s[i]=='u'){
                val=(1<<4);
            }
            else{
                val=0;
            }
            XOR=XOR^val;
            if(Mpp.find(XOR)!=Mpp.end()){
                int idx=Mpp[XOR].first;
                Mpp[XOR].first=i;
                Mpp[XOR].second=Mpp[XOR].second+(i-idx);
            }
            else{
                Mpp[XOR].first=i;
                Mpp[XOR].second=0;
            }
            maxSubLen=max(maxSubLen,Mpp[XOR].second);
        }
        return maxSubLen;
    }
};