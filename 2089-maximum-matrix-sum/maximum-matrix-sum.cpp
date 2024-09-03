class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        // minimum neag number cnt neag 
        int n=matrix.size();
        int m=matrix[0].size();
        int cnt=0;
        long long total=0;
        int  mini=INT_MAX;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]<0){
                    cnt++;
                }

                mini=min(mini,abs(matrix[i][j]));
                total+=abs(matrix[i][j]);
            }
        }


        // cout<<mini<<endl;
        // cout<<total<<endl;
        // cout<<cnt;
        if(cnt%2==0)return total;
        return total-2*mini;
        // return total+mini?cnt%2==1:total;
    }
};