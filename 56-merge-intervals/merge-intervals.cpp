class Solution {
public:

   static bool customComparator(vector<int>& a,vector<int>& b) {
    if (a[0] != b[0]) {
        return a[0] < b[0];
    }
    return a[1] > b[1];
    }




    vector<vector<int>> merge(vector<vector<int>>& a) {
          int n=a.size();

    vector<vector<int>>res;
    sort(a.begin(),a.end(),customComparator);
    int start=a[0][0];
    int end=a[0][1];
    for(int i=1;i<n;i++){
            if(end>=a[i][0]){
                end=max(a[i][1],end);
            } else {
                vector<int> temp;
                temp.push_back(start);

                temp.push_back(end);
                res.push_back(temp);

                    end=a[i][1];
                    start = a[i][0];
            
            }
    }

                vector<int> temp;
                temp.push_back(start);
                temp.push_back(end);
                res.push_back(temp);


    return res;
    }
};