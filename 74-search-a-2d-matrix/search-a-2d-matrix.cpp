class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {


        // binary search on last index find the upperbound 
        // binary search on rowstart 


        int n=matrix.size();
        int m=matrix[0].size();
        int i=0;
        int j=n-1;
        while(i<j){
            int mid=i+(j-i)/2;

            if(target>matrix[mid][m-1]){
                    i=mid+1;

            }
            else {
                j=mid;
            }

        } 

         cout<<j<<endl;


        int col=j;
        i=0;
        j=m-1;

        while(i<=j){
            int mid=i+(j-i)/2;
            if(target==matrix[col][mid])return true;

            if(target>matrix[col][mid]){
                    i=mid+1;

            }
            else {
                j=mid-1;
            }

        } 

        return false;

    }
};