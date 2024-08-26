class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {

        int n = points.size();
        if(n==1)return 1;
        sort(points.begin(),points.end());
    
        int cnt=1;
        int x=points[0][0];
        int y=points[0][1];

        for(int i=1;i<n;i++){
            if(points[i][0]<=y){
                x=max(x,points[i][0]);
                y=min(y,points[i][1]);
            }
            else{
                cnt++;
                x=points[i][0];
                y=points[i][1];
            }

            // cout<<x<<" "<<y<<endl;
        }

        return cnt;

        
    }
};