class Solution {
public:
    long long maximumHappinessSum(vector<int>& hap, int k) {
        sort(hap.begin(),hap.end(),greater<int>());

        long long int sum=0;
        for(int i=0;i<k;i++){
            sum+=max((hap[i]-i),0);
        }

        return max(sum,0ll);
    }
};