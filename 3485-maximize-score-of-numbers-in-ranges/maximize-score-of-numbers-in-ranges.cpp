class Solution {
public:

    bool check(const vector<int>& start, int d, int mid){
        long long  prev=start[0];
        for(int i=1 ; i<start.size(); i++){
            long long int next=max(prev+mid, static_cast<long long>(start[i]));
            if (next > start[i] + d) { 
                return false;
            }
            prev=next;
        }
        return true;
    }
    int maxPossibleScore(vector<int>& start, int d) {
        int n=start.size();
        sort(start.begin(), start.end());
        long long low=0, hi=start.back() - start.front() + d;
        
        long long ans=0;
        while(low<=hi){
            long long mid=(low+hi)/2;
            if(check(start, d, mid)){
                ans=mid;
                low=mid+1;
            }else{
                hi=mid-1;
            }
        }

        return ans;
    }
};