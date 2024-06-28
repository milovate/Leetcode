class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
         vector<int>pr(n);
        for(int i=0;i<n;i++)
        {
            pr[i]=0;
        }
        for(int i=0;i<roads.size();i++)
        {
            pr[roads[i][0]]++;
            pr[roads[i][1]]++;
        }
        sort(pr.begin(),pr.end());
        long long int total=0;
        long long int x=n;
        for(int i=pr.size()-1;i>=0;i--)
        {
            total+=(pr[i])*x;
            x--;
        }
        return total;
    }
};