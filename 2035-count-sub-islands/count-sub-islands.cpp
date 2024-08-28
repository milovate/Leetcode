class Solution {
public:

    void dfs(int row,int col,int cnt,vector<vector<int>>&grid1,vector<vector<int>>&vis1){
        vis1[row][col]=cnt;
        
        int n=grid1.size();
        int m=grid1[0].size();

        int dx[] ={0,0,-1,1};
        int dy[] ={1,-1,0,0};

        for(int i=0;i<4;i++){
            int nrow=row+dx[i];
            int ncol=col+dy[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid1[nrow][ncol]==1&&vis1[nrow][ncol]==-1){
                dfs(nrow,ncol,cnt,grid1,vis1);
            }


        }
        
    }



    void dfs1(bool& flg, int row,int col,int cnt,vector<vector<int>>&grid2,vector<vector<int>>&vis2,vector<vector<int>>&vis1){
        vis2[row][col]=1;

        if(vis1[row][col]!=cnt){
                flg=true;
        }
        
        int n=grid2.size();
        int m=grid2[0].size();

        int dx[] ={0,0,-1,1};
        int dy[] ={1,-1,0,0};
        
        for(int i=0;i<4;i++){
            int nrow=row+dx[i];
            int ncol=col+dy[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
            if(grid2[nrow][ncol]==1 && vis2[nrow][ncol]==-1){
               dfs1(flg,nrow,ncol,cnt,grid2,vis2,vis1);
            }
            
            }

        }
        
    }




    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n=grid1.size();
        int m=grid1[0].size();

        vector<vector<int>>vis1(n,vector<int>(m,-1));
        vector<vector<int>>vis2(n,vector<int>(m,-1));
        
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid1[i][j]==1&&vis1[i][j]==-1){
                dfs(i,j,cnt,grid1,vis1);
                cnt++;}
            }
        }

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<vis1[i][j]<<" ";
        //     }cout<<endl;
        // }


        int ans=0;
        bool flg=false;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid2[i][j]==1 && vis2[i][j]==-1){

                    flg=false;
                    if(vis1[i][j]==-1)continue;
                    dfs1(flg,i,j,vis1[i][j],grid2,vis2,vis1);
                     if(!flg){

                    // cout<<i<<j<<endl;
                    // cout<<endl;
                     
                     ans++;}
                
                }
            }
        }

        // cout<<endl;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<vis2[i][j]<<" ";
        //     }cout<<endl;
        // }



return ans;


    }
};