class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& cap) {
        sort(cap.begin(),cap.end(),greater<int>());
        int total_apple=0;
        for(int i=0;i<apple.size();i++){
            total_apple+=apple[i];
        }
        int intersum=0;
        for(int i=0;i<cap.size();i++){
            if(intersum>=total_apple)return i;
            intersum+=cap[i];
        }
        return cap.size();
    }
};